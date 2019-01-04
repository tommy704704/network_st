/********************************************************************************
** Form generated from reading UI file 'clientcommunication.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTCOMMUNICATION_H
#define UI_CLIENTCOMMUNICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientCommunicationClass
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_received_;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_reply_;

    void setupUi(QWidget *ClientCommunicationClass)
    {
        if (ClientCommunicationClass->objectName().isEmpty())
            ClientCommunicationClass->setObjectName(QStringLiteral("ClientCommunicationClass"));
        ClientCommunicationClass->resize(1034, 376);
        gridLayout_3 = new QGridLayout(ClientCommunicationClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(ClientCommunicationClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit_received_ = new QTextEdit(groupBox);
        textEdit_received_->setObjectName(QStringLiteral("textEdit_received_"));
        textEdit_received_->setReadOnly(true);

        gridLayout->addWidget(textEdit_received_, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ClientCommunicationClass);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit_reply_ = new QTextEdit(groupBox_2);
        textEdit_reply_->setObjectName(QStringLiteral("textEdit_reply_"));
        textEdit_reply_->setReadOnly(true);

        gridLayout_2->addWidget(textEdit_reply_, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);


        retranslateUi(ClientCommunicationClass);

        QMetaObject::connectSlotsByName(ClientCommunicationClass);
    } // setupUi

    void retranslateUi(QWidget *ClientCommunicationClass)
    {
        ClientCommunicationClass->setWindowTitle(QApplication::translate("ClientCommunicationClass", "TCP\345\256\242\346\210\267\347\253\257", 0));
        groupBox->setTitle(QApplication::translate("ClientCommunicationClass", "\346\216\245\346\224\266", 0));
        groupBox_2->setTitle(QApplication::translate("ClientCommunicationClass", "\345\233\236\345\244\215", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientCommunicationClass: public Ui_ClientCommunicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTCOMMUNICATION_H
