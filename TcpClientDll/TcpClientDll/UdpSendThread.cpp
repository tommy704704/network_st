#include "UdpSendThread.h"
#include <QDateTime>
using namespace network_st;

extern QString g_server_ip;
extern QString g_local_ip;
UdpSendThread *UdpSendThread::instance_ = nullptr;
UdpSendThread::UdpSendThread() : is_quit_(false)
{
	qDebug() << "UdpSendThread()";

	Init();
}

UdpSendThread::~UdpSendThread()
{
	mutex_.lock();
	is_quit_ = true;
	//if (queue_receipt_messages_)
	//	delete queue_receipt_messages_;		
	//	///<回执的消息队列
	//queue_receipt_messages_ = NULL;
	mutex_.unlock();

}

void UdpSendThread::EnqueueReceipt(QString _message)
{
	mutex_.lock();
	if (queue_receipt_messages_)
		queue_receipt_messages_->enqueue(_message);
	mutex_.unlock();
}

QString UdpSendThread::DequeueReceipt()
{
	mutex_.lock();
	QString result = "";
	if (queue_receipt_messages_)
		result = queue_receipt_messages_->dequeue();
	mutex_.unlock();
	return result;
}

QString UdpSendThread::PackageReceiptMessage(QString _message, bool _is_heartbeat)
{
	///<添加回执消息

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

	return "";
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

	//udpSocket_heartbeat_send_ = new QUdpSocket(this);
}

void UdpSendThread::run()
{
	udpSocket_heartbeat_send_ = new QUdpSocket(this);
	///<如收到心跳监测询问包，则要定期回复，告知服务器，客户端在线
	while (!is_quit_)
	{
		//msleep(1000);
		msleep(1);
		if (is_quit_)
		{
			///<因为析构时，线程还没有停止仍在执行，此时run内多处需要判断。
			///<已经进入析构状态，所以线程执行的业务逻辑应依据is_quit_判断退出，
			///<所以加is_quit_判断
			goto end;
			//return;
		}

		if (!udpSocket_heartbeat_send_
			|| !queue_receipt_messages_)
		///<没有回复消息
		{
			continue;
		}

		int size = queue_receipt_messages_->size();

		for (int i = 0; i < size; i++)
		{
			if (is_quit_)
			{
				goto end;
				//return;
			}

			QString receipt_msg = DequeueReceipt();
			///<取出将发出的回复消息，并删除缓存

			if (receipt_msg.startsWith(k_receipt_keepAlive))
			{
				///<回复心跳包

				QString msg = k_receipt_keepAlive;

				int size_msg = msg.size();

				QHostAddress server_address(g_server_ip);

				if (udpSocket_heartbeat_send_ && !is_quit_)
				{
					///<输出收到心跳询问回执包
					qint64 sended_bytes = udpSocket_heartbeat_send_->writeDatagram(
						msg.toLocal8Bit().constData()
						, size_msg
						, server_address
						, UDP_HEARTBEAT_SERVER_PORT);
					///<回执心跳包

					if (GetOutDebug())
					{
						qDebug() << QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz")
							<< ":.ark_heart."
							<< "===>"
							<< g_server_ip;
					}
				}

			}
			else
			{
				//int size_msg = receipt_msg.size();
				//QHostAddress server_address(g_server_ip);
				//if (udpSocket_heartbeat_send_)
				//	qint64 sended_bytes = udpSocket_heartbeat_send_->writeDatagram(receipt_msg.toLocal8Bit().constData()
				//															, size_msg
				//															, server_address
				//															, UDP_HEARTBEAT_SERVER_PORT);
			}
		}
	}

end:
	if (udpSocket_heartbeat_send_)
	{
		//udpSocket_heartbeat_send_->close();
		udpSocket_heartbeat_send_->disconnectFromHost();
		udpSocket_heartbeat_send_->waitForDisconnected();
		delete udpSocket_heartbeat_send_;
		udpSocket_heartbeat_send_ = NULL;

		///<线程对象析构在线程里清理，否则会出现跨线程无法传递关闭消息，也会出现析构了但是线程还有执行出现异常
		if (queue_receipt_messages_)
		{
			delete queue_receipt_messages_;
			///<回执的消息队列
		}
		queue_receipt_messages_ = NULL;
		//delete this;
	}

}

