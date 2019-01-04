#include "TcpSendThread.h"
#include "MessageManager.h"
#include "SocketManager.h"

using namespace network_st;

TcpSendThread *TcpSendThread::instance_ = nullptr;

network_st::TcpSendThread::~TcpSendThread()
{
	delete tcpSocket_client_;

	tcpSocket_client_ = NULL;

	delete messageManager_;

	messageManager_ = NULL;

	delete socketManager_;

	socketManager_ = NULL;

}

void network_st::TcpSendThread::Slot_SendMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();

	ipv4_ = _messageUnit->ip;

	mutex_.unlock();
}

network_st::TcpSendThread::TcpSendThread()
{
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
	while (1)
	{
		mutex_.lock();

		MessageUnit *messageUnit_send = messageManager_->GetSendingMessage();

		if (messageUnit_send)
		{
			tcpSocket_client_ = socketManager_->GetSendTcpSocketByIP(messageUnit_send->ip);

			if (tcpSocket_client_)
			{
// 				qint64 success_sended = tcpSocket_client_->write(messageUnit_send->msg, strlen(messageUnit_send->msg));
				MessageUnit messageUnit_head = PackageMessage(messageUnit_send);
				//���ͷ������

				qint64 success_sended = tcpSocket_client_->write(*messageUnit_head.byteArray_msg);

				bool is_written = tcpSocket_client_->waitForBytesWritten();

				Signal_UpdateUITcpReplyMessage(messageUnit_send);
				/*֪ͨUI*/
			}
		}
// 		if (ipv4_ != "")
// 		{
// 			tcpSocket_client_ = socketManager_->GetSendTcpSocketByIP(ipv4_);
// 			/*��ȡ����*/
// 			if (tcpSocket_client_)
// 			{
// 				MessageUnit *messageUnit_send = messageManager_->GetSendingMessage();
// 				qint64 success_sended = tcpSocket_client_->write(messageUnit_send->msg, strlen(messageUnit_send->msg));
// 				bool is_written = tcpSocket_client_->waitForBytesWritten();
// 				ipv4_ = "";
// 				/*����*/
// 				Signal_UpdateUITcpReplyMessage(messageUnit_send);
// 				/*֪ͨUI*/
// 			}
// 		}
		mutex_.unlock();
	}
}
