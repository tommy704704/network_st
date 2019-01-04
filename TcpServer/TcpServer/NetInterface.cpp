#include "NetInterface.h"
#include <QDateTime>
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "SocketManager.h"
#include "MessageManager.h"
#include "NewTcpServer.h"
#include "UdpReceiveThread.h"
#include "UdpSendThread.h"

using namespace network_st;
NetInterface *NetInterface::instance_ = NULL;
extern QString g_local_ip;
extern QString g_sender_ip;

NetInterface *NetInterface::GetInstance()
{
	if (!instance_)
	{
		instance_ = new NetInterface();
	}
	return instance_;
}


NetInterface::~NetInterface()
{
	delete TcpSendThread_;

	TcpSendThread_ = NULL;

	tcpReceiveThread_->quit();

	delete tcpReceiveThread_;

	tcpReceiveThread_ = NULL;

	delete udpSendThread_;

	udpSendThread_ = NULL;

	delete udpReceiveThread_;

	udpReceiveThread_ = NULL;

	delete tcpServer_;

	tcpServer_ = NULL;

	delete addressManager_;

	addressManager_ = NULL;
	
	delete logManager_;

	logManager_ = NULL;
	
	delete messageManager_;

	messageManager_ = NULL;

	delete socketManager_;

	socketManager_ = NULL;

}

void NetInterface::BroadcastMessage()
{

}

void NetInterface::SendMessage(MessageUnit *_messageUnit)
{
    /*消息加入队列*/
	messageManager_->AppendSendedMessage(_messageUnit);
// 	socketManager_->AppendSendedMessage(_messageUnit);
}

void NetInterface::HadHandleMessage()
{
    /*删除队列第一个消息，因为已被处理，此函数被相应消息的模块调用*/
	messageManager_->RemoveReceivedMessage();
// 	socketManager_->RemoveReceivedMessage();
}

NetInterface::NetInterface()
{
	qDebug() << "NetInterface()";

	Init();
}

void NetInterface::Init()
{

	g_local_ip = GetLocalIP();

	udpReceiveThread_ = UdpReceiveThread::GetInstance();

	udpReceiveThread_->start();
	//udp接收线程

	udpSendThread_ = UdpSendThread::GetInstance();

	udpSendThread_->start();
	//udp发送线程

	socketManager_ = SocketManager::GetInstance();
	
	messageManager_ = MessageManager::GetInstance();
	
	addressManager_ = AddressManager::GetInstance();

	logManager_ = LogManager::GetInstance();

	tcpServer_ = NewTcpServer::GetInstance();

	TcpSendThread_ = TcpSendThread::GetInstance();

    tcpReceiveThread_ = TcpReceiveThread::GetInstance();

	TcpSendThread_->start();

	tcpReceiveThread_->start();

    CreateSignalAndSlot();

}

void NetInterface::CreateSignalAndSlot()
{
    bool is_ok = connect(tcpReceiveThread_
		, SIGNAL(Signal_ReceivedMessage(MessageUnit *))
        , this
		, SLOT(Slot_ReceivedMessage(MessageUnit *)));

	is_ok = connect(udpSendThread_
		, SIGNAL(Signal_UpdateOfflineAddressList(QList<Client *> *))
		, this
		, SIGNAL(Signal_UpdateOfflineAddressList(QList<Client *> *)));

	is_ok = connect(udpSendThread_
		, SIGNAL(Signal_UpdateOfflineAddressList(QList<Client *> *))
		, this
		, SLOT(Slot_UpdateOfflineSocket(QList<Client *> *)));

	is_ok = connect(udpReceiveThread_
		, SIGNAL(Signal_UpdateAddressList(Client *))
		, this
		, SIGNAL(Signal_UpdateAddressList(Client *)));

}

void NetInterface::Slot_ReceivedMessage(MessageUnit *_messageUnit)
{
    emit Signal_ReceivedMessage(_messageUnit);
	/*  通知应用：收到新消息，取走  */
	emit Signal_UpdateUIReplyTcpMsg(_messageUnit);
	/*更新UI回复列表*/
}


MessageUnit * network_st::NetInterface::GetReceivedNewMessageUnit()
{
	return messageManager_->GetNewReceivedMessageUnit();
}

QList<Client *> * network_st::NetInterface::GetAllClient()
{
	return addressManager_->GetAllClient();
}

void network_st::NetInterface::AddMessageToSend(MessageUnit *_messageUnit)
{
	messageManager_->AppendSendedMessage(_messageUnit);			///<ui和队列同步增加操作
}

void network_st::NetInterface::RemoveSendMessage(char *_msg)
{
	messageManager_->RemoveSendMessage(_msg);

}

void network_st::NetInterface::AddClientAddress(Client *_client)
{
	addressManager_->AddClientAddress(_client);
}

void network_st::NetInterface::RemoveClientAddress(int _index)
{
	addressManager_->RemoveClientAddress(_index);
}

void network_st::NetInterface::Slot_UpdateOfflineSocket(QList<Client *> *_clients)
{
	int size_client_offline = _clients->size();
	for (int i = 0; i < size_client_offline; i++)
	{
		Client *client = _clients->at(i);
		QString ipv4 = client->ipv4;

		socketManager_->RemoveAcceptedTcpSocket(ipv4);
		//关闭并删除下线连接

		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(client->ipv4)
			.arg(" udp timeout(s): ")
			.arg(client->timeout);
		logManager_->AppendLog(logMessage);
		logManager_->OutLog();
		//输出udp异常日志
	}
}

