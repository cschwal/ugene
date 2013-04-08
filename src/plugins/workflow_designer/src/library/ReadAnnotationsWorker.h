/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2011 UniPro <ugene@unipro.ru>
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

#ifndef _U2_READ_ANNOTATIONS_WORKER_
#define _U2_READ_ANNOTATIONS_WORKER_

#include "GenericReadActor.h"
#include "GenericReadWorker.h"

namespace U2 {
namespace LocalWorkflow {

class ReadAnnotationsWorker : public GenericDocReader {
    Q_OBJECT
public:
    ReadAnnotationsWorker(Actor *p);
    virtual void init() ;

protected:
    virtual void onTaskFinished(Task *task);

protected:
    virtual Task * createReadTask(const QString &url, const QString &datasetName);

protected:
    bool mergeAnnotations;
}; // ReadAnnotationsWorker

class ReadAnnotationsProto : public GenericReadDocProto {
public:
    enum Mode{
        SPLIT,
        MERGE,
    };
    static const QString MODE_ATTR;

    ReadAnnotationsProto();
}; // ReadAnnotationsProto

class ReadAnnotationsWorkerFactory : public DomainFactory {
public:
    static const QString ACTOR_ID;

    ReadAnnotationsWorkerFactory() : DomainFactory(ACTOR_ID) {}
    static void init();
    virtual Worker *createWorker(Actor *a);

}; // ReadAnnotationsWorkerFactory

class ReadAnnotationsTask : public Task {
    Q_OBJECT
public:
    ReadAnnotationsTask(const QString &url, const QString &datasetName, bool mergeAnnotations);
    virtual void prepare();
    virtual void run();
    virtual void cleanup();

    QList<QVariantMap> takeResults();
    const QString & getDatasetName() const;

private:
    QString url;
    QString datasetName;
    bool mergeAnnotations;

    QList<QVariantMap> results;
};

} // LocalWorkflow
} // U2

#endif // _U2_READ_ANNOTATIONS_WORKER_
