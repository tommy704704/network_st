#include "TcpReceiveThread.h"
#include <QHostAddress>
#include "MessageManager.h"
#include "SocketManager.h"

using namespace network_st;

TcpReceiveThread *TcpReceiveThread::instance_ = nullptr;

extern QString g_server_ip;

network_st::TcpReceiveThread::~TcpReceiveThread()
{

	delete messageManager_;

	messageManager_ = NULL;
	
	delete socketManager_;

	socketManager_ = NULL;

}

void network_st::TcpReceiveThread::Slot_ReadMessage()
{
	QTcpSocket *tcpSocket_sended = socketManager_->GetSendTcpSocketByIP(g_server_ip);

	if (!tcpSocket_sended)
	{
		return;
	}

	QByteArray byteArray_message = tcpSocket_sended->readAll();

	qDebug() << byteArray_message;

// 	QString message = QString::fromLocal8Bit(byteArray_message.data());

	QList<MessageUnit *> * list_messages = UnpackMessage(byteArray_message);
	//拆解消息包头，解决多条消息缓冲区一起取出来，消息融合的问题

	int size = list_messages->size();

	for (int i = 0; i < size; i++)
	{
		MessageUnit * messageUnit_each = list_messages->at(i);

		QString ipv4 = tcpSocket_sended->peerAddress().toString();

		messageUnit_each->ip = ipv4;

		messageManager_->AppendReceivedMessage(messageUnit_each);
		/*缓存接收的消息*/

		emit Signal_UpdateUITcpReceivedMessage(messageUnit_each);
		/*通知UI已收到消息*/

	}
}


network_st::TcpReceiveThread::TcpReceiveThread()
{
	Init();
}

void network_st::TcpReceiveThread::CreateSignalAndSlot()
{
}

void network_st::TcpReceiveThread::Init()
{
	blockSize_ = 0;			///<初始化其为0

	messageManager_ = MessageManager::GetInstance();

	socketManager_ = SocketManager::GetInstance();

}

void network_st::TcpReceiveThread::run()
{
	exec();
}
