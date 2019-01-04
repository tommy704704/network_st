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
		//���ڷ��Ͳ�ѯ���ģ����յ��ͻ��˻�ִ���ж������ߣ����30��û���յ���ִ����Ϊ������

		num_keepAlive++;

		if (num_keepAlive >= 3)
		{
			NoticeClientClearTcpConnect();
			//֪ͨ�ͻ���������ӣ���Ϊ����������

			BroadcastAllOnlineClient();
			//�����㲥

			num_keepAlive = 0;
			//����

			//mutex_.lock();

			QList<Client *> * list_offline_client = addressManager_->UpdateClientTimeout();
			//�㲥ͬ�������³�ʱ

			if (list_offline_client->size() > 0)
			{
				emit Signal_UpdateOfflineAddressList(list_offline_client);
				//֪ͨUI�޸����߿ͻ���״̬
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
			//֪ͨ�ͻ�����������ӣ���Ϊ��������޸�����
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

