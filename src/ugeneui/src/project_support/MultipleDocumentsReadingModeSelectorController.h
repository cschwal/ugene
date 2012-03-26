#ifndef _MULTIPLE_SEQUENCE_FILES_SELECTOR_H_
#define _MULTIPLE_SEQUENCE_FILES_SELECTOR_H_

#include <QDialog>
#include <QVariant>
#include <QtCore/QList>

#include <U2Core/GUrl.h>

#include "ui/ui_MultimpleSequenceFilesReadingMode.h"

namespace U2{

class MultipleDocumentsReadingModeSelectorController {
public:	
	static bool adjustReadingMode(QVariantMap& , QList<GUrl>& urls);
	static bool isAbilityToUniteDocumnents(const QVariantMap& hintsDiocuments);    
private:
    MultipleDocumentsReadingModeSelectorController();
};

class MultipleDocumentsReadingModeDialog : public QDialog, public Ui_MultipleDocumentsReadingModeSelectorController{
Q_OBJECT
public:
    MultipleDocumentsReadingModeDialog(const QList<GUrl>& urls, QWidget* parent = 0); 
    ~MultipleDocumentsReadingModeDialog();
    bool setupGUI(QList<GUrl>& urls, QVariantMap& hintsDocuments);
    void setupOrderingMergeDocuments();
private slots:
   void sl_onMoveUp();
   void sl_onMoveDown();
   void sl_onChooseDirPath();
private:
   QString deleteNumPrefix(QString);
   void deleteAllNumPrefix();
   void changeNumPrefix();
   QString findUrlByFileName(const QString& fileName);
private:
    QList<GUrl> urls;
    QString extension4MergedDocument;
};

}

#endif