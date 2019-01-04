#include "UdpSendThread.h"
using namespace network_st;

UdpSendThread *UdpSendThread::s_instance_ = nullptr;

extern QString g_local_ip;

extern QString g_sender_ip;

UdpSendThread::UdpSendThread() : is_quit_(false)
{
	qDebug() << "UdpSendThread()";

	Init();
}

UdpSendThread::~UdpSendThread()
{
	is_quit_ = true;

	wait();

	mutex_.lock();

	//udpSocket_send_heartbeat_->close();

	//delete udpSocket_send_heartbeat_;

	//udpSocket_send_heartbeat_ = NULL;

	mutex_.unlock();

}

void UdpSendThread::Init()
{
	addressManager_ = AddressManager::GetInstance();

	socketManager_ = SocketManager::GetInstance();

	udpSocket_send_heartbeat_ = new QUdpSocket();

	g_local_ip = GetLocalIP();

	QHostAddress server_address(g_local_ip);

}

void UdpSendThread::BroadcastAllOnlineClient()
{
	mutex_.lock();

	if (udpSocket_send_heartbeat_)
	{
		QString msg = k_keepAlive;

		int size_msg = msg.size();

		qint64 sended_bytes = udpSocket_send_heartbeat_->writeDatagram(msg.toLocal8Bit().constData(),
			size_msg,
			QHostAddress::Broadcast,
			UDP_HEARTBEAT_CLIENT_PORT);
	}

	mutex_.unlock();
}

void UdpSendThread::run()
{
	int num_keepAlive = 0;

	while (!is_quit_)
	{
		msleep(1000);
		//定期发送查询报文，如收到客户端回执则判定其在线，如果30秒没有收到回执则认为不在线

		num_keepAlive++;

		if (num_keepAlive >= 3)
		{
			NoticeClientClearTcpConnect();
			//通知客户端清除连接，因为服务端已清除

			BroadcastAllOnlineClient();
			//心跳广播

			num_keepAlive = 0;
			//重置

			//mutex_.lock();

			QList<Client *> * list_offline_client = addressManager_->UpdateClientTimeout();
			//广播同步并更新超时

			if (list_offline_client->size() > 0)
			{
				emit Signal_UpdateOfflineAddressList(list_offline_client);
				//通知UI修改下线客户端状态
			}

			//mutex_.unlock();
		}
	}
}

void network_st::UdpSendThread::NoticeClientClearTcpConnect()
{

	int size = addressManager_->GetAllClientSize();

	for (int i = 0; i < size; i++)
	{
		Client *client = addressManager_->GetClientByIndex(i);

		QString ipv4 = client->ipv4;

		QTcpSocket *tcpSocket_accepted = socketManager_->GetAcceptedTcpSocketByIP(ipv4);

		if (!tcpSocket_accepted)
		{
			//mutex_.lock();
			//通知客户端清除该连接，因为服务端已无该连接
			QString msg = k_reset;

			int size_msg = msg.size();

			QHostAddress client_address(ipv4);

			qint64 sended_bytes = udpSocket_send_heartbeat_->writeDatagram(msg.toLocal8Bit().constData()
																		, size_msg
																		, client_address
																		, UDP_HEARTBEAT_CLIENT_PORT);

			//mutex_.unlock();
		}
	}

}

