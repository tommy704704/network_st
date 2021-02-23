#include "TcpSendThread.h"
#include <QException> 
#include "NewTcpServer.h"
using namespace network_server_st;

TcpSendThread *TcpSendThread::instance_ = NULL;
TcpSendThread::TcpSendThread(QObject *parent) : QThread(parent)
{
	qDebug() << "TcpSendThread()";

    Init();
}

TcpSendThread::~TcpSendThread()
{
	is_quit_ = true;

	//delete k_tcpServer_;
	//k_tcpServer_ = NULL;
	
	wait();
}

void TcpSendThread::Init()
{
	addressManager_ = AddressManager::GetInstance();

	messageManager_ = MessageManager::GetInstance();

	socketManager_ = SocketManager::GetInstance();

	NewTcpServer::GetInstance();
}

//NewTcpServer *tcpServer_ = NULL;
void TcpSendThread::run()
{
	//tcpServer_ = NewTcpServer::GetInstance();

// 	socketManager_ = new SocketManager();
	/* 发送线程单独维护一个连接池，只包含所有的发送连接 */
	while (!is_quit_)
    {
		//msleep(1000);
		msleep(1);

		mutex_.lock();

		int size_message = messageManager_->GetSizeSendingMessage();

		for (int i = 0; i < size_message; i++)
        {
			///<已指定接收方ip，则单独发送，否则广播
			MessageUnit *messageUnit = messageManager_->GetSendingMessage();

			QString ipv4 = messageUnit->ip;
			qDebug() << "message will send to client by ip :" << ipv4;

			if (ipv4 != k_default_ip && ipv4 != "")
			{
				SendMessageTcp(ipv4);
				qDebug() << "SendMessageTcp() by only one client ip: " << ipv4;
			}
			else if (k_default_ip == ipv4 || "" == ipv4)
			{
				/*广播给所有在线客户端*/

				int size_client = addressManager_->GetAllClientSize();

				bool is_sended = false;

				qDebug() << "SendMessageTcp() by broadcast, client size: " << size_client;
				for (int j = 0; j < size_client; j++)
				{
					Client *client = addressManager_->GetClientByIndex(j);

					QString ipv4 = client->ipv4;

					if (client->is_online)
					{
// 	 					this->msleep(100);
						is_sended &= SendMessageTcp(ipv4);
						qDebug() << "SendMessageTcp() by broadcast, each client ip: " << ipv4;
					}
				}
			}

			messageManager_->RemoveSendedMessage();
			/*全部客户端发送后，删除队列已发送的消息*/
		}

		mutex_.unlock();
	}
}

bool TcpSendThread::SendMessageTcp(const QString _ipv4)
{
	MessageUnit *messageUnit = messageManager_->GetSendingMessage();
    /*取队列头，发送后删除*/

	QTcpSocket *sendSocket = NULL;

	sendSocket = socketManager_->GetAcceptedTcpSocketByIP(_ipv4);

	if (!sendSocket)
	{
		return false;
	}
	else if (sendSocket->isValid() && sendSocket->isWritable())
	{
		int state = sendSocket->state();

		if (QAbstractSocket::ConnectedState == state)
		{
// 			qint64 success_sended = sendSocket->write(messageUnit->msg, strlen(messageUnit->msg));
			MessageUnit messageUnit_head = PackageMessage(messageUnit);

			qint64 success_sended = sendSocket->write(*messageUnit_head.byteArray_msg);
			bool is_written = false;
			try
			{
				if (sendSocket != NULL)
				{
					//throw "error";
					is_written = sendSocket->waitForBytesWritten();
					qDebug() << "socket write data to " << _ipv4 << " ====> " << is_written;
				}

			}
			catch (QException  &e)
			{
				qDebug() << "socket write data to " << _ipv4 << " ====> " << is_written << " exception ";
				
			}
			catch (...)
			{
				qDebug() << "socket write data to " << _ipv4 << " ====> " << is_written << " exception... ";
			}
			return true;
		}
	}
	return false;

// 	QTcpSocket *sendSocket_current = new QTcpSocket();
// 	bool is_ok = sendSocket_current->setSocketDescriptor(socketDescriptor_);

// 	socketManager_->AppendAccpetedTcpSocket(sendSocket_current);
//     sendSocket->write(messageUnit->msg);

// 	QByteArray block;		
// 	//用于暂存我们要发送的数据
// 	QDataStream out(&block, QIODevice::WriteOnly);
// 	//使用数据流写入数据
// 
// 	out.setVersion(QDataStream::Qt_5_4);
// 	//设置数据流的版本，客户端和服务器端使用的版本要相同
// 
// 	out << (quint16)0;
// 	/*占位*/
//   	QString msg = QString::fromLocal8Bit(messageUnit->msg);
//  out << messageUnit->msg;
// 	out << msg;
// 	/*写入消息内容*/
// 	out.device()->seek(0);
// 	/*回头*/
// 	quint16 message_bytes = (quint16)(block.size() - sizeof(quint16));
// 	/*消息大小*/
// 	out << message_bytes;
// 	qint64 success_sended = sendSocket->write(block);
}

void network_server_st::TcpSendThread::Slot_NewConnection()
{
	//QTcpSocket *acceptedSocket = tcp_server_->nextPendingConnection();

	//socketManager_->AppendAccpetedTcpSocket(acceptedSocket);

	//没有用到
}

