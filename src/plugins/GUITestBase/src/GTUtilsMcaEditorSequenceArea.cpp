/**
* UGENE - Integrated Bioinformatics Tools.
* Copyright (C) 2008-2017 UniPro <ugene@unipro.ru>
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

#include <QMainWindow>
#include <QStyleOptionSlider>

#include <drivers/GTMouseDriver.h>

#include <U2Core/AppContext.h>
#include <U2Core/DNASequenceObject.h>
#include <U2Core/DNASequenceSelection.h>
#include <U2Core/U2OpStatusUtils.h>

#include <U2View/ADVSingleSequenceWidget.h>
#include <U2View/BaseWidthController.h>
#include <U2View/DrawHelper.h>
#include <U2View/McaEditor.h>
#include <U2View/McaEditorNameList.h>
#include <U2View/McaEditorSequenceArea.h>
#include <U2View/McaEditorConsensusArea.h>

#include <U2View/McaEditorWgt.h>
#include <U2View/PanView.h>
#include <U2View/RowHeightController.h>
#include <U2View/SequenceObjectContext.h>

#include "GTUtilsMcaEditor.h"
#include "GTUtilsMcaEditorSequenceArea.h"
#include "GTUtilsMdi.h"

namespace U2 {
using namespace HI;

#define GT_CLASS_NAME "GTUtilsMcaEditorSequenceArea"

#define GT_METHOD_NAME "getSequenceArea"
McaEditorSequenceArea* GTUtilsMcaEditorSequenceArea::getSequenceArea(GUITestOpStatus &os) {
    QWidget *activeWindow = GTUtilsMdi::activeWindow(os);
    CHECK_OP(os, NULL);

    McaEditorSequenceArea *result = qobject_cast<McaEditorSequenceArea*>(GTWidget::findWidget(os, "mca_editor_sequence_area", activeWindow));
    GT_CHECK_RESULT(NULL != result, "MsaEditorSequenceArea is not found", NULL);
    return result;
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "getVisibleNames"
QStringList GTUtilsMcaEditorSequenceArea::getVisibleNames(GUITestOpStatus &os) {
    Q_UNUSED(os);
    QMainWindow* mw = AppContext::getMainWindow()->getQMainWindow();
    McaEditor* editor = mw->findChild<McaEditor*>();
    CHECK_SET_ERR_RESULT(editor != NULL, "McaEditor not found", QStringList());

    McaEditorNameList *nameListArea = GTUtilsMcaEditor::getNameListArea(os);
    CHECK_SET_ERR_RESULT(NULL != nameListArea, "Mca Editor name list area is NULL", QStringList());

    const QList<int> visibleRowsIndexes = editor->getUI()->getDrawHelper()->getVisibleRowsIndexes(nameListArea->height());

    QStringList visibleRowNames;
    foreach(const int rowIndex, visibleRowsIndexes) {
        visibleRowNames << editor->getMaObject()->getRow(rowIndex)->getName();
    }
    return visibleRowNames;
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "getRowHeight"
int GTUtilsMcaEditorSequenceArea::getRowHeight(GUITestOpStatus &os, int rowNumber) {
    QWidget* activeWindow = GTUtilsMdi::activeWindow(os);
    GT_CHECK_RESULT(activeWindow != NULL, "active mdi window is NULL", 0);
    McaEditorWgt* ui = GTUtilsMdi::activeWindow(os)->findChild<McaEditorWgt*>();
    return ui->getRowHeightController()->getRowHeightByNumber(rowNumber);
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "clickToPosition"
void GTUtilsMcaEditorSequenceArea::clickToPosition(GUITestOpStatus &os, const QPoint &globalMaPosition) {
    McaEditorSequenceArea *mcaSeqArea = GTWidget::findExactWidget<McaEditorSequenceArea *>(os, "mca_editor_sequence_area", GTUtilsMdi::activeWindow(os));
    GT_CHECK(NULL != mcaSeqArea, "MCA Editor sequence area is not found");
    GT_CHECK(mcaSeqArea->isInRange(globalMaPosition), "Position is out of range");

    scrollToPosition(os, globalMaPosition);
    const QPoint positionCenter(mcaSeqArea->getEditor()->getUI()->getBaseWidthController()->getBaseScreenCenter(globalMaPosition.x()),
        mcaSeqArea->getEditor()->getUI()->getRowHeightController()->getRowScreenRangeByNumber(globalMaPosition.y()).center());
    GT_CHECK(mcaSeqArea->rect().contains(positionCenter, false), "Position is not visible");

    GTMouseDriver::moveTo(mcaSeqArea->mapToGlobal(positionCenter));
    GTMouseDriver::click();
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "scrollToPosition"
void GTUtilsMcaEditorSequenceArea::scrollToPosition(GUITestOpStatus &os, const QPoint &position) {
    McaEditorSequenceArea *mcaSeqArea = GTWidget::findExactWidget<McaEditorSequenceArea *>(os, "mca_editor_sequence_area", GTUtilsMdi::activeWindow(os));
    GT_CHECK(NULL != mcaSeqArea, "MSA Editor sequence area is not found");
    GT_CHECK(mcaSeqArea->isInRange(position), "Position is out of range");

    // scroll down
    GScrollBar* vBar = GTWidget::findExactWidget<GScrollBar *>(os, "vertical_sequence_scroll", GTUtilsMdi::activeWindow(os));
    GT_CHECK(NULL != vBar, "Vertical scroll bar is not found");

    QStyleOptionSlider vScrollBarOptions;
    vScrollBarOptions.initFrom(vBar);

    while (!mcaSeqArea->isRowVisible(position.y(), false)) {
        const QRect sliderSpaceRect = vBar->style()->subControlRect(QStyle::CC_ScrollBar, &vScrollBarOptions, QStyle::SC_ScrollBarGroove, vBar);
        const QPoint bottomEdge(sliderSpaceRect.width() / 2, sliderSpaceRect.y() + sliderSpaceRect.height());

        GTMouseDriver::moveTo(vBar->mapToGlobal(bottomEdge) - QPoint(0, 1));
        GTMouseDriver::click();
    }

    // scroll right
    GScrollBar* hBar = GTWidget::findExactWidget<GScrollBar *>(os, "horizontal_sequence_scroll", GTUtilsMdi::activeWindow(os));
    GT_CHECK(NULL != hBar, "Horisontal scroll bar is not found");

    QStyleOptionSlider hScrollBarOptions;
    hScrollBarOptions.initFrom(hBar);

    while (!mcaSeqArea->isPositionVisible(position.x(), false)) {
        const QRect sliderSpaceRect = hBar->style()->subControlRect(QStyle::CC_ScrollBar, &hScrollBarOptions, QStyle::SC_ScrollBarGroove, hBar);
        const QPoint rightEdge(sliderSpaceRect.x() + sliderSpaceRect.width(), sliderSpaceRect.height() / 2);

        GTMouseDriver::moveTo(hBar->mapToGlobal(rightEdge) - QPoint(1, 0));
        GTMouseDriver::click();
    }

    SAFE_POINT(mcaSeqArea->isVisible(position, false), "The position is still invisible after scrolling", );
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "clickCollapseTriangle"
void GTUtilsMcaEditorSequenceArea::clickCollapseTriangle(GUITestOpStatus &os, QString rowName, bool showChromatogram){
    McaEditorSequenceArea *mcaEditArea = qobject_cast<McaEditorSequenceArea*>(GTWidget::findWidget(os, "mca_editor_sequence_area"));
    GT_CHECK(mcaEditArea != NULL, "McaEditorSequenceArea not found");

    int rowNum = getVisibleNames(os).indexOf(rowName);
    GT_CHECK(rowNum != -1, "sequence not found in nameList");
    QWidget* nameList = GTWidget::findWidget(os, "msa_editor_name_list");
    int yPos = mcaEditArea->getEditor()->getUI()->getRowHeightController()->getRowScreenCenterByNumber(rowNum);
    if (showChromatogram) {
        yPos -= 65;
    }
    QPoint localCoord = QPoint(15, yPos);
    QPoint globalCoord = nameList->mapToGlobal(localCoord);
    GTMouseDriver::moveTo(globalCoord);
    GTMouseDriver::click();
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "isCollapsed"
bool GTUtilsMcaEditorSequenceArea::isChromatogramShown(GUITestOpStatus &os, QString rowName){
    McaEditorSequenceArea *mcaEditArea = qobject_cast<McaEditorSequenceArea*>(GTWidget::findWidget(os, "mca_editor_sequence_area"));
    GT_CHECK_RESULT(mcaEditArea != NULL, "McaEditorSequenceArea not found", false);
    int rowNum = GTUtilsMcaEditor::getReadsNames(os).indexOf(rowName);
    GT_CHECK_RESULT(rowNum != -1, "sequence not found in nameList", false);
    int rowHeight = mcaEditArea->getEditor()->getUI()->getRowHeightController()->getRowHeight(rowNum);
    bool isCollapsed = rowHeight > 100;
    return isCollapsed;
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "getNameList"
QStringList GTUtilsMcaEditorSequenceArea::getNameList(GUITestOpStatus &os) {
    QMainWindow* mw = AppContext::getMainWindow()->getQMainWindow();
    McaEditor* editor = mw->findChild<McaEditor*>();
    CHECK_SET_ERR_RESULT(editor != NULL, "MsaEditor not found", QStringList());

    QStringList result = editor->getMaObject()->getMultipleAlignment()->getRowNames();

    return result;
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "callContextMenu"
void GTUtilsMcaEditorSequenceArea::callContextMenu(GUITestOpStatus &os, const QPoint &innerCoords) {
    if (innerCoords.isNull()) {
        GTWidget::click(os, getSequenceArea(os), Qt::RightButton);
    } else {
        moveTo(os, innerCoords);
        GTMouseDriver::click(Qt::RightButton);
    }
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "moveTo"
void GTUtilsMcaEditorSequenceArea::moveTo(GUITestOpStatus &os, const QPoint &p)
{
    QPoint convP = convertCoordinates(os, p);

    GTMouseDriver::moveTo(convP);
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "convertCoordinates"
QPoint GTUtilsMcaEditorSequenceArea::convertCoordinates(GUITestOpStatus &os, const QPoint p) {
    QWidget* activeWindow = GTUtilsMdi::activeWindow(os);
    McaEditorSequenceArea *mcaEditArea = qobject_cast<McaEditorSequenceArea*>(GTWidget::findWidget(os, "mca_editor_sequence_area", activeWindow));
    GT_CHECK_RESULT(mcaEditArea != NULL, "McaEditorSequenceArea not found", QPoint());

    const int posX = static_cast<int>(mcaEditArea->getEditor()->getUI()->getBaseWidthController()->getBaseGlobalRange(p.x()).center());
    const int posY = static_cast<int>(mcaEditArea->getEditor()->getUI()->getRowHeightController()->getRowGlobalRangeByNumber(p.y()).center());
    return mcaEditArea->mapToGlobal(QPoint(posX, posY));
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "getReferenceReg"
QString GTUtilsMcaEditorSequenceArea::getReferenceReg(GUITestOpStatus &os, int num, int length) {
    QMainWindow* mw = AppContext::getMainWindow()->getQMainWindow();
    GT_CHECK_RESULT(mw != NULL, "QMainWindow not found", QString());
    McaEditor* editor = mw->findChild<McaEditor*>();
    GT_CHECK_RESULT(editor != NULL, "McaEditor not found", QString());
    MultipleChromatogramAlignmentObject* obj = editor->getMaObject();
    GT_CHECK_RESULT(obj != NULL, "MultipleChromatogramAlignmentObject not found", QString());

    U2OpStatus2Log status;
    QByteArray seq = obj->getReferenceObj()->getSequenceData(U2Region(num, 1), status);

    return seq;
}
#undef GT_METHOD_NAME

#define GT_METHOD_NAME "moveTheBorderBetweenAlignmentAndRead"
void GTUtilsMcaEditorSequenceArea::moveTheBorderBetweenAlignmentAndRead(HI::GUITestOpStatus &os, int shift) {
    QStringList visible = getVisibleNames(os);
    GT_CHECK_RESULT(visible.size() != 0, "No visible reads", );
    QString firstVisible = visible.first();

    const QRect sequenceNameRect = GTUtilsMcaEditor::getReadNameRect(os, firstVisible);
    GTMouseDriver::moveTo(QPoint (sequenceNameRect.right() + 2, sequenceNameRect.center().y()));
    GTMouseDriver::press(Qt::MouseButton::LeftButton);
    GTGlobals::sleep(1000);
    GTMouseDriver::moveTo(QPoint(sequenceNameRect.right() + 2 + shift, sequenceNameRect.center().y()));
    GTMouseDriver::release(Qt::MouseButton::LeftButton);
}
#undef GT_METHOD_NAME

#undef GT_CLASS_NAME

}//namespace
