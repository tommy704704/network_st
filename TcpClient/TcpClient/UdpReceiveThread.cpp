#include "UdpReceiveThread.h"
#include "SocketManager.h"
#include "TcpReceiveThread.h"

using namespace network_st;

extern QString g_sender_ip;
extern QString g_server_ip;
extern QString g_local_ip;
UdpReceiveThread::UdpReceiveThread()
{
	Init();
}

UdpReceiveThread::~UdpReceiveThread()
{
	delete socketManager_;

	socketManager_ = NULL;

	delete udpSocket_heartbeat_receive_;			///<����

	udpSocket_heartbeat_receive_ = NULL;

	udpSendThread_->quit();

	udpSendThread_->wait();

	delete udpSendThread_;

	udpSendThread_ = NULL;
}

void UdpReceiveThread::Init()
{
	socketManager_ = SocketManager::GetInstance();

	udpSendThread_ = UdpSendThread::GetInstance();

	udpSocket_heartbeat_receive_ = new QUdpSocket(this);

	QHostAddress sender = udpSocket_heartbeat_receive_->localAddress();

	quint16 senderPort = udpSocket_heartbeat_receive_->localPort();

	QHostAddress sender_local(g_local_ip);
	
	/*�ͻ��˵�һ�ν���������������udp����
	����ȡ������ȷ�Ϸ���˵�ַ
	Ȼ���ٰ󶨷����	
	*/

	bool is_ok = udpSocket_heartbeat_receive_->bind(QHostAddress::Any, UDP_HEARTBEAT_CLIENT_PORT);		
	///<��UDP����

// 	is_ok = connect(udpSocket_heartbeat_receive_, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()));
}

void UdpReceiveThread::run()
{
	int timeout = 0;		///<�������������ʱʱ��		��
	while (true)
	{
		msleep(1000);

		timeout++;

		if (timeout > k_client_timeout)
		{
			emit Signal_DisconnectTcpFromHost(g_server_ip);
			//��ʱ���������
		}
		if (udpSocket_heartbeat_receive_->hasPendingDatagrams())
		{
			QByteArray datagram;

			datagram.resize(udpSocket_heartbeat_receive_->pendingDatagramSize());

			QHostAddress sender;

			quint16 senderPort;

			udpSocket_heartbeat_receive_->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

			QString text = QString(datagram);

			if (text.startsWith(k_reset)
				&& !text.startsWith(k_keepAlive))
			{
				/*�յ�����������������Ϣ*/
				emit Signal_DisconnectTcpFromHost(g_server_ip);
				//�����ӳ�ɾ�����ӣ�Ȼ������
			}
			else if (text.startsWith(k_keepAlive))
			{
				/*���������ѯ�ʰ�*/

				timeout = 0;
				//����

				if (!udpSendThread_->isRunning())
				{
					udpSendThread_->start();
				}

				if (g_server_ip == k_default_ip)
				{
					g_server_ip = sender.toString();
					emit Signal_GetServerAddress();
					//g_server_ip��ȡ����ܴ�tcp���շ���
				}
				else
				{					
					QTcpSocket *sendSocket = socketManager_->GetSendTcpSocketByIP(g_server_ip);

					if (!sendSocket)
					{
// 						socketManager_->ReCreateSendTcpSocket(g_server_ip);
						emit Signal_BindNewTcpConnection();
					}
				}

				QString msg = udpSendThread_->PackageReceiptMessage(text, true);
				//��װ��ִ����

// 				emit Signal_AddReceivedMessage(text);
				//��ӡ������
			}

		}
	}
}

void UdpReceiveThread::ReadPendingDatagrams()
{
}

