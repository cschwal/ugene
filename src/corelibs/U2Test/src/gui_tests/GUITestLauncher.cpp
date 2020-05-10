/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2020 UniPro <ugene@unipro.ru>
 * http://ugene.net
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

#include "GUITestLauncher.h"
#include <system/GTFile.h>

#include <QApplication>
#include <QDesktopWidget>
#include <QDir>
#include <QMap>
#include <QTextStream>

#include <U2Core/AppContext.h>
#include <U2Core/CMDLineCoreOptions.h>
#include <U2Core/CmdlineTaskRunner.h>
#include <U2Core/ExternalToolRegistry.h>
#include <U2Core/Timer.h>
#include <U2Core/U2SafePoints.h>

#include "GUITestTeamcityLogger.h"
#include "UGUITestBase.h"

#define TIMEOUT 480000

#ifdef Q_OS_MAC
#    define NUMBER_OF_TESTS_IN_SUITE 750
#elif defined(Q_OS_UNIX)
#    define NUMBER_OF_TESTS_IN_SUITE 550
#elif defined(Q_OS_WIN)
#    define NUMBER_OF_TESTS_IN_SUITE 850
#endif

#define GUITESTING_REPORT_PREFIX "GUITesting"

namespace U2 {

GUITestLauncher::GUITestLauncher(int _suiteNumber, bool _noIgnored, QString _iniFileTemplate)
    : Task("gui_test_launcher", TaskFlags(TaskFlag_ReportingIsSupported) | TaskFlag_ReportingIsEnabled),
      suiteNumber(_suiteNumber), noIgnored(_noIgnored), pathToSuite(""), iniFileTemplate(_iniFileTemplate) {
    tpm = Task::Progress_Manual;
    testOutDir = getTestOutDir();

    QWidget *splashScreen = QApplication::activeWindow();
    if (splashScreen != nullptr) {
        splashScreen->hide();
    }
}

GUITestLauncher::GUITestLauncher(QString _pathToSuite, bool _noIgnored, QString _iniFileTemplate)
    : Task("gui_test_launcher", TaskFlags(TaskFlag_ReportingIsSupported) | TaskFlag_ReportingIsEnabled),
      suiteNumber(0), noIgnored(_noIgnored), pathToSuite(_pathToSuite), iniFileTemplate(_iniFileTemplate) {
    tpm = Task::Progress_Manual;
    testOutDir = getTestOutDir();
}

bool GUITestLauncher::renameTestLog(const QString &testName) {
    QString outFileName = testOutFile(testName);
    QString outFilePath = testOutDir + QString("/logs/");

    QFile outLog(outFilePath + outFileName);
    return outLog.rename(outFilePath + "failed_" + outFileName);
}

void GUITestLauncher::run() {
    if (!initGUITestBase()) {
        return;
    }

    int finishedCount = 0;
    foreach (HI::GUITest *test, tests) {
        if (isCanceled()) {
            return;
        }
        if (test == nullptr) {
            updateProgress(finishedCount++);
            continue;
        }
        QString testName = test->getFullName();
        QString testNameForTeamCity = test->getSuite() + "_" + test->getName();
        results[testName] = "";

        firstTestRunCheck(testName);

        if (!test->isIgnored()) {
            qint64 startTime = GTimer::currentTimeMicros();
            GUITestTeamcityLogger::testStarted(testNameForTeamCity);

            QString testResult = runTest(testName);
            results[testName] = testResult;
            if (GUITestTeamcityLogger::testFailed(testResult)) {
                renameTestLog(testName);
            }

            qint64 finishTime = GTimer::currentTimeMicros();
            GUITestTeamcityLogger::teamCityLogResult(testNameForTeamCity, testResult, GTimer::millisBetween(startTime, finishTime));
        } else if (test->getReason() == HI::GUITest::Bug) {
            GUITestTeamcityLogger::testIgnored(testNameForTeamCity, test->getIgnoreMessage());
        }

        updateProgress(finishedCount++);
    }
}

void GUITestLauncher::firstTestRunCheck(const QString &testName) {
    QString testResult = results[testName];
    Q_ASSERT(testResult.isEmpty());
}

bool GUITestLauncher::initGUITestBase() {
    UGUITestBase *b = AppContext::getGUITestBase();
    SAFE_POINT(b != nullptr, "Test base is NULL", false);
    QString label = qgetenv("UGENE_GUI_TEST_LABEL");
    QList<HI::GUITest *> allTestList = b->getTests(UGUITestBase::Normal, label);
    if (allTestList.isEmpty()) {
        setError(tr("No tests to run"));
        return false;
    }

    QList<QList<HI::GUITest *>> suiteList;
    if (suiteNumber) {
        for (int i = 0; i < (allTestList.length() / NUMBER_OF_TESTS_IN_SUITE + 1); i++) {
            suiteList << allTestList.mid(i * NUMBER_OF_TESTS_IN_SUITE, NUMBER_OF_TESTS_IN_SUITE);
        }
        if (suiteNumber < 0 || suiteNumber > suiteList.size()) {
            setError(tr("Invalid suite number: %1. There are %2 suites").arg(suiteNumber).arg(suiteList.size()));
            return false;
        }
        tests = suiteList.takeAt(suiteNumber - 1);
    } else if (!pathToSuite.isEmpty()) {
        QString absPath = QDir().absoluteFilePath(pathToSuite);
        QFile suite(absPath);
        SAFE_POINT(suite.exists(), "file " + absPath + " does not exists", false);
        if (suite.open(QFile::ReadOnly)) {
            char buf[1024];
            while (suite.readLine(buf, sizeof(buf)) != -1) {
                QString testName = QString(buf).remove('\n').remove('\t').remove(' ');
                if (testName.startsWith("#")) {
                    continue;    // comment line
                }
                bool added = false;
                foreach (HI::GUITest *test, allTestList) {
                    QString fullTestName = test->getFullName();
                    QString fullTestNameInTeamcityFormat = fullTestName.replace(':', '_');
                    if (fullTestName == testName || fullTestNameInTeamcityFormat == testName) {
                        tests << test;
                        added = true;
                        break;
                    }
                }
                SAFE_POINT(added, "test " + testName + " not found", false)
            }
        } else {
            SAFE_POINT(0, "can not open file " + absPath, false);
        }
    } else {
        tests = allTestList;
    }

    if (noIgnored) {
        foreach (HI::GUITest *test, tests) {
            test->setIgnored(false);
        }
    }
    return true;
}

void GUITestLauncher::updateProgress(int finishedCount) {
    int testsSize = tests.size();
    if (testsSize) {
        stateInfo.progress = finishedCount * 100 / testsSize;
    }
}

QString GUITestLauncher::testOutFile(const QString &testName) {
    return QString("ugene_" + testName + ".out").replace(':', '_');
}

QString GUITestLauncher::getTestOutDir() {
    QString date = QDate::currentDate().toString("dd.MM.yyyy");
    QString guiTestOutputDirectory = qgetenv("GUI_TESTING_OUTPUT");
    QString initPath;
    if (guiTestOutputDirectory.isEmpty()) {
        initPath = QDir::homePath() + "/gui_testing_output/" + date;
    } else {
        initPath = guiTestOutputDirectory + "/gui_testing_output/" + date;
    }
    QDir d(initPath);
    int i = 1;
    while (d.exists()) {
        d = QDir(initPath + QString("_%1").arg(i));
        i++;
    }
    return d.absolutePath();
}

static bool isTestPathLogged = false;

static QString getTestDirFromEnv() {
    QString testDir = qgetenv("UGENE_TESTS_PATH");
    if (testDir.isEmpty()) {
        testDir = "../../test/";
    } else if (!testDir.endsWith("/")) {
        testDir += "/";
    }
    QFileInfo dirInfo(testDir);
    QString absolutePath = dirInfo.absoluteFilePath();
    if (!isTestPathLogged) {
        coreLog.info(QString("UGENE_TESTS_PATH for tests: '%1', absolute path: %2")
                         .arg(testDir)
                         .arg(absolutePath));
        // Perform extra check: to make the misconfiguration easier discoverable in logs.
        QFileInfo commonData(absolutePath, "_common_data");
        if (!commonData.isDir()) {
            coreLog.error("UGENE_TESTS_PATH is not a valid test dir!");
        }
        isTestPathLogged = true;
    }
#ifdef Q_OS_WIN
    // Absolute path on Windows looks like 'C:/../' and is not compatible with
    // some testing controls (like 'open file dialog').
    return testDir;
#else
    return absolutePath;
#endif
}

QProcessEnvironment GUITestLauncher::getProcessEnvironment(QString testName) {
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

    QDir().mkpath(testOutDir + "/logs");
    env.insert(ENV_UGENE_DEV, "1");
    env.insert(ENV_GUI_TEST, "1");
    env.insert(ENV_USE_NATIVE_DIALOGS, "0");
    env.insert(U2_PRINT_TO_FILE, testOutDir + "/logs/" + testOutFile(testName));

    QString iniFileName = testOutDir + "/inis/" + testName.replace(':', '_') + "_UGENE.ini";
    if (!iniFileTemplate.isEmpty() && QFile::exists(iniFileTemplate)) {
        QFile::copy(iniFileTemplate, iniFileName);
    }
    env.insert(U2_USER_INI, iniFileName);

    env.insert("UGENE_TESTS_PATH", getTestDirFromEnv());
    return env;
}

/** Helper class to backup & restore data around the test run. */
class BackupAndRestore {
public:
    /** Backups sensitive data before the test run. */
    BackupAndRestore(const QString &testDir);

    /** Performs cleanup after the test run. */
    ~BackupAndRestore();

    QString testDir;
};

BackupAndRestore::BackupAndRestore(const QString &testDir)
    : testDir(testDir) {
    // Backup files before run. FIXME: rework to use svn revert -R ?
    if (QDir(testDir).exists()) {
        coreLog.info("Running backup for files before the test run.");
        GUITestOpStatus os;
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj1.uprj");
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj2-1.uprj");
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj2.uprj");
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj3.uprj");
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj4.uprj");
        GTFile::backup(os, testDir + "_common_data/scenarios/project/proj5.uprj");

        // Files from the projects above.
        GTFile::backup(os, testDir + "_common_data/scenarios/project/1.gb");
        coreLog.info("Backup is finished");
    }
}

BackupAndRestore::~BackupAndRestore() {
    // Restore saved files
    if (QDir(testDir).exists()) {
        coreLog.info("Running restore for files after the test run.");
        GUITestOpStatus os;
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj1.uprj");
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj2-1.uprj");
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj2.uprj");
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj3.uprj");
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj4.uprj");
        GTFile::restore(os, testDir + "_common_data/scenarios/project/proj5.uprj");

        // Files from the projects above.
        GTFile::restore(os, testDir + "_common_data/scenarios/project/1.gb");
        coreLog.info("Restore is finished.");
    }
}

QString GUITestLauncher::runTest(const QString &testName) {
    QString path = QCoreApplication::applicationFilePath();
    QProcessEnvironment environment = getProcessEnvironment(testName);
    QStringList arguments = getTestProcessArguments(testName);

    QString testDir = environment.value("UGENE_TESTS_PATH");
    BackupAndRestore backupAndRestore(testDir);

    // ~QProcess is killing the process, will not return until the process is terminated.
    coreLog.info(QString("Starting a new process for test %1").arg(testName));
    QProcess process;
    process.setProcessEnvironment(environment);
    process.start(path, arguments);
    qint64 processId = process.processId();

    QProcess screenRecorder;
    if (qgetenv("UGENE_SKIP_TEST_RECORDING").toInt() != 1) {
        screenRecorder.start(getScreenRecorderString(testName));
    }

    bool started = process.waitForStarted();
    if (!started) {
        return tr("An error occurred while starting UGENE: ") + process.errorString();
    }
    bool finished = process.waitForFinished(TIMEOUT);
    QProcess::ExitStatus exitStatus = process.exitStatus();

    coreLog.info(QString("The process for test %1 is finished with status: %2")
                     .arg(testName)
                     .arg(exitStatus));

    if (!finished || exitStatus != QProcess::NormalExit) {
        CmdlineTaskRunner::killChildrenProcesses(processId);
    }

#ifdef Q_OS_WIN
    QProcess::execute("closeErrorReport.exe");    //this exe file, compiled Autoit script
#endif

    QString testResult = readTestResult(process.readAllStandardOutput());

    if (qgetenv("UGENE_SKIP_TEST_RECORDING").toInt() != 1) {
        screenRecorder.close();
        screenRecorder.waitForFinished(2000);
        if (!GUITestTeamcityLogger::testFailed(testResult)) {
            QFile(getVideoPath(testName)).remove();
        }
    }

    if (finished && (exitStatus == QProcess::NormalExit)) {
        return testResult;
    }
#ifdef Q_OS_WIN
    CmdlineTaskRunner::killProcessTree(process.processId());
#endif
    if (finished) {
        return tr("An error occurred while finishing UGENE: ") + process.errorString() + '\n' + testResult;
    } else {
        return tr("Test fails because of timeout.");
    }
}

QStringList GUITestLauncher::getTestProcessArguments(const QString &testName) {
    return QStringList() << QString("--") + CMDLineCoreOptions::LAUNCH_GUI_TEST + "=" + testName;
}

QString GUITestLauncher::readTestResult(const QByteArray &output) {
    QString msg;
    QTextStream stream(output, QIODevice::ReadOnly);

    while (!stream.atEnd()) {
        QString str = stream.readLine();

        if (str.contains(GUITESTING_REPORT_PREFIX)) {
            msg = str.remove(0, str.indexOf(':') + 1);
            if (!msg.isEmpty()) {
                break;
            }
        }
    }

    return msg;
}

QString GUITestLauncher::generateReport() const {
    QString res;
    res += "<table width=\"100%\">";
    res += QString("<tr><th>%1</th><th>%2</th></tr>").arg(tr("Test name")).arg(tr("Status"));

    QMap<QString, QString>::const_iterator i;
    for (i = results.begin(); i != results.end(); ++i) {
        QString color = "green";
        if (GUITestTeamcityLogger::testFailed(i.value())) {
            color = "red";
        }
        res += QString("<tr><th><font color='%3'>%1</font></th><th><font color='%3'>%2</font></th></tr>").arg(i.key()).arg(i.value()).arg(color);
    }
    res += "</table>";

    return res;
}

QString GUITestLauncher::getScreenRecorderString(QString testName) {
    QString result;
#ifdef Q_OS_LINUX
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    QString display = qgetenv("DISPLAY");
    result = QString("ffmpeg -video_size %1x%2 -framerate 5 -f x11grab -i %3.0 %4").arg(width).arg(height).arg(display).arg(getVideoPath(testName));
#elif defined Q_OS_MAC
    result = QString("ffmpeg -f avfoundation -r 5 -i \"1:none\" \"%1\"").arg(getVideoPath(testName));
#elif defined Q_OS_WIN
    result = QString("ffmpeg -f dshow -i video=\"UScreenCapture\" -r 5 %1").arg(getVideoPath(testName.replace(':', '_')));
#endif
    uiLog.trace("going to record video: " + result);
    return result;
}

QString GUITestLauncher::getVideoPath(const QString &testName) {
    QDir().mkpath(QDir::currentPath() + "/videos");
    QString result = QDir::currentPath() + "/videos/" + testName + ".avi";
    return result;
}
}    // namespace U2
