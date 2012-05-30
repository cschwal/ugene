include (GUITestBase.pri)

# Input
HEADERS +=  src/GUITestBasePlugin.h \
#   Runnables
#   Runnables / Qt
            src/runnables/qt/MessageBoxFiller.h \
            src/runnables/qt/PopupChooser.h \
#   Runnables / UGENE
#   Runnables / UGENE / ugeneui
            src/runnables/ugene/ugeneui/CreateNewProjectWidgetFiller.h \
            src/runnables/ugene/ugeneui/ExportProjectDialogFiller.h \
            src/runnables/ugene/ugeneui/SequenceReadingModeSelectorDialogFiller.h \
#   Runnables / UGENE / corelibs
#   Runnables / UGENE / corelibs / U2Gui
            src/runnables/ugene/corelibs/U2Gui/CopyDocumentDialogFiller.h \
            src/runnables/ugene/corelibs/U2Gui/CreateAnnotationWidgetFiller.h \
            src/runnables/ugene/corelibs/U2Gui/CreateDocumentFromTextDialogFiller.h \
            src/runnables/ugene/corelibs/U2Gui/DownloadRemoteFileDialogFiller.h \
            src/runnables/ugene/corelibs/U2Gui/EditSequenceDialogFiller.h \
            src/runnables/ugene/corelibs/U2Gui/RangeSelectionDialogFiller.h \
            src/runnables/ugene/corelibs/U2Gui/RemovePartFromSequenceDialogFiller.h \
#   Runnables / UGENE / corelibs / U2Gui / util
            src/runnables/ugene/corelibs/U2Gui/util/PositionSelectorFiller.h \
            src/runnables/ugene/corelibs/U2Gui/util/RangeSelectorFiller.h \
#   Runnables / UGENE / corelibs / U2View
            src/runnables/ugene/corelibs/U2View/utils_smith_waterman/SmithWatermanDialogBaseFiller.h \
#   Runnables / UGENE / plugins / dotplot
            src/runnables/ugene/plugins/dotplot/DotPlotDialogFiller.h \
#   Runnables / UGENE / plugins / dna_export
            src/runnables/ugene/plugins/dna_export/ExportAnnotationsDialogFiller.h \
            src/runnables/ugene/plugins/dna_export/ExportMSA2SequencesDialogFiller.h \
            src/runnables/ugene/plugins/dna_export/ExportSequences2MSADialogFiller.h \
            src/runnables/ugene/plugins/dna_export/ExportSequencesDialogFiller.h \
#   Utils classes
            src/GTUtilsApp.h \
            src/GTUtilsDialog.h \
            src/GTUtilsDocument.h \
            src/GTUtilsLog.h \
            src/GTUtilsMdi.h \
            src/GTUtilsProject.h \
            src/GTUtilsProjectTreeView.h \
            src/GTUtilsAnnotationsTreeView.h \
            src/GTUtilsBookmarksTreeView.h \
            src/GTUtilsSequenceView.h \
            src/GTUtilsToolTip.h \
            src/GTUtilsTaskTreeView.h \
            src/GTUtilsMsaEditorSequenceArea.h \
#   Tests
            src/tests/GUIInitialChecks.h \
#   Tests/Regression Scenarios
            src/tests/regression_scenarios/GTTestsRegressionScenarios.h \
#   Tests/Common Scenarios
            src/tests/common_scenarios/sequence_edit/GTTestsSequenceEdit.h \
            src/tests/common_scenarios/sequence_view/GTTestsSequenceView.h \
            src/tests/common_scenarios/toggle_view/GTTestsToggleView.h \
            src/tests/common_scenarios/project/GTTestsProject.h \
            src/tests/common_scenarios/project/bookmarks/GTTestsBookmarks.h \
            src/tests/common_scenarios/project/relations/GTTestsProjectRelations.h \
            src/tests/common_scenarios/project/remote_request/GTTestsProjectRemoteRequest.h \
            src/tests/common_scenarios/project/sequence_exporting/GTTestsProjectSequenceExporting.h \
            src/tests/common_scenarios/project/multiple_docs/GTTestsProjectMultipleDocs.h \
            src/tests/common_scenarios/project/anonymous_project/GTTestsProjectAnonymousProject.h \
            src/tests/common_scenarios/project/user_locking/GTTestsProjectUserLocking.h \
            src/tests/common_scenarios/project/document_modifying/GTTestsProjectDocumentModifying.h \
            src/tests/common_scenarios/project/sequence_exporting/from_project_view/GTTestsFromProjectView.h \
            src/tests/common_scenarios/msa_editor/GTTestsMsaEditor.h \
#   UGENE primitives
            src/api/GTMSAEditorStatusWidget.h \
            src/api/GTRegionSelector.h \
            src/api/GTSequenceReadingModeDialog.h \
            src/api/GTSequenceReadingModeDialogUtils.h \
#   Qt primitives
            src/api/GTCheckBox.h \
            src/api/GTComboBox.h \
            src/api/GTTabWidget.h \
            src/api/GTTabBar.h \
            src/api/GTSpinBox.h \
            src/api/GTRadioButton.h \
            src/api/GTFileDialog.h \
            src/api/GTFile.h \
            src/api/GTGlobals.h \
            src/api/GTKeyboardDriver.h \
            src/api/GTLineEdit.h \
            src/api/GTMenu.h \
            src/api/GTMenuBar.h \
            src/api/GTMouse.h \
            src/api/GTMouseDriver.h \
            src/api/GTTextEdit.h \
            src/api/GTPlainTextEdit.h \
            src/api/GTScrollBar.h \
            src/api/GTSystem.h \
            src/api/GTTreeWidget.h \
            src/api/GTToolbar.h \
            src/api/GTWidget.h \
            src/api/GTAction.h

SOURCES +=  src/GUITestBasePlugin.cpp \
#   Runnables
#   Runnables / Qt
            src/runnables/qt/MessageBoxFiller.cpp \
            src/runnables/qt/PopupChooser.cpp \
#   Runnables / UGENE
#   Runnables / UGENE / ugeneui
            src/runnables/ugene/ugeneui/CreateNewProjectWidgetFiller.cpp \
            src/runnables/ugene/ugeneui/ExportProjectDialogFiller.cpp \
            src/runnables/ugene/ugeneui/SequenceReadingModeSelectorDialogFiller.cpp \
#   Runnables / UGENE / corelibs
#   Runnables / UGENE / corelibs / U2Gui
            src/runnables/ugene/corelibs/U2Gui/CopyDocumentDialogFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/CreateAnnotationWidgetFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/CreateDocumentFromTextDialogFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/DownloadRemoteFileDialogFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/EditSequenceDialogFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/RangeSelectionDialogFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/RemovePartFromSequenceDialogFiller.cpp \
#   Runnables / UGENE / corelibs / U2Gui / util
            src/runnables/ugene/corelibs/U2Gui/util/PositionSelectorFiller.cpp \
            src/runnables/ugene/corelibs/U2Gui/util/RangeSelectorFiller.cpp \
#   Runnables / UGENE / corelibs / U2View
            src/runnables/ugene/corelibs/U2View/utils_smith_waterman/SmithWatermanDialogBaseFiller.cpp \
#   Runnables / UGENE / plugins / dotplot
            src/runnables/ugene/plugins/dotplot/DotPlotDialogFiller.cpp \
#   Runnables / UGENE / plugins / dna_export
            src/runnables/ugene/plugins/dna_export/ExportAnnotationsDialogFiller.cpp \
            src/runnables/ugene/plugins/dna_export/ExportMSA2SequencesDialogFiller.cpp \
            src/runnables/ugene/plugins/dna_export/ExportSequences2MSADialogFiller.cpp \
            src/runnables/ugene/plugins/dna_export/ExportSequencesDialogFiller.cpp \
#   Utils classes
            src/GTUtilsApp.cpp \
            src/GTUtilsDialog.cpp \
            src/GTUtilsDocument.cpp \
            src/GTUtilsLog.cpp \
            src/GTUtilsMdi.cpp \
            src/GTUtilsProject.cpp \
            src/GTUtilsProjectTreeView.cpp \
            src/GTUtilsAnnotationsTreeView.cpp \
            src/GTUtilsBookmarksTreeView.cpp \
            src/GTUtilsSequenceView.cpp \
            src/GTUtilsToolTip.cpp \
            src/GTUtilsTaskTreeView.cpp \
            src/GTUtilsMsaEditorSequenceArea.cpp \
#   Tests
            src/tests/GUIInitialChecks.cpp \
#   Tests/Regression Scenarios
            src/tests/regression_scenarios/GTTestsRegressionScenarios.cpp \
#   Tests/Common Scenarios
            src/tests/common_scenarios/sequence_edit/GTTestsSequenceEdit.cpp \
            src/tests/common_scenarios/sequence_view/GTTestsSequenceView.cpp \
            src/tests/common_scenarios/toggle_view/GTTestsToggleView.cpp \
            src/tests/common_scenarios/project/GTTestsProject.cpp \
            src/tests/common_scenarios/project/bookmarks/GTTestsBookmarks.cpp \
            src/tests/common_scenarios/project/relations/GTTestsProjectRelations.cpp \
            src/tests/common_scenarios/project/remote_request/GTTestsProjectRemoteRequest.cpp \
            src/tests/common_scenarios/project/sequence_exporting/GTTestsProjectSequenceExporting.cpp \
            src/tests/common_scenarios/project/user_locking/GTTestsProjectUserLocking.cpp \
            src/tests/common_scenarios/project/anonymous_project/GTTestsProjectAnonymousProject.cpp \
            src/tests/common_scenarios/project/multiple_docs/GTTestsProjectMultipleDocs.cpp \
            src/tests/common_scenarios/project/document_modifying/GTTestsProjectDocumentModifying.cpp \
            src/tests/common_scenarios/project/sequence_exporting/from_project_view/GTTestsFromProjectView.cpp \
            src/tests/common_scenarios/msa_editor/GTTestsMsaEditor.cpp \
#   UGENE primitives
            src/api/GTMSAEditorStatusWidget.cpp \
            src/api/GTRegionSelector.cpp \
            src/api/GTSequenceReadingModeDialog.cpp \
            src/api/GTSequenceReadingModeDialogUtils.cpp \
#   Qt primitives
            src/api/GTCheckBox.cpp \
            src/api/GTComboBox.cpp \
            src/api/GTTabWidget.cpp \
            src/api/GTTabBar.cpp \
            src/api/GTSpinBox.cpp \
            src/api/GTRadioButton.cpp \
            src/api/GTFileDialog.cpp \
            src/api/GTFile.cpp \
            src/api/GTGlobals.cpp \
            src/api/GTKeyboardDriver.cpp \
            src/api/GTKeyboardDriverLinux.cpp \
            src/api/GTKeyboardDriverMac.cpp \
            src/api/GTKeyboardDriverWindows.cpp \
            src/api/GTLineEdit.cpp \
            src/api/GTMenu.cpp \
            src/api/GTMenuBar.cpp \
            src/api/GTMouse.cpp \
            src/api/GTMouseDriver.cpp \
            src/api/GTMouseDriverLinux.cpp \
            src/api/GTMouseDriverMac.cpp \
            src/api/GTMouseDriverWindows.cpp \
            src/api/GTTextEdit.cpp \
            src/api/GTPlainTextEdit.cpp \
            src/api/GTScrollBar.cpp \
            src/api/GTSystem.cpp \
            src/api/GTToolbar.cpp \
            src/api/GTTreeWidget.cpp \
            src/api/GTWidget.cpp \
            src/api/GTAction.cpp

