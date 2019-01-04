#include "clientcommunication.h"

using namespace network_st;

extern QString g_sender_ip;
extern QString g_server_ip;
extern QString g_local_ip;

ClientCommunication::ClientCommunication(QWidget *parent)
	: QWidget(parent)
{
	ui_.setupUi(this);
	Init();
}

ClientCommunication::~ClientCommunication()
{
}

void ClientCommunication::Init()
{
// 	SetStreamHandle(false);


	netInterface_ = NetInterface::GetInstance();
	bool is_ok = connect(netInterface_
		, SIGNAL(Signal_UpdateUITcpReplyMessage(MessageUnit *))
		, this
		, SLOT(Slot_UpdateUITcpReplyMessage(MessageUnit *)));

	is_ok = connect(netInterface_
		, SIGNAL(Signal_UpdateUITcpReceivedMessage(MessageUnit *))
		, this
		, SLOT(Slot_UpdateUITcpReceivedMessage(MessageUnit *)));

	is_ok = connect(netInterface_
		, SIGNAL(Signal_AddReceivedMessage(QString))
		, this
		, SLOT(Slot_AddReceivedMessage(QString)));
}

void ClientCommunication::Slot_AddReceivedMessage(QString _message)
{
	ui_.textEdit_received_->append(_message);

// 	QString receipt_msg = udpSendThread_->GetQueueLastValue();

	MessageUnit *messageUnit = netInterface_->GetReceiveNewMessage();

	QString receipt_msg = QString::fromLocal8Bit(messageUnit->byteArray_msg->data());

	ui_.textEdit_reply_->append(receipt_msg);
}

void network_st::ClientCommunication::Slot_UpdateUITcpReceivedMessage(MessageUnit *_messageUnit)
{
	QString message = QString::fromLocal8Bit(_messageUnit->msg);
	ui_.textEdit_received_->append(message);
}

void network_st::ClientCommunication::Slot_UpdateUITcpReplyMessage(MessageUnit *_messageUnit)
{
	QString message = QString::fromLocal8Bit(_messageUnit->msg);
	ui_.textEdit_reply_->append(message);

}
