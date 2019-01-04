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

	delete udpSocket_heartbeat_receive_;			///<心跳

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
	
	/*客户端第一次接收所有其他机器udp数据
	，获取心跳包确认服务端地址
	然后再绑定服务端	
	*/

	bool is_ok = udpSocket_heartbeat_receive_->bind(QHostAddress::Any, UDP_HEARTBEAT_CLIENT_PORT);		
	///<打开UDP连接

// 	is_ok = connect(udpSocket_heartbeat_receive_, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()));
}

void UdpReceiveThread::run()
{
	int timeout = 0;		///<与服务器心跳超时时间		秒
	while (true)
	{
		msleep(1000);

		timeout++;

		if (timeout > k_client_timeout)
		{
			emit Signal_DisconnectTcpFromHost(g_server_ip);
			//超时后清掉连接
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
				/*收到服务器连接重置消息*/
				emit Signal_DisconnectTcpFromHost(g_server_ip);
				//从连接池删除连接，然后重连
			}
			else if (text.startsWith(k_keepAlive))
			{
				/*服务端心跳询问包*/

				timeout = 0;
				//重置

				if (!udpSendThread_->isRunning())
				{
					udpSendThread_->start();
				}

				if (g_server_ip == k_default_ip)
				{
					g_server_ip = sender.toString();
					emit Signal_GetServerAddress();
					//g_server_ip获取后才能打开tcp接收服务
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
				//组装回执心跳

// 				emit Signal_AddReceivedMessage(text);
				//打印心跳包
			}

		}
	}
}

void UdpReceiveThread::ReadPendingDatagrams()
{
}

