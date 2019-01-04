#include "TcpSendThread.h"
#include "MessageManager.h"
#include "SocketManager.h"

using namespace network_st;

TcpSendThread *TcpSendThread::instance_ = nullptr;

network_st::TcpSendThread::~TcpSendThread()
{
	is_quit_ = true;

	mutex_.lock();

	if (tcpSocket_client_)
	{
		delete tcpSocket_client_;

		tcpSocket_client_ = NULL;
	}

	mutex_.unlock();

	wait();

}

void network_st::TcpSendThread::Slot_SendMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();

	ipv4_ = _messageUnit->ip;

	mutex_.unlock();
}

network_st::TcpSendThread::TcpSendThread() : is_quit_(false),
											tcpSocket_client_(nullptr)
{
	qDebug() << "TcpSendThread()";

	Init();
}

void network_st::TcpSendThread::CreateSignalAndSlot()
{

}

void network_st::TcpSendThread::Init()
{
	ipv4_ = "";

	messageManager_ = MessageManager::GetInstance();

	socketManager_ = SocketManager::GetInstance();
}

void network_st::TcpSendThread::run()
{
	while (!is_quit_)
	{
		//msleep(1000);
		msleep(1);
		//mutex_.lock();
		
		MessageUnit *messageUnit_send = messageManager_->GetSendingMessage();

		if (messageUnit_send)
		{
			tcpSocket_client_ = socketManager_->GetSendTcpSocketByIP(messageUnit_send->ip);
			qDebug() << "tcpSocket_client_: " << tcpSocket_client_;

			if (tcpSocket_client_)
			{
// 				qint64 success_sended = tcpSocket_client_->write(messageUnit_send->msg, strlen(messageUnit_send->msg));
				MessageUnit messageUnit_head = PackageMessage(messageUnit_send);
				//打包头部发送
				qDebug() << "message will send to server ip: " << messageUnit_send->ip;
				qDebug() << "message will send to server: " << *(messageUnit_send->byteArray_msg);

				qint64 success_sended = tcpSocket_client_->write(*messageUnit_head.byteArray_msg);
				qDebug() << "message sended successful bytes: " << success_sended;

				bool is_written = tcpSocket_client_->waitForBytesWritten();
				qDebug() << "message is_written: " << is_written;

				Signal_UpdateUITcpReplyMessage(messageUnit_send);
				/*通知UI*/
			}
		}
		//mutex_.unlock();
	}
}
