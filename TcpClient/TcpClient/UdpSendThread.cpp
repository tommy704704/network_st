#include "UdpSendThread.h"
using namespace network_st;

extern QString g_sender_ip;
extern QString g_server_ip;
extern QString g_local_ip;
UdpSendThread *UdpSendThread::instance_ = nullptr;
UdpSendThread::UdpSendThread()
{
	Init();
}

UdpSendThread::~UdpSendThread()
{
	delete queue_receipt_messages_;		///<回执的消息队列

	queue_receipt_messages_ = NULL;

	delete udpSocket_heartbeat_send_;

	udpSocket_heartbeat_send_ = NULL;

}

void UdpSendThread::EnqueueReceipt(QString _message)
{
	mutex_.lock();
	queue_receipt_messages_->enqueue(_message);
	mutex_.unlock();
}

QString UdpSendThread::DequeueReceipt()
{
	mutex_.lock();
	QString result = queue_receipt_messages_->dequeue();
	mutex_.unlock();
	return result;
}

QString UdpSendThread::PackageReceiptMessage(QString _message, bool _is_heartbeat)
{
	/*添加回执消息*/

	if (_is_heartbeat)
	{
		QString receipt_msg = k_receipt_keepAlive;

		EnqueueReceipt(receipt_msg);

		return receipt_msg;
	}
	else if (_message.startsWith(k_reset))
	{
// 		QString receipt_msg = QString("%1%2").arg("Ark_").arg(_message);
		QString receipt_msg = k_receipt_reset;

		EnqueueReceipt(receipt_msg);

		return receipt_msg;
	}
}

QString UdpSendThread::GetQueueValueByIndex(int _index)
{
	QString value = "";

	mutex_.lock();

	if (!queue_receipt_messages_->isEmpty())
	{
		value = queue_receipt_messages_->at(_index);
	}

	mutex_.unlock();

	return value;
}

QString UdpSendThread::GetQueueLastValue()
{
	QString value = "";

	mutex_.lock();

	if (!queue_receipt_messages_->isEmpty())
	{
		value = queue_receipt_messages_->last();
	}

	mutex_.unlock();

	return value;
}

void UdpSendThread::Init()
{
	queue_receipt_messages_ = new QQueue<QString>();

	udpSocket_heartbeat_send_ = new QUdpSocket(this);
}

void UdpSendThread::run()
{
	/*如收到心跳监测询问包，则要定期回复，告知服务器，客户端在线*/

	while (1)
	{
		msleep(1000);

		int size = queue_receipt_messages_->size();

		for (int i = 0; i < size; i++)
		{
			QString receipt_msg = DequeueReceipt();

			if (receipt_msg.startsWith(k_receipt_keepAlive))
			{
				/*回复心跳包*/

				QString msg = k_receipt_keepAlive;

				int size_msg = msg.size();

				QHostAddress sender_local(g_sender_ip);

				QHostAddress server_address(g_server_ip);

				qint64 sended_bytes = udpSocket_heartbeat_send_->writeDatagram(msg.toLocal8Bit().constData()
																			, size_msg
																			, server_address
																			, UDP_HEARTBEAT_SERVER_PORT);
				/*回执心跳包*/
			}
			else
			{
				int size_msg = receipt_msg.size();

				QHostAddress sender_local(g_sender_ip);

				QHostAddress server_address(g_server_ip);

				qint64 sended_bytes = udpSocket_heartbeat_send_->writeDatagram(receipt_msg.toLocal8Bit().constData()
																			, size_msg
																			, server_address
																			, UDP_HEARTBEAT_SERVER_PORT);
			}
		}
	}
}

