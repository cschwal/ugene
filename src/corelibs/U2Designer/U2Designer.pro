include (U2Designer.pri)

# Input
HEADERS += src/BreakpointHitCountDialog.h \
           src/DatasetWidget.h \
           src/DatasetsController.h \
           src/DatasetsListWidget.h \
           src/DbFolderItem.h \
           src/DbObjectItem.h \
           src/DelegateEditors.h \
           src/DesignerUtils.h \
           src/DirectoryItem.h \
           src/EditBreakpointLabelsDialog.h \
           src/EditMarkerGroupDialog.h \
           src/EstimationReporter.h \
           src/FileItem.h \
           src/GrouperEditor.h \
           src/GrouperEditorWidget.h \
           src/MarkerEditor.h \
           src/MarkerEditorWidget.h \
           src/NewBreakpointDialog.h \
           src/NewGrouperSlotDialog.h \
           src/OutputFileDialog.h \
           src/PropertyWidget.h \
           src/QDScheduler.h \
           src/UrlItem.h \
           src/WorkflowGUIUtils.h \
           src/dashboard/Dashboard.h \
           src/dashboard/DashboardInfo.h \
           src/dashboard/DashboardInfoRegistry.h \
           src/dashboard/DashboardJsAgent.h \
           src/dashboard/DashboardPageController.h \
           src/dashboard/RemoveDashboardsTask.h \
           src/dashboard/ScanDashboardsDirTask.h \
           src/dashboard/webview/JavaScriptAgent.h \
           src/dashboard/webview/SimpleWebViewBasedWidgetController.h \
           src/dashboard/webview/U2WebView.h \
           src/dashboard/webview/WebViewController.h \
           src/dashboard/webview/WebViewControllerPrivate.h \
           src/support/OutputDirectoryWidget.h \
           src/support/URLLineEdit.h \
           src/wizard/BowtieWidgetController.h \
           src/wizard/ElementSelectorController.h \
           src/wizard/PairedDatasetsController.h \
           src/wizard/PropertyWizardController.h \
           src/wizard/RadioController.h \
           src/wizard/SelectorActors.h \
           src/wizard/SettingsController.h \
           src/wizard/TophatSamplesWidgetController.h \
           src/wizard/UrlAndDatasetWizardController.h \
           src/wizard/WDWizardPage.h \
           src/wizard/WidgetController.h \
           src/wizard/WizardController.h \
           src/wizard/WizardPageController.h

useWebKit() {
    HEADERS += src/dashboard/webview/webkit/WebViewWebKitControllerPrivate.h
} else {
    HEADERS += src/dashboard/webview/qtwebengine/WebViewQtWebEngineControllerPrivate.h \
               src/dashboard/webview/qtwebengine/webchannel/U2WebChannel.h \
               src/dashboard/webview/qtwebengine/webchannel/WebSocketClientWrapper.h \
               src/dashboard/webview/qtwebengine/webchannel/WebSocketTransport.h
}


FORMS += src/AnnsActionDialog.ui \
         src/BreakpointHitCountDialog.ui \
         src/CreateDirectoryDialog.ui \
         src/DatasetWidget.ui \
         src/DbFolderOptions.ui \
         src/DirectoryOptions.ui \
         src/EditBreakpointLabelsDialog.ui \
         src/EditFloatMarkerWidget.ui \
         src/EditIntegerMarkerWidget.ui \
         src/EditMarkerDialog.ui \
         src/EditMarkerGroupDialog.ui \
         src/EditStringMarkerWidget.ui \
         src/GrouperEditorWidget.ui \
         src/MarkerEditorWidget.ui \
         src/MsaActionDialog.ui \
         src/NewBreakpointDialog.ui \
         src/NewGrouperSlotDialog.ui \
         src/OutputFileDialog.ui \
         src/SequenceActionDialog.ui \
         src/StringActionDialog.ui

SOURCES += src/BreakpointHitCountDialog.cpp \
           src/DatasetWidget.cpp \
           src/DatasetsController.cpp \
           src/DatasetsListWidget.cpp \
           src/DbFolderItem.cpp \
           src/DbObjectItem.cpp \
           src/DelegateEditors.cpp \
           src/DesignerUtils.cpp \
           src/DirectoryItem.cpp \
           src/EditBreakpointLabelsDialog.cpp \
           src/EditMarkerGroupDialog.cpp \
           src/EstimationReporter.cpp \
           src/FileItem.cpp \
           src/GrouperEditor.cpp \
           src/GrouperEditorWidget.cpp \
           src/MarkerEditor.cpp \
           src/MarkerEditorWidget.cpp \
           src/NewBreakpointDialog.cpp \
           src/NewGrouperSlotDialog.cpp \
           src/OutputFileDialog.cpp \
           src/PropertyWidget.cpp \
           src/QDScheduler.cpp \
           src/UrlItem.cpp \
           src/WorkflowGUIUtils.cpp \
           src/dashboard/Dashboard.cpp \
           src/dashboard/DashboardInfo.cpp \
           src/dashboard/DashboardInfoRegistry.cpp \
           src/dashboard/DashboardJsAgent.cpp \
           src/dashboard/DashboardPageController.cpp \
           src/dashboard/RemoveDashboardsTask.cpp \
           src/dashboard/ScanDashboardsDirTask.cpp \
           src/dashboard/webview/JavaScriptAgent.cpp \
           src/dashboard/webview/SimpleWebViewBasedWidgetController.cpp \
           src/dashboard/webview/WebViewController.cpp \
           src/dashboard/webview/WebViewControllerPrivate.cpp \
           src/support/OutputDirectoryWidget.cpp \
           src/support/URLLineEdit.cpp \
           src/wizard/BowtieWidgetController.cpp \
           src/wizard/ElementSelectorController.cpp \
           src/wizard/PairedDatasetsController.cpp \
           src/wizard/PropertyWizardController.cpp \
           src/wizard/RadioController.cpp \
           src/wizard/SelectorActors.cpp \
           src/wizard/SettingsController.cpp \
           src/wizard/TophatSamplesWidgetController.cpp \
           src/wizard/UrlAndDatasetWizardController.cpp \
           src/wizard/WDWizardPage.cpp \
           src/wizard/WidgetController.cpp \
           src/wizard/WizardController.cpp \
           src/wizard/WizardPageController.cpp

useWebKit() {
    SOURCES += src/dashboard/webview/webkit/WebViewWebKitControllerPrivate.cpp
} else {
    SOURCES += src/dashboard/webview/qtwebengine/WebViewQtWebEngineControllerPrivate.cpp \
               src/dashboard/webview/qtwebengine/webchannel/U2WebChannel.cpp \
               src/dashboard/webview/qtwebengine/webchannel/WebSocketClientWrapper.cpp \
               src/dashboard/webview/qtwebengine/webchannel/WebSocketTransport.cpp

}


RESOURCES += U2Designer.qrc
TRANSLATIONS += transl/russian.ts
