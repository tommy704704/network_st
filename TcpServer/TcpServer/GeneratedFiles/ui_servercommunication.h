/********************************************************************************
** Form generated from reading UI file 'servercommunication.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCOMMUNICATION_H
#define UI_SERVERCOMMUNICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerCommunicationClass
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget_sendMessage_;
    QPushButton *pushButton_delete_;
    QPushButton *pushButton_add_;
    QPushButton *pushButton_automatic_generate_;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_address_;
    QPushButton *pushButton_stop_;
    QPushButton *pushButton_add_address_;
    QPushButton *pushButton_send_;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_delete_address_;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget_ReceivedMessage_;

    void setupUi(QWidget *ServerCommunicationClass)
    {
        if (ServerCommunicationClass->objectName().isEmpty())
            ServerCommunicationClass->setObjectName(QStringLiteral("ServerCommunicationClass"));
        ServerCommunicationClass->resize(764, 971);
        gridLayout_5 = new QGridLayout(ServerCommunicationClass);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(ServerCommunicationClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        listWidget_sendMessage_ = new QListWidget(groupBox_3);
        listWidget_sendMessage_->setObjectName(QStringLiteral("listWidget_sendMessage_"));

        gridLayout->addWidget(listWidget_sendMessage_, 0, 0, 1, 4);

        pushButton_delete_ = new QPushButton(groupBox_3);
        pushButton_delete_->setObjectName(QStringLiteral("pushButton_delete_"));

        gridLayout->addWidget(pushButton_delete_, 1, 2, 1, 1);

        pushButton_add_ = new QPushButton(groupBox_3);
        pushButton_add_->setObjectName(QStringLiteral("pushButton_add_"));

        gridLayout->addWidget(pushButton_add_, 1, 1, 1, 1);

        pushButton_automatic_generate_ = new QPushButton(groupBox_3);
        pushButton_automatic_generate_->setObjectName(QStringLiteral("pushButton_automatic_generate_"));

        gridLayout->addWidget(pushButton_automatic_generate_, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget_address_ = new QTableWidget(groupBox_4);
        if (tableWidget_address_->columnCount() < 2)
            tableWidget_address_->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_address_->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_address_->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_address_->setObjectName(QStringLiteral("tableWidget_address_"));

        gridLayout_2->addWidget(tableWidget_address_, 0, 0, 1, 6);

        pushButton_stop_ = new QPushButton(groupBox_4);
        pushButton_stop_->setObjectName(QStringLiteral("pushButton_stop_"));

        gridLayout_2->addWidget(pushButton_stop_, 1, 4, 1, 1);

        pushButton_add_address_ = new QPushButton(groupBox_4);
        pushButton_add_address_->setObjectName(QStringLiteral("pushButton_add_address_"));

        gridLayout_2->addWidget(pushButton_add_address_, 1, 1, 1, 1);

        pushButton_send_ = new QPushButton(groupBox_4);
        pushButton_send_->setObjectName(QStringLiteral("pushButton_send_"));

        gridLayout_2->addWidget(pushButton_send_, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_delete_address_ = new QPushButton(groupBox_4);
        pushButton_delete_address_->setObjectName(QStringLiteral("pushButton_delete_address_"));

        gridLayout_2->addWidget(pushButton_delete_address_, 1, 2, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ServerCommunicationClass);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tableWidget_ReceivedMessage_ = new QTableWidget(groupBox_2);
        if (tableWidget_ReceivedMessage_->columnCount() < 2)
            tableWidget_ReceivedMessage_->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_ReceivedMessage_->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_ReceivedMessage_->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_ReceivedMessage_->setObjectName(QStringLiteral("tableWidget_ReceivedMessage_"));

        gridLayout_4->addWidget(tableWidget_ReceivedMessage_, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(ServerCommunicationClass);

        QMetaObject::connectSlotsByName(ServerCommunicationClass);
    } // setupUi

    void retranslateUi(QWidget *ServerCommunicationClass)
    {
        ServerCommunicationClass->setWindowTitle(QApplication::translate("ServerCommunicationClass", "TCP\346\234\215\345\212\241\347\253\257", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ServerCommunicationClass", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ServerCommunicationClass", "\345\217\221\351\200\201\345\221\275\344\273\244\351\230\237\345\210\227", Q_NULLPTR));
        pushButton_delete_->setText(QApplication::translate("ServerCommunicationClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_add_->setText(QApplication::translate("ServerCommunicationClass", "\345\242\236\345\212\240", Q_NULLPTR));
        pushButton_automatic_generate_->setText(QApplication::translate("ServerCommunicationClass", "\350\207\252\345\212\250\347\224\237\346\210\220", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("ServerCommunicationClass", "\345\234\260\345\235\200\345\210\227\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_address_->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ServerCommunicationClass", "IP", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_address_->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ServerCommunicationClass", "\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_stop_->setText(QApplication::translate("ServerCommunicationClass", "\345\201\234\346\255\242", Q_NULLPTR));
        pushButton_add_address_->setText(QApplication::translate("ServerCommunicationClass", "\345\242\236\345\212\240", Q_NULLPTR));
        pushButton_send_->setText(QApplication::translate("ServerCommunicationClass", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_delete_address_->setText(QApplication::translate("ServerCommunicationClass", "\345\210\240\351\231\244", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ServerCommunicationClass", "\346\216\245\346\224\266\345\233\236\346\211\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_ReceivedMessage_->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ServerCommunicationClass", "IP", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_ReceivedMessage_->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ServerCommunicationClass", "\345\233\236\345\244\215\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerCommunicationClass: public Ui_ServerCommunicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCOMMUNICATION_H
