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

#include "GTTestsMsaEditor.h"
#include "api/GTMouseDriver.h"
#include "api/GTKeyboardDriver.h"
#include "api/GTMenu.h"
#include "api/GTFileDialog.h"
#include "api/GTClipboard.h"
#include "GTUtilsMdi.h"
#include "GTUtilsMsaEditorSequenceArea.h"
#include "GTUtilsProjectTreeView.h"
#include "runnables/qt/PopupChooser.h"
#include "runnables/ugene/corelibs/U2Gui/util/PositionSelectorFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportMSA2MSADialogFiller.h"

#include <U2View/MSAEditor.h>

namespace U2 {

namespace GUITest_common_scenarios_msa_editor {

GUI_TEST_CLASS_DEFINITION(test_0001) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gapped.aln");
    GTGlobals::sleep();

    int length = GTUtilsMSAEditorSequenceArea::getLength(os);
    CHECK_SET_ERR(length == 14, "Wrong length");

    int leftOffest = GTUtilsMSAEditorSequenceArea::getLeftOffset(os);
    CHECK_SET_ERR(leftOffest == 1, "Wrong left offset");

    int rightOffest = GTUtilsMSAEditorSequenceArea::getRightOffset(os);
    CHECK_SET_ERR(rightOffest == 14, "Wrong right offset");
}

GUI_TEST_CLASS_DEFINITION(test_0001_1) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma.aln");
    GTGlobals::sleep();

    int length = GTUtilsMSAEditorSequenceArea::getLength(os);
    CHECK_SET_ERR(length == 12, "Wrong length");

    int leftOffest = GTUtilsMSAEditorSequenceArea::getLeftOffset(os);
    CHECK_SET_ERR(leftOffest == 1, "Wrong left offset");

    int rightOffest = GTUtilsMSAEditorSequenceArea::getRightOffset(os);
    CHECK_SET_ERR(rightOffest == 12, "Wrong right offset");
}

GUI_TEST_CLASS_DEFINITION(test_0001_2) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gap_col.aln");
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Maximize);
    GTGlobals::sleep();

    int length = GTUtilsMSAEditorSequenceArea::getLength(os);
    CHECK_SET_ERR(length == 14, "Wrong length");

    int leftOffest = GTUtilsMSAEditorSequenceArea::getLeftOffset(os);
    CHECK_SET_ERR(leftOffest == 1, "Wrong left offset");

    int rightOffest = GTUtilsMSAEditorSequenceArea::getRightOffset(os);
    CHECK_SET_ERR(rightOffest == 14, "Wrong right offset");
}

GUI_TEST_CLASS_DEFINITION(test_0001_3) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "revcompl.aln");
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Minimize);
    GTGlobals::sleep();

    int length = GTUtilsMSAEditorSequenceArea::getLength(os);
    CHECK_SET_ERR(length == 6, "Wrong length");

    int leftOffest = GTUtilsMSAEditorSequenceArea::getLeftOffset(os);
    CHECK_SET_ERR(leftOffest == 1, "Wrong left offset");

    int rightOffest = GTUtilsMSAEditorSequenceArea::getRightOffset(os);
    CHECK_SET_ERR(rightOffest == 6, "Wrong right offset");
}

GUI_TEST_CLASS_DEFINITION(test_0001_4) {

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "translations_nucl.aln", "*.*", GTFileDialog::Cancel);
    GTGlobals::sleep();
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "translations_nucl.aln", "*.*", GTFileDialog::Open);
    GTGlobals::sleep();

    int length = GTUtilsMSAEditorSequenceArea::getLength(os);
    CHECK_SET_ERR(length == 3, "Wrong length");

    int leftOffest = GTUtilsMSAEditorSequenceArea::getLeftOffset(os);
    CHECK_SET_ERR(leftOffest == 1, "Wrong left offset");

    int rightOffest = GTUtilsMSAEditorSequenceArea::getRightOffset(os);
    CHECK_SET_ERR(rightOffest == 3, "Wrong right offset");
}

GUI_TEST_CLASS_DEFINITION(test_0002) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gapped.aln");
    GTGlobals::sleep(1000);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    bool offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == false, "Offsets are visible");


    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == true, "Offsets are not visible");
}

GUI_TEST_CLASS_DEFINITION(test_0002_1) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma.aln");
    GTGlobals::sleep(1000);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    GTUtilsMdi::click(os, GTGlobals::Maximize);
    GTGlobals::sleep();

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    bool offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == false, "Offsets are visible");


    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == true, "Offsets are not visible");
}

GUI_TEST_CLASS_DEFINITION(test_0002_2) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gap_col.aln");
    GTGlobals::sleep(1000);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    GTUtilsMdi::click(os, GTGlobals::Maximize);
    GTGlobals::sleep();

    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();
    GTGlobals::sleep();

    bool offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == false, "Offsets are visible");


    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == true, "Offsets are not visible");
}

GUI_TEST_CLASS_DEFINITION(test_0002_3) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "revcompl.aln");
    GTGlobals::sleep(1000);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    QWidget *mdiWindow = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(mdiWindow != NULL, "MDI window == NULL");
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();
    GTGlobals::sleep();

    bool offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == false, "Offsets are visible");

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTGlobals::sleep();

    mdiWindow = GTUtilsMdi::activeWindow(os, false);
    CHECK_SET_ERR(mdiWindow == NULL, "There is an MDI window");

    QPoint p = GTUtilsProjectTreeView::getItemCenter(os, "revcompl");
    GTMouseDriver::moveTo(os, p);
    GTMouseDriver::doubleClick(os);
    GTGlobals::sleep();

    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();
    GTGlobals::sleep();

    offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == true, "Offsets are not visible");
}

GUI_TEST_CLASS_DEFINITION(test_0002_4) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "revcompl.aln");
    GTGlobals::sleep(1000);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    bool offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == false, "Offsets are visible");

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTGlobals::sleep();

    QPoint p = GTUtilsProjectTreeView::getItemCenter(os, "revcompl");
    GTMouseDriver::moveTo(os, p);
    GTMouseDriver::doubleClick(os);
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Maximize);
    GTGlobals::sleep();

    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    offsetsVisible = GTUtilsMSAEditorSequenceArea::offsetsVisible(os);
    CHECK_SET_ERR(offsetsVisible == true, "Offsets are not visible");
}

GUI_TEST_CLASS_DEFINITION(test_0003) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gapped.aln");
    GTGlobals::sleep();

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os);
}

GUI_TEST_CLASS_DEFINITION(test_0003_1) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gapped.aln");
    GTGlobals::sleep();

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os);
}

GUI_TEST_CLASS_DEFINITION(test_0003_2) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "revcompl.aln");
    GTGlobals::sleep();

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();

    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os);
}

GUI_TEST_CLASS_DEFINITION(test_0003_3) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gap_col.aln");
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os, false);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    Runnable *chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "show_offsets");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Maximize);
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os);
}

GUI_TEST_CLASS_DEFINITION(test_0003_4) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma.aln");
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os, false);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_VIEW << "action_sort_by_name");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTGlobals::sleep();

    QWidget* mdiWindow = GTUtilsMdi::activeWindow(os, false);
    CHECK_SET_ERR(mdiWindow == NULL, "There is an MDI window");

    QPoint p = GTUtilsProjectTreeView::getItemCenter(os, "ma");
    GTMouseDriver::moveTo(os, p);
    GTMouseDriver::doubleClick(os);
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSorted(os);
}

GUI_TEST_CLASS_DEFINITION(test_0004)
{
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/" , "ma2_gapped.aln");
    GTGlobals::sleep(1000);

    QWidget *mdiWindow = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(mdiWindow != NULL, "MDI window == NULL");

    Runnable *chooser = new PopupChooser(os, QStringList() << "action_go_to_position");
    Runnable *filler = new GoToDialogFiller(os, 6);
    GTUtilsDialog::waitForDialog(os, filler);
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);

    GTMenu::showContextMenu(os, mdiWindow);
    GTGlobals::sleep();
    GTGlobals::sleep();

    QRect expectedRect(5, 0, 1, 1);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, expectedRect);

    Runnable *filler1 = new GoToDialogFiller(os, 6);
    GTUtilsDialog::waitForDialog(os, filler1);
    GTKeyboardDriver::keyClick(os, 'g', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, expectedRect);
}

GUI_TEST_CLASS_DEFINITION(test_0010) {

// 1. Open file _common_data\scenarios\msa\translations_nucl.aln
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "translations_nucl.aln");

// 2. Do document context menu {Export->Export aligniment to amino format}
// 3. Translate with default settings
    QWidget* activeMDI = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(activeMDI != NULL, "there is no active MDI window");

    Runnable *filler = new ExportMSA2MSADialogFiller(os);
    GTUtilsDialog::waitForDialog(os, filler, GUIDialogWaiter::Modal);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_EXPORT << "amino_translation_of_alignment_rows");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTWidget::click(os, activeMDI, Qt::RightButton);
    GTGlobals::sleep();

    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::selectArea(os);
// copy to clipboard
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

// Expected state: every sequense name the same as it amino translation
    QString clipboardText = GTClipboard::text(os);
    QString expectedMSA = "L\nS\nD\nS\nP\nK";

    CHECK_SET_ERR(clipboardText == expectedMSA, "Clipboard string and expected MSA string differs");

    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_0010_1) {

// 1. Open file _common_data\scenarios\msa\translations_nucl.aln
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "translations_nucl.aln");

// 2. Do document context menu {Export->Export aligniment to amino format}
// 3. Translate with default settings
    QWidget* activeMDI = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(activeMDI != NULL, "there is no active MDI window");

    Runnable *filler = new ExportMSA2MSADialogFiller(os);
    GTUtilsDialog::waitForDialog(os, filler, GUIDialogWaiter::Modal);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_EXPORT << "amino_translation_of_alignment_rows");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTWidget::click(os, activeMDI, Qt::RightButton);
    GTGlobals::sleep();

    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::selectArea(os);
// copy to clipboard
    Runnable* chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_COPY << "copy_selection");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep();

// Expected state: every sequense name the same as it amino translation
    QString clipboardText = GTClipboard::text(os);
    QString expectedMSA = "L\nS\nD\nS\nP\nK";

    CHECK_SET_ERR(clipboardText == expectedMSA, "Clipboard string and expected MSA string differs");

    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_0010_2) {

// 1. Open file _common_data\scenarios\msa\translations_nucl.aln
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "translations_nucl.aln");

// 2. Do document context menu {Export->Export aligniment to amino format}
// 3. Translate with default settings
    QWidget* activeMDI = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(activeMDI != NULL, "there is no active MDI window");

    Runnable *filler = new ExportMSA2MSADialogFiller(os);
    GTUtilsDialog::waitForDialog(os, filler, GUIDialogWaiter::Modal);

    Runnable *chooser = new PopupChooser(os, QStringList() << MSAE_MENU_EXPORT << "amino_translation_of_alignment_rows");
    GTUtilsDialog::waitForDialog(os, chooser, GUIDialogWaiter::Popup);
    GTWidget::click(os, activeMDI, Qt::RightButton);
    GTGlobals::sleep();

    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::selectArea(os);
// copy to clipboard
    Runnable* chooser2 = new PopupChooser(os, QStringList() << MSAE_MENU_COPY << "copy_selection");
    GTUtilsDialog::waitForDialog(os, chooser2, GUIDialogWaiter::Popup);
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep();

// Expected state: every sequense name the same as it amino translation
    QString clipboardText = GTClipboard::text(os);
    QString expectedMSA = "L\nS\nD\nS\nP\nK";
    CHECK_SET_ERR(clipboardText == expectedMSA, "Clipboard string and expected MSA string differs");

    QStringList nameList = GTUtilsMSAEditorSequenceArea::getNameList(os);
    QStringList expectedNameList = QStringList() << "L" << "S" << "D" << "S" << "P" << "K";

    CHECK_SET_ERR(nameList == expectedNameList, "name lists differ");

    GTGlobals::sleep();
}

} // namespace GUITest_common_scenarios_msa_editor
} // namespace U2
