/********************************************************************************
** Form generated from reading UI file 'FileClient.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECLIENT_H
#define UI_FILECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileClientClass
{
public:

    void setupUi(QWidget *FileClientClass)
    {
        if (FileClientClass->objectName().isEmpty())
            FileClientClass->setObjectName(QStringLiteral("FileClientClass"));
        FileClientClass->resize(600, 400);

        retranslateUi(FileClientClass);

        QMetaObject::connectSlotsByName(FileClientClass);
    } // setupUi

    void retranslateUi(QWidget *FileClientClass)
    {
        FileClientClass->setWindowTitle(QApplication::translate("FileClientClass", "FileClient", 0));
    } // retranslateUi

};

namespace Ui {
    class FileClientClass: public Ui_FileClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECLIENT_H
