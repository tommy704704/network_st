/********************************************************************************
** Form generated from reading UI file 'FileServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESERVER_H
#define UI_FILESERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileServerClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_send_;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_url_;
    QLineEdit *lineEdit_ip_;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_selectFile_;
    QLabel *label;
    QProgressBar *progressBar_upload_;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit_receivedFile_;
    QProgressBar *progressBar_received_;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_download_url_;
    QPushButton *pushButton_download_;

    void setupUi(QWidget *FileServerClass)
    {
        if (FileServerClass->objectName().isEmpty())
            FileServerClass->setObjectName(QStringLiteral("FileServerClass"));
        FileServerClass->resize(724, 547);
        gridLayout = new QGridLayout(FileServerClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(FileServerClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_send_ = new QPushButton(groupBox);
        pushButton_send_->setObjectName(QStringLiteral("pushButton_send_"));

        gridLayout_2->addWidget(pushButton_send_, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_url_ = new QLineEdit(groupBox);
        lineEdit_url_->setObjectName(QStringLiteral("lineEdit_url_"));

        verticalLayout_2->addWidget(lineEdit_url_);

        lineEdit_ip_ = new QLineEdit(groupBox);
        lineEdit_ip_->setObjectName(QStringLiteral("lineEdit_ip_"));

        verticalLayout_2->addWidget(lineEdit_ip_);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_selectFile_ = new QPushButton(groupBox);
        pushButton_selectFile_->setObjectName(QStringLiteral("pushButton_selectFile_"));

        verticalLayout->addWidget(pushButton_selectFile_);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        progressBar_upload_ = new QProgressBar(groupBox);
        progressBar_upload_->setObjectName(QStringLiteral("progressBar_upload_"));
        progressBar_upload_->setValue(0);

        gridLayout_2->addWidget(progressBar_upload_, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(FileServerClass);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEdit_receivedFile_ = new QTextEdit(groupBox_2);
        textEdit_receivedFile_->setObjectName(QStringLiteral("textEdit_receivedFile_"));

        gridLayout_3->addWidget(textEdit_receivedFile_, 1, 0, 1, 1);

        progressBar_received_ = new QProgressBar(groupBox_2);
        progressBar_received_->setObjectName(QStringLiteral("progressBar_received_"));
        progressBar_received_->setValue(0);

        gridLayout_3->addWidget(progressBar_received_, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(FileServerClass);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_download_url_ = new QLineEdit(groupBox_3);
        lineEdit_download_url_->setObjectName(QStringLiteral("lineEdit_download_url_"));

        gridLayout_4->addWidget(lineEdit_download_url_, 0, 0, 1, 1);

        pushButton_download_ = new QPushButton(groupBox_3);
        pushButton_download_->setObjectName(QStringLiteral("pushButton_download_"));

        gridLayout_4->addWidget(pushButton_download_, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);


        retranslateUi(FileServerClass);

        QMetaObject::connectSlotsByName(FileServerClass);
    } // setupUi

    void retranslateUi(QWidget *FileServerClass)
    {
        FileServerClass->setWindowTitle(QApplication::translate("FileServerClass", "FileServer", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FileServerClass", "\346\226\207\344\273\266\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_send_->setText(QApplication::translate("FileServerClass", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_selectFile_->setText(QApplication::translate("FileServerClass", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("FileServerClass", "\346\216\245\346\224\266\347\253\257IP:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("FileServerClass", "\346\226\207\344\273\266\346\216\245\346\224\266", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FileServerClass", "\346\226\207\344\273\266\346\216\245\346\224\266", Q_NULLPTR));
        pushButton_download_->setText(QApplication::translate("FileServerClass", "\344\270\213\350\275\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileServerClass: public Ui_FileServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESERVER_H
