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

#include "GTTestsProject.h"
#include "api/GTGlobals.h"
#include "api/GTKeyboardDriver.h"
#include "api/GTMouseDriver.h"
#include "api/GTMenu.h"
#include "api/GTFile.h"
#include "api/GTFileDialog.h"
#include "GTUtilsProject.h"
#include "GTUtilsDocument.h"
#include "GTUtilsLog.h"
#include "GTUtilsApp.h"
#include "GTUtilsToolTip.h"
#include "GTUtilsDialog.h"
#include "GTUtilsMdi.h"
#include "GTUtilsProjectTreeView.h"
#include "GTUtilsSequenceView.h"
#include "GTUtilsMdi.h"
#include "GTUtilsTaskTreeView.h"

#include <U2View/AnnotatedDNAViewFactory.h>
#include <U2View/MSAEditorFactory.h>

namespace U2{

namespace GUITest_common_scenarios_project{

GUI_TEST_CLASS_DEFINITION(test_0004) {
    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/project/", "proj1.uprj");
    GTGlobals::sleep(3000);
    GTUtilsApp::checkUGENETitle(os, "proj1 UGENE");
    GTUtilsDocument::checkDocument(os, "1CF7.PDB");

    GTUtilsProject::exportProject(os, testDir+"_common_data/scenarios/sandbox");
    GTGlobals::sleep(2000);
    GTUtilsProject::closeProject(os);
    GTGlobals::sleep(2000);

    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/sandbox/", "proj1.uprj");
    GTGlobals::sleep(2000);
    GTUtilsApp::checkUGENETitle(os, "proj1 UGENE");
    GTUtilsDocument::checkDocument(os, "1CF7.PDB");

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1CF7.PDB"));
    GTGlobals::sleep(2000);
    GTUtilsToolTip::checkExistingToolTip(os, "_common_data/scenarios/sandbox/1CF7.PDB");

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1CF7.PDB"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["Enter"]);

    GTUtilsDocument::checkDocument(os,
        "1CF7.PDB",
        AnnotatedDNAViewFactory::ID
    );
}

GUI_TEST_CLASS_DEFINITION(test_0005) {

    GTUtilsProject::openFiles(os, testDir+"_common_data/scenarios/project/proj1.uprj");
    GTUtilsApp::checkUGENETitle(os, "proj1 UGENE");
    GTUtilsDocument::checkDocument(os, "1CF7.PDB");

    GTUtilsProject::saveProjectAs(os,
        "proj2",
        testDir+"_common_data/scenarios/sandbox",
        "proj2"
    );

    GTUtilsProject::closeProject(os);

    GTUtilsProject::openFiles(os, testDir+"_common_data/scenarios/sandbox/proj2.uprj");
    GTUtilsApp::checkUGENETitle(os, "proj2 UGENE");
    GTUtilsDocument::checkDocument(os, "1CF7.PDB");

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1CF7.PDB"));
    GTGlobals::sleep(2000);
    GTUtilsToolTip::checkExistingToolTip(os, "samples/PDB/1CF7.PDB");
}

GUI_TEST_CLASS_DEFINITION(test_0006) {
    GTUtilsApp::checkUGENETitle(os, "UGENE");

    QMenu *m = GTMenu::showMainMenu(os, MWMENU_FILE);
    QAction *result = GTMenu::getMenuItem(os, m, ACTION_PROJECTSUPPORT__EXPORT_PROJECT);

    CHECK_SET_ERR(result == NULL, "Export menu item present in menu without any project created");
}
GUI_TEST_CLASS_DEFINITION(test_0007) {

    GTUtilsProject::openFiles(os, testDir+"_common_data/scenarios/project/proj1.uprj");
    GTUtilsApp::checkUGENETitle(os, "proj1 UGENE");
    GTUtilsDocument::checkDocument(os, "1CF7.PDB");

    GTUtilsDocument::removeDocument(os, "1CF7.PDB", GTGlobals::UseMouse);
    GTUtilsProject::checkProject(os, GTUtilsProject::Empty);
}

GUI_TEST_CLASS_DEFINITION(test_0009) {

    GTUtilsProject::openFiles(os, dataDir + "samples/CLUSTALW/ty3.aln.gz");
    GTUtilsDocument::checkDocument(os, "ty3.aln.gz", MSAEditorFactory::ID);
}

GUI_TEST_CLASS_DEFINITION(test_0010) {

    GTUtilsProject::openFiles(os, dataDir + "samples/FASTA/human_T1.fa");
    GTUtilsProjectTreeView::rename(os, "human_T1 (UCSC April 2002 chr7:115977709-117855134)", "qqq");
    CHECK_SET_ERR(GTUtilsProjectTreeView::findItem(os, "qqq") != NULL, "Item qqq not found in tree widget");
}

GUI_TEST_CLASS_DEFINITION(test_0011) {

    GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/project/1.gb");
    GTUtilsProject::exportProjectCheck(os, "project.uprj");
}

GUI_TEST_CLASS_DEFINITION(test_0012) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/project/", "1.gb");
	GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1.gb"));
	GTMouseDriver::click(os, Qt::RightButton);
	GTUtilsDialog::PopupChooser popupChooser(os, QStringList() << "Save a copy..", GTGlobals::UseMouse);
	GTUtilsDialog::preWaitForDialog(os, &popupChooser, GUIDialogWaiter::Popup);

	GTUtilsDialog::CopyToFileAsDialogFiller filler(os, testDir + "_common_data/scenarios/sandbox/", "1.gb", 
		                                           GTUtilsDialog::CopyToFileAsDialogFiller::Genbank, true, true, GTGlobals::UseMouse);
	GTUtilsDialog::preWaitForDialog(os, &filler, GUIDialogWaiter::Modal);
	GTGlobals::sleep(100);

	GTUtilsDocument::checkDocument(os, "1.gb.gz");
	GTGlobals::sleep(100);
	QString fileNames[] = {"_common_data/scenarios/project/test_0012.gb", "_common_data/scenarios/project/1.gb"};
	QString fileContent[2];

	for (int i = 0; i < 2; i++) {
		QFile file(testDir + fileNames[i]);
		if (! file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			if (! os.hasError()) {
				os.setError("Can't open file \"" + testDir + fileNames[i]);
			}
		}
		QTextStream in(&file);
		QString temp;
		temp = in.readLine();
		while (! in.atEnd()) {
			temp = in.readLine();
			fileContent[i] += temp;
		}
		file.close();
	}

	qDebug() << "file 1 = " << fileContent[0] << "file 2 = " << fileContent[1];
	if (fileContent[0] != fileContent[1] && !os.hasError() ) {
		os.setError("File is not expected file");
	}

}

GUI_TEST_CLASS_DEFINITION(test_0014) {
    GTMenu::clickMenuItem(os, GTMenu::showMainMenu(os, MWMENU_FILE),ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);
    GTUtilsDialog::RemoteDBDialogFiller filler(os, "1HTQ", 2); 
    GTUtilsDialog::waitForDialog(os, &filler);
    GTUtilsTaskTreeView::openView(os);
    GTUtilsTaskTreeView::cancelTask(os, "DownloadRemoteDocuments");
}

GUI_TEST_CLASS_DEFINITION(test_0016) {
	QDir dir(dataDir + "samples");
	dir.makeAbsolute();
	bool ok;
	if (!dir.exists(dir.absolutePath()+ "/.dir")) {
		ok = QDir::root().mkpath(dir.absolutePath() + "/.dir");
		CHECK_SET_ERR(ok, QString("Can't create TEMP_DATA_DIR : %1").arg(dir.absolutePath()));
	}

	QFile fileTarget(dir.absolutePath() + "/.dir/example.gb");
	if(!fileTarget.exists()){
		QFile fileDest(dir.absolutePath()+"/Genbank/sars.gb");
		QFile::copy(fileDest.fileName(), fileTarget.fileName());
	}
	GTUtilsProject::openFiles(os, fileTarget.fileName());
	GTGlobals::sleep(100);

	GTUtilsDialog::PopupChooser popupChooser(os, QStringList() << "Save a copy..", GTGlobals::UseMouse);
	GTUtilsDialog::CopyToFileAsDialogFiller filler(os, "", "", GTUtilsDialog::CopyToFileAsDialogFiller::Genbank, true, true, GTGlobals::UseMouse);
	GTUtilsDialog::preWaitForDialog(os, &popupChooser, GUIDialogWaiter::Popup);
	GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "example.gb"));
	GTUtilsDialog::preWaitForDialog(os, &filler, GUIDialogWaiter::Modal);
	GTMouseDriver::click(os, Qt::RightButton);
	GTGlobals::sleep(100);
	if (dir.exists(dir.absolutePath()+ "/.dir")) {
		QDir rmDir(dir.absolutePath()+ "/.dir");
		QStringList lstFiles = rmDir.entryList(QDir::Files);
		foreach (QString entry, lstFiles)
		{
			QString entryAbsPath = rmDir.absolutePath() + "/" + entry;
			QFile::remove(entryAbsPath);
		}
		ok = QDir::root().rmpath(rmDir.absolutePath());
		CHECK_SET_ERR(ok, QString("Can't remove TEMP_DATA_DIR : %1").arg(rmDir.absolutePath()));
	}
}

GUI_TEST_CLASS_DEFINITION(test_0017) {

    GTUtilsProject::openFiles(os, QList<QUrl>()
        << dataDir+"samples/Genbank/murine.gb"
        << dataDir+"samples/Genbank/sars.gb"
        << dataDir+"samples/Genbank/CVU55762.gb"
    );
    GTUtilsDocument::checkDocument(os, "murine.gb");
    GTUtilsDocument::checkDocument(os, "sars.gb");
    GTUtilsDocument::checkDocument(os, "CVU55762.gb");
}
GUI_TEST_CLASS_DEFINITION(test_0018) {

    GTUtilsProject::openFiles(os, dataDir + "samples/FASTA/human_T1.fa");
    GTUtilsProjectTreeView::rename(os, "human_T1 (UCSC April 2002 chr7:115977709-117855134)", "qqq");
    GTUtilsProjectTreeView::rename(os, "qqq", "eee");
    GTUtilsDocument::removeDocument(os, "human_T1.fa");

    GTUtilsProject::openFiles(os, dataDir + "samples/FASTA/human_T1.fa");
    CHECK_SET_ERR(GTUtilsProjectTreeView::findItem(os, "human_T1.fa") != NULL, "Item human_T1.fa not found in tree widget");
}

GUI_TEST_CLASS_DEFINITION(test_0019) {

    GTUtilsDialog::SequenceReadingModeSelectorDialogFiller dialog(os);
    GTUtilsDialog::preWaitForDialog(os, &dialog, GUIDialogWaiter::Modal);
    GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/project/multiple.fa");
    GTGlobals::sleep(1000);

    QTreeWidgetItem* se1 = GTUtilsProjectTreeView::findItem(os, "se1");
    QTreeWidgetItem* se2 = GTUtilsProjectTreeView::findItem(os, "se2");

    CHECK_SET_ERR(se1->font(0).bold(), "se1 are not marked with bold text");
    CHECK_SET_ERR(se2->font(0).bold(), "se2 are not marked with bold text");

    QWidget *w = GTWidget::findWidget(os, "render_area_se1");

    GTUtilsDialog::PopupChooser chooser(os, QStringList() << "ADV_MENU_REMOVE" << ACTION_EDIT_SELECT_SEQUENCE_FROM_VIEW);
    GTUtilsDialog::preWaitForDialog(os, &chooser, GUIDialogWaiter::Popup);
    GTMenu::showContextMenu(os, w);
    GTGlobals::sleep(1000);
    GTGlobals::sleep(1000);

    CHECK_SET_ERR(!se1->font(0).bold(), "se1 are not marked with regular text");
}

GUI_TEST_CLASS_DEFINITION(test_0020) {
    GTUtilsDialog::SequenceReadingModeSelectorDialogFiller dialog(os);
    GTUtilsDialog::preWaitForDialog(os, &dialog, GUIDialogWaiter::Modal);
    GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/project/multiple.fa");
    GTGlobals::sleep(1000);

    QTreeWidgetItem* se1 = GTUtilsProjectTreeView::findItem(os, "se1");
    GTUtilsProjectTreeView::itemActiveCheck(os, se1);

    QTreeWidgetItem* se2 = GTUtilsProjectTreeView::findItem(os, "se2");
    GTUtilsProjectTreeView::itemActiveCheck(os, se2);

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsProjectTreeView::itemActiveCheck(os, se1, false);
    GTUtilsProjectTreeView::itemActiveCheck(os, se2, false);

    GTUtilsSequenceView::openSequenceView(os, "se1");
    GTUtilsProjectTreeView::itemActiveCheck(os, se1);

    GTUtilsSequenceView::addSequenceView(os, "se2");
    GTUtilsProjectTreeView::itemActiveCheck(os, se2);
}

GUI_TEST_CLASS_DEFINITION(test_0021) {
	GTUtilsDialog::SequenceReadingModeSelectorDialogFiller dialog(os);
	GTUtilsDialog::preWaitForDialog(os, &dialog, GUIDialogWaiter::Modal);
	GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/project/multiple.fa");
	GTGlobals::sleep(1000);

	QTreeWidgetItem* item = GTUtilsProjectTreeView::findItem(os, "se1");
	QFont font = item->font(0);
	CHECK_SET_ERR(font.bold(), "se1 item font is not a bold");
	item = GTUtilsProjectTreeView::findItem(os, "se2");
	font = item->font(0);
	CHECK_SET_ERR(font.bold(), "se2 item font is not a bold");

	GTUtilsMdi::click(os, GTGlobals::Close);
	GTGlobals::sleep(1000);
	item = GTUtilsProjectTreeView::findItem(os, "se1");
	font = item->font(0);
	CHECK_SET_ERR(!font.bold(), "se1 item font is not a bold");

	GTUtilsSequenceView::openSequenceView(os, "se1");	
	item = GTUtilsProjectTreeView::findItem(os, "se1");
	font = item->font(0);
	CHECK_SET_ERR(font.bold(), "se1 item font is not a bold");

	GTUtilsSequenceView::openSequenceView(os, "se2");	
	item = GTUtilsProjectTreeView::findItem(os, "se2");
	font = item->font(0);
	CHECK_SET_ERR(font.bold(), "se2 item font is not a bold");	 
}

GUI_TEST_CLASS_DEFINITION(test_0023) {
    GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/project/1m.fa");
    GTUtilsMdi::click(os, GTGlobals::Minimize);

    QWidget* w = GTUtilsMdi::findWindow(os, "1m.fa");
    CHECK_SET_ERR(w != NULL, "Sequence view window title is not 1m.fa");
}

GUI_TEST_CLASS_DEFINITION(test_0025) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/project/", "proj4.uprj");

    GTUtilsDialog::PopupChooser popupChooser1(os, QStringList() << "action_load_selected_documents", GTGlobals::UseMouse);
    GTUtilsDialog::preWaitForDialog(os, &popupChooser1, GUIDialogWaiter::Popup);
	GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1.gb"));
    GTGlobals::sleep(1000);
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep(100);

    GTUtilsDialog::PopupChooser popupChooser2(os, QStringList() << "action_load_selected_documents", GTGlobals::UseMouse);
    GTUtilsDialog::preWaitForDialog(os, &popupChooser2, GUIDialogWaiter::Popup);
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "2.gb"));
    GTGlobals::sleep(1000);
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep(100);

	GTUtilsProject::createAnnotation(os, "<auto>", "misc_feature", "complement(1.. 20)");
	GTGlobals::sleep(2000);
	GTUtilsProject::ExitProjectSettings s;
    s.saveNoCloseButton = QMessageBox::No;
	GTUtilsProject::exitProject(os, s);
}

GUI_TEST_CLASS_DEFINITION(test_0026) {

    GTUtilsProject::openFiles(os, dataDir + "samples/Genbank/sars.gb");
    GTUtilsDocument::checkDocument(os, "sars.gb", AnnotatedDNAViewFactory::ID);
    GTUtilsDocument::removeDocument(os, "sars.gb");
}

GUI_TEST_CLASS_DEFINITION(test_0028) {
	GTLogTracer logTracer;
	GTUtilsProject::openFiles(os, dataDir + "samples/FASTA/human_T1.fa");
	QMdiSubWindow* fasta = (QMdiSubWindow*)GTUtilsMdi::findWindow(os, "human_T1 [s] human_T1 (UCSC April 2002 chr7:115977709-117855134)");

	GTUtilsProject::openFiles(os, dataDir + "samples/CLUSTALW/COI.aln");
	QWidget* coi = GTUtilsMdi::findWindow(os, "COI [m] COI");
	CHECK_SET_ERR(fasta->windowIcon().cacheKey() != coi->windowIcon().cacheKey() , "Icons must not be equals");
	GTUtilsLog::check(os, logTracer);
}

GUI_TEST_CLASS_DEFINITION(test_0030) {
    GTLogTracer logTracer;
    GTUtilsProject::openFiles(os, dataDir + "samples/FASTA/human_T1.fa");

    GTUtilsProject::CloseProjectSettings s;
    s.saveOnCloseButton = QMessageBox::Cancel;

    GTUtilsProject::closeProject(os, s);
    GTUtilsLog::check(os, logTracer);
}

}

}
