/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2012 UniPro <ugene@unipro.ru>
 * http://ugene.unipro.ru
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <U2Core/AppContext.h>
#include <U2Core/AppResources.h>
#include <U2Core/AppSettings.h>
#include <U2Core/U2OpStatusUtils.h>
#include <U2Core/U2SafePoints.h>

extern "C" {
#include <bam.h>
#include <bam_sort.c>
#include <sam.h>
#include <sam.c>
}

#include <QFileInfo>

#include "BAMUtils.h"

namespace U2 {

static void closeFiles(samfile_t *in, samfile_t *out) {
    if (NULL != in) {
        samclose(in);
    }

    if (NULL != out) {
        samclose(out);
    }
}

GUrl BAMUtils::convertSamToBam(const GUrl &samUrl, U2OpStatus &os) {
    QByteArray samFileName = samUrl.getURLString().toAscii();
    QByteArray bamFileName = samFileName + ".bam";

    samfile_t *in = NULL;
    samfile_t *out = NULL;

    // open files
    {
        in = samopen(samFileName.constData(), "r", NULL);
        if (NULL == in) {
            os.setError(QString("[main_samview] fail to open \"%1\" for reading").arg(samFileName.constData()));
            closeFiles(in, out);
            return QString();
        }
        if (NULL == in->header) {
            os.setError(QString("[main_samview] fail to read the header from \"%1\"").arg(samFileName.constData()));
            closeFiles(in, out);
            return QString();
        }
        out = samopen(bamFileName.constData(), "wb", in->header);
        if (NULL == out) {
            os.setError(QString("[main_samview] fail to open \"%1\" for writing").arg(bamFileName.constData()));
            closeFiles(in, out);
            return QString();
        }
    }

    // convert files
    {
        bam1_t *b = bam_init1();
        int r;
        while ((r = samread(in, b)) >= 0) { // read one alignment from `in'
            samwrite(out, b); // write the alignment to `out'
        }
        if (r < -1) {
            os.setError(QString("[main_samview] truncated file \"%1\"").arg(samFileName.constData()));
        }
        bam_destroy1(b);
    }

    closeFiles(in, out);
    return QString(bamFileName);
}

static bool isSorted(const QString &headerText) {
    QString text = headerText;
    text = text.replace('\r', QString(""));
    QStringList lines = text.split('\n');

    bool result = false;
    foreach (const QString &line, lines) {
        if (!line.startsWith("@HD")) {
            continue;
        }

        QStringList tokens = line.split('\t');
        for (int i = 1; i < tokens.size(); i++) {
            QString &token = tokens[i];
            int colonIdx = token.indexOf(':');
            if(-1 == colonIdx) {
                continue;
            }
            QString fieldTag = token.mid(0, colonIdx);
            QString fieldValue = token.mid(colonIdx + 1);

            if ("SO" == fieldTag) {
                result = ("coordinate" == fieldValue);
                break;
            }
        }
    }

    return result;
}

bool BAMUtils::isSortedBam(const GUrl &bamUrl, U2OpStatus &os) {
    const QByteArray &bamFileName = bamUrl.getURLString().toAscii();

    bamFile bamHandler = NULL;
    bam_header_t *header = NULL;
    QString error;
    bool result = false;

    bamHandler = bam_open(bamFileName.constData(), "r");
    if (NULL != bamHandler) {
        header = bam_header_read(bamHandler);
        if (NULL != header) {
            result = isSorted(header->text);
        } else {
            error = QString("Can't read header from file '%1'").arg(bamFileName.constData());
        }
    } else {
        error = QString("Can't open file '%1'").arg(bamFileName.constData());
    }

    // deallocate resources
    {
        if (NULL != header) {
            bam_header_destroy(header);
        }
        if (NULL != bamHandler) {
            bam_close(bamHandler);
        }
    }

    if (!error.isEmpty()) {
        os.setError(error);
        return false;
    }

    /**
     * There is a bug in samtools. If you sort a BAM using samtools then
     * the header tag "SO" is not changed. So, if the check above is false
     * then maybe it is not true that the file is not sorted.
     */
    if (!result) {
        result = BAMUtils::hasValidBamIndex(bamUrl);
        if (!result) {
            U2OpStatusImpl idxOs;
            BAMUtils::createBamIndex(bamUrl, idxOs);
            CHECK_OP(idxOs, false);
        }
    }

    return true;
}

inline static int bytes2MB(qint64 bytes) {
    return (int) (bytes / (1024 * 1024)) + 1;
}

inline static qint64 mB2bytes(int mb) {
    return (qint64)mb * 1024 * 1024;
}

#define INITIAL_SAMTOOLS_MEM_SIZE_MB bytes2MB(500000000)
#define SAMTOOLS_MEM_BOOST 5

GUrl BAMUtils::sortBam(const GUrl &bamUrl, U2OpStatus &os) {
    const QByteArray &bamFileName = bamUrl.getURLString().toAscii();

    QByteArray sortedFileBaseName = bamFileName + ".sorted";
    QByteArray sortedFileName = sortedFileBaseName + ".bam";

    // get memory resource
    AppSettings *appSettings = AppContext::getAppSettings();
    AppResourcePool *resPool = appSettings->getAppResourcePool();
    AppResource *memory = resPool->getResource(RESOURCE_MEMORY);
    SAFE_POINT_EXT(NULL != memory, os.setError("No memory resource"), QString());

    // calculate needed memory
    QFileInfo info(bamFileName);
    qint64 fileSizeBytes = info.size();
    CHECK_EXT(fileSizeBytes >= 0, os.setError(QString("Unknown file size: %1").arg(bamFileName.constData())), QString());

    int fileSizeMB = bytes2MB(fileSizeBytes);
    int maxMemMB = qMin(SAMTOOLS_MEM_BOOST * fileSizeMB, INITIAL_SAMTOOLS_MEM_SIZE_MB);
    while (!memory->isAvailable(maxMemMB)) {
        // reduce used memory
        maxMemMB = maxMemMB * 2 / 3;
    }

    // sort bam
    memory->acquire(maxMemMB);
    {
        coreLog.details(BAMUtils::tr("Sort bam file: \"%1\" using %2 Mb of memory. Result sorted file is: \"%3\"")
            .arg(bamFileName.constData()).arg(maxMemMB).arg(sortedFileName.constData()));
        size_t maxMemBytes = (size_t)(mB2bytes(maxMemMB)); // maxMemMB < 500 Mb, so the conversation is correct!
        bam_sort_core(0, bamFileName.constData(), sortedFileBaseName.constData(), maxMemBytes);
    }
    memory->release(maxMemMB);

    return QString(sortedFileName);
}

bool BAMUtils::hasValidBamIndex(const GUrl &bamUrl) {
    const QByteArray &bamFileName = bamUrl.getURLString().toAscii();

    bam_index_t *index = bam_index_load(bamFileName.constData());
    
    if (NULL == index) {
        return false;
    } else {
        bam_index_destroy(index);
        return true;
    }
}

void BAMUtils::createBamIndex(const GUrl &bamUrl, U2OpStatus &os) {
    const QByteArray &bamFileName = bamUrl.getURLString().toAscii();

    coreLog.details(BAMUtils::tr("Build index for bam file: \"%1\"").arg(bamFileName.constData()));

    int error = bam_index_build(bamFileName.constData());
    if (-1 == error) {
        os.setError("Can't build the index");
    }
}

} // U2
