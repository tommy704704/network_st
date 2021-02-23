#include "NetInterface.h"
#include "LogManager.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "AddressManager.h"
#include "SocketManager.h"
#include "MessageManager.h"
#include "NewTcpClient.h"
#include "UdpReceiveThread.h"
#include "UdpSendThread.h"

using namespace network_client_st;
NetInterface *NetInterface::instance_ = NULL;
extern QString g_local_ip;

NetInterface::~NetInterface()
{

	delete udpReceiveThread_;

	udpReceiveThread_ = NULL;

	udpSendThread_->QuitThread();
	//delete udpSendThread_;
	udpSendThread_ = NULL;
	
	delete tcpSendThread_;

	tcpSendThread_ = NULL;

	delete addressManager_;

	addressManager_ = NULL;
	delete logManager_;

	logManager_ = NULL;

	delete messageManager_;

	messageManager_ = NULL;

	delete socketManager_;

	socketManager_ = NULL;

	delete tcpClient_;

	tcpClient_ = NULL;

}

QTcpSocket * network_client_st::NetInterface::GetSendTcpSocketByIP(QString _ip)
{
	QTcpSocket *p_result = socketManager_->GetSendTcpSocketByIP(_ip);
	return p_result;
}

NetInterface::NetInterface()
{
	qDebug() << "NetInterface()";

	Init();
}

void NetInterface::Init()
{


	g_local_ip = GetLocalIP();

	logManager_ = LogManager::GetInstance();

	messageManager_ = MessageManager::GetInstance();

	addressManager_ = AddressManager::GetInstance();
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

	//is_ok = connect(udpReceiveThread_
	//	, SIGNAL(Signal_GetServerAddress())
	//	, this
	//	, SIGNAL(Signal_GetServerAddress()));
	///<stao 20210222 信号没有使用
	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_AddReceivedMessage(QString))
		, this
		, SIGNAL(Signal_AddReceivedMessage(QString)));

	//is_ok = connect(udpReceiveThread_
	//	, SIGNAL(Signal_BindNewTcpConnection())
	//	, this
	//	, SIGNAL(Signal_BindNewTcpConnection())
	//	, Qt::BlockingQueuedConnection);
	///<stao 20210222 信号没有使用
	///<消息传递，通知重连接
	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_GetServerAddress())
		, tcpClient_
		, SLOT(Slot_GetServerAddress()));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_BindNewTcpConnection())
		, tcpClient_
		, SLOT(Slot_BindNewTcpConnection())
		//, Qt::DirectConnection);
		, Qt::BlockingQueuedConnection);

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_DisconnectTcpFromHost(QString))
		, this
		, SLOT(Slot_RemoveSendedTcpSocketFromConnected(QString)));

}

QList<Server*>* network_client_st::NetInterface::GetAllServers()
{
	return addressManager_->GetAllServers();
}

MessageUnit * network_client_st::NetInterface::GetReceiveNewMessage()
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

void network_client_st::NetInterface::AddSendMessage(MessageUnit *_messageUnit)
{
	messageManager_->AddSendMessage(_messageUnit);
}

void network_client_st::NetInterface::Slot_RemoveSendedTcpSocketFromConnected(QString _ip)
{
	socketManager_->RemoveSendedTcpSocketFromConnected(_ip);
}

