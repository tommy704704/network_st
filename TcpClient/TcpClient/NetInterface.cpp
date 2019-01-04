#include "NetInterface.h"
#include "LogManager.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "SocketManager.h"
#include "MessageManager.h"
#include "NewTcpClient.h"
#include "UdpReceiveThread.h"
#include "UdpSendThread.h"

using namespace network_st;
NetInterface *NetInterface::instance_ = NULL;
extern QString g_local_ip;
extern QString g_sender_ip;

NetInterface::~NetInterface()
{
	udpReceiveThread_->quit();

	udpReceiveThread_->wait();

	delete udpReceiveThread_;

	udpReceiveThread_ = NULL;

	udpSendThread_->quit();

	udpSendThread_->wait();

	delete udpSendThread_;

	udpSendThread_ = NULL;

	tcpSendThread_->quit();

	tcpSendThread_->wait();

	delete tcpSendThread_;

	tcpSendThread_ = NULL;

	delete logManager_;

	logManager_ = NULL;

	delete messageManager_;

	messageManager_ = NULL;

	delete socketManager_;

	socketManager_ = NULL;

	delete tcpClient_;

	tcpClient_ = NULL;

}

NetInterface::NetInterface()
{
	Init();
}

void NetInterface::Init()
{


	g_local_ip = GetLocalIP();

	logManager_ = LogManager::GetInstance();

	messageManager_ = MessageManager::GetInstance();

	udpSendThread_ = UdpSendThread::GetInstance();

	udpReceiveThread_ = new UdpReceiveThread();

	udpReceiveThread_->start();

	tcpSendThread_ = TcpSendThread::GetInstance();

	tcpSendThread_->start();

	socketManager_ = SocketManager::GetInstance();

	tcpClient_ = NewTcpClient::GetInstance();

	CreateSignalAndSlot();


}

void NetInterface::CreateSignalAndSlot()
{
	bool is_ok = connect(tcpSendThread_
		, SIGNAL(Signal_UpdateUITcpReplyMessage(MessageUnit *))
		, this
		, SIGNAL(Signal_UpdateUITcpReplyMessage(MessageUnit *)));

	is_ok = connect(tcpClient_
		, SIGNAL(Signal_UpdateUITcpReceivedMessage(MessageUnit *))
		, this
		, SIGNAL(Signal_UpdateUITcpReceivedMessage(MessageUnit *)));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_GetServerAddress())
		, this
		, SIGNAL(Signal_GetServerAddress()));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_AddReceivedMessage(QString))
		, this
		, SIGNAL(Signal_AddReceivedMessage(QString)));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_BindNewTcpConnection())
		, this
		, SIGNAL(Signal_BindNewTcpConnection())
		, Qt::BlockingQueuedConnection);

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_GetServerAddress())
		, tcpClient_
		, SLOT(Slot_GetServerAddress()));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_BindNewTcpConnection())
		, tcpClient_
		, SLOT(Slot_BindNewTcpConnection())
		, Qt::BlockingQueuedConnection);

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_DisconnectTcpFromHost(QString))
		, this
		, SLOT(Slot_RemoveSendedTcpSocketFromConnected(QString)));

}

MessageUnit * network_st::NetInterface::GetReceiveNewMessage()
{
// 	QString receipt_msg = udpSendThread_->GetQueueLastValue();
	MessageUnit *receipt_msg = messageManager_->GetReceivedMessage();
	if (receipt_msg)
	{
		return receipt_msg;
	}
	else
	{
		return NULL;
	}
}

void network_st::NetInterface::AddSendMessage(MessageUnit *_messageUnit)
{
	messageManager_->AddSendMessage(_messageUnit);
}

void network_st::NetInterface::Slot_RemoveSendedTcpSocketFromConnected(QString _ip)
{
	socketManager_->RemoveSendedTcpSocketFromConnected(_ip);
}

