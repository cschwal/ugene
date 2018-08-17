/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2018 UniPro <ugene@unipro.ru>
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

#include <QTabWidget>
#include <QWebEngineView>

#include <primitives/GTWebView.h>
#include <primitives/GTWidget.h>

#include "GTUtilsDashboard.h"

namespace U2 {
using namespace HI;

#define GT_CLASS_NAME "GTUtilsDashboard"
QMap<QString, GTUtilsDashboard::Tabs> GTUtilsDashboard::initTabMap(){
    QMap<QString, GTUtilsDashboard::Tabs> result;
    result.insert("Overview", GTUtilsDashboard::Overview);
    result.insert("Input", GTUtilsDashboard::Input);
    result.insert("External Tools", GTUtilsDashboard::ExternalTools);
    return result;
}

const QMap<QString, GTUtilsDashboard::Tabs> GTUtilsDashboard::tabMap = initTabMap();

QWebEngineView* GTUtilsDashboard::getDashboard(HI::GUITestOpStatus &os){
    return GTWidget::findExactWidget<QWebEngineView*>(os, "Dashboard");
}

QTabWidget* GTUtilsDashboard::getTabWidget(HI::GUITestOpStatus &os){
    return GTWidget::findExactWidget<QTabWidget*>(os, "WorkflowTabView");
}

QStringList GTUtilsDashboard::getOutputFiles(HI::GUITestOpStatus &os, const QString &producerName) {
    const HIWebElement outputFilesWidget = GTWebView::findElementById(os, getDashboard(os), "output files", "table");
    const QList<HIWebElement> outputFilesButtons = GTWebView::findElementsById(os, getDashboard(os), producerName, "button", outputFilesWidget);
    QStringList outputFilesNames;
    foreach (const HIWebElement &outputFilesButton, outputFilesButtons) {
        const QString outputFileName = outputFilesButton.toPlainText();
        if (!outputFileName.isEmpty()) {
            outputFilesNames << outputFileName;
        }
    }
    return outputFilesNames;
}

#define GT_METHOD_NAME "clickOutputFile"
void GTUtilsDashboard::clickOutputFile(GUITestOpStatus &os, const QString &outputFileName, const QString &producerName) {
    const QList<HIWebElement> outputFilesButtons = GTWebView::findElementsById(os, getDashboard(os), producerName, "button");
    foreach (const HIWebElement &outputFilesButton, outputFilesButtons) {
        QString buttonText = outputFilesButton.toPlainText();
        if (buttonText == outputFileName) {
            click(os, outputFilesButton);
            return;
        }

        if (buttonText.endsWith("...")) {
            buttonText.chop(QString("...").length());
            if (!buttonText.isEmpty() && outputFileName.startsWith(buttonText)) {
                click(os, outputFilesButton);
                return;
            }
        }
    }

    GT_CHECK(false, QString("The output file with name '%1' produced by '%2' not found").arg(outputFileName).arg(producerName));
}
#undef GT_METHOD_NAME

HIWebElement GTUtilsDashboard::findElement(HI::GUITestOpStatus &os, QString text, QString tag, bool exactMatch){
    return GTWebView::findElement(os, getDashboard(os), text, tag, exactMatch);
}

HIWebElement GTUtilsDashboard::findTreeElement(HI::GUITestOpStatus &os, QString text){
    return GTWebView::findTreeElement(os, getDashboard(os), text);
}

HIWebElement GTUtilsDashboard::findContextMenuElement(HI::GUITestOpStatus &os, QString text){
    return GTWebView::findContextMenuElement(os, getDashboard(os), text);
}

void GTUtilsDashboard::click(HI::GUITestOpStatus &os, HIWebElement el, Qt::MouseButton button){
    GTWebView::click(os, getDashboard(os), el, button);
}

bool GTUtilsDashboard::areThereNotifications(HI::GUITestOpStatus &os) {
    openTab(os, Overview);
    return GTWebView::doesElementExist(os, getDashboard(os), "Notifications", "DIV", true);
}

#define GT_METHOD_NAME "openTab"
void GTUtilsDashboard::openTab(HI::GUITestOpStatus &os, Tabs tab){
    HIWebElement el = GTWebView::findElement(os, getDashboard(os), tabMap.key(tab), "A");
    GTWebView::click(os, getDashboard(os), el);
}
#undef GT_METHOD_NAME

#undef GT_CLASS_NAME

}   // namespace U2
