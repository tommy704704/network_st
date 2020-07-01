#include "TcpReceiveThread.h"

#include <QDebug>

using namespace network_server_st;

TcpReceiveThread *TcpReceiveThread::instance_ = NULL;
TcpReceiveThread::TcpReceiveThread() : is_quit_(false)
{
	qDebug() << "TcpReceiveThread()";


    Init();
}

TcpReceiveThread::~TcpReceiveThread()
{
	is_quit_ = true;

	mutex_.lock();

	//delete accept_tcpSocket_;

	//accept_tcpSocket_ = NULL;

	//delete accept_udpSocket_;

	//accept_udpSocket_ = NULL;

	mutex_.unlock();

	wait();
}

void TcpReceiveThread::Init()
{
	messageManager_ = MessageManager::GetInstance();

    socketManager_ = SocketManager::GetInstance();

	accept_tcpSocket_ = new QTcpSocket();

	accept_udpSocket_ = new QUdpSocket();

}

void TcpReceiveThread::run()
{
    exec();
}

void TcpReceiveThread::Slot_ReadyRead()
{
	qDebug() << "Slot_ReadyRead()";

	mutex_.lock();

    QByteArray byteArray_receive;

    QString msg = "";

	QString client_ip = "";

    MessageUnit *messageUnit = new MessageUnit();

    QTcpSocket *acceptedSocket = qobject_cast<QTcpSocket *>(sender());

	if (!acceptedSocket)
	{
		mutex_.unlock();
		qDebug() << "acceptedSocket: " << acceptedSocket;

		return;
	}
	else if (acceptedSocket->isValid() && acceptedSocket->isReadable())
	{
		qint64 size = acceptedSocket->readBufferSize();
		//client_ip = acceptedSocket->peerAddress().toString();
		client_ip = GetPeerAddressIpv4(acceptedSocket);
		qDebug() << "message received from client ip: " << client_ip;


		byteArray_receive = acceptedSocket->readAll();
		qDebug() << "message received from client, byteArray_receive: " << byteArray_receive
			<< " Slot_ReadMessage received message size: " << byteArray_receive.size();
		//读取缓冲区数据
// 		messageUnit->ip = client_ip;

		if (!byteArray_receive.isEmpty())
		{
// 			msg += tr(byteArray_receive);

// 			QByteArray *bytes_receiveMsg = new QByteArray(msg.toLocal8Bit());

			QString message = QString::fromLocal8Bit(byteArray_receive.data());

// 			QStringList list_messages = UnpackMessage(message);
			QList<MessageUnit *> * list_messages = UnpackMessage(byteArray_receive, client_ip);
			//拆解消息包头，解决多条消息缓冲区一起取出来，消息融合的问题

// 			int size = list_messages.size();
			int size = list_messages->size();
			qDebug() << "message sizes: " << size;

			for (int i = 0; i < size; i++)
			{
// 				QString message_each = list_messages.at(i);
				MessageUnit * message_each = list_messages->at(i);

// 				QByteArray *byteArray_msg = new QByteArray(message_each.toLocal8Bit());

// 				messageUnit->byteArray_msg = byteArray_msg;

// 				messageUnit->msg = bytes_receiveMsg->data();
// 				messageUnit->msg = byteArray_msg->data();
				//添加接收的消息到队列

				message_each->ip = client_ip;

				messageManager_->AppendReceivedMessage(message_each);
				//通知应用 消息队列收到新消息
				qDebug() << "AppendReceivedMessage() by client ip: " << client_ip;


				emit Signal_ReceivedMessage(message_each);
			}
		}
	}
	mutex_.unlock();
}


