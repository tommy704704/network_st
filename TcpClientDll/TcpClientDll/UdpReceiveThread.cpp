#include "UdpReceiveThread.h"
#include "AddressManager.h"
#include "SocketManager.h"
#include "TcpReceiveThread.h"

#include <QDateTime>

using namespace network_client_st;

extern QString g_server_ip;
extern QString g_local_ip;
UdpReceiveThread::UdpReceiveThread() : is_quit_(false),
is_first_connecting_(true)
{
	qDebug() << "UdpReceiveThread()";

	Init();
}

UdpReceiveThread::~UdpReceiveThread()
{
	is_quit_ = true;

	mutex_.lock();

	delete udpSocket_heartbeat_receive_;			///<心跳

	udpSocket_heartbeat_receive_ = NULL;

	mutex_.unlock();

	wait();
}

void UdpReceiveThread::Init()
{
	addressManager_ = AddressManager::GetInstance();
	socketManager_ = SocketManager::GetInstance();

	udpSendThread_ = UdpSendThread::GetInstance();

	udpSocket_heartbeat_receive_ = new QUdpSocket(this);

	QHostAddress sender = udpSocket_heartbeat_receive_->localAddress();

	quint16 senderPort = udpSocket_heartbeat_receive_->localPort();

	QHostAddress sender_local(g_local_ip);
	
	///<客户端第一次接收所有其他机器udp数据
	///<，获取心跳包确认服务端地址
	///<然后再绑定服务端	
	

	bool is_ok = udpSocket_heartbeat_receive_->bind(QHostAddress::Any, /*UDP_HEARTBEAT_CLIENT_PORT*/k_udp_heart_client_port_);
	///<打开UDP连接

// 	is_ok = connect(udpSocket_heartbeat_receive_, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()));
}

void UdpReceiveThread::run()
{
	QString ipv4_peer = k_default_ip;
	///<udp对端的ipv4
	int timeout = 0;
	///<与服务器心跳超时时间		单位：秒
	while (!is_quit_)
	{
		msleep(1000);
 		timeout++;
		
		addressManager_->UpdateServerTimeout();
		///<更新所有服务端缓存的超时时长

		if (timeout > GetTimeout())
		{
			emit Signal_DisconnectTcpFromHost(g_server_ip);
			///<超时后清掉连接
		}
		if (udpSocket_heartbeat_receive_ &&
			udpSocket_heartbeat_receive_->hasPendingDatagrams())
		///<收到来自服务端心跳包
		{
			QByteArray datagram;

			if (udpSocket_heartbeat_receive_)
			{
				datagram.resize(udpSocket_heartbeat_receive_->pendingDatagramSize());
				///<设置缓存大小
			}
			else
			{
				continue;
			}

			QHostAddress sender;

			quint16 senderPort;

			if (!is_quit_ && udpSocket_heartbeat_receive_)
			{
				udpSocket_heartbeat_receive_->readDatagram(datagram.data()
					, datagram.size()
					, &sender
					, &senderPort);
				///<接收udp包
				ipv4_peer = QHostAddress(sender.toIPv4Address()).toString();

				Server *server = new Server();
				server->ipv4 = ipv4_peer;
				server->timeout = 0;
				server->is_online = true;
				///<更新所有在线服务端
				addressManager_->UpdateServerState(server);

				if (ipv4_peer != g_server_ip)
				///<没有获取到正确的对端ip，此时接收到的udp是干扰包，要丢弃
				{
					continue;
				}
				udpSocket_heartbeat_receive_->flush();
				///<清除缓存中多余的包，当服务器关闭时候，还会收到未处理的包，应丢弃
			}
			else
			{
				continue;
			}
			QString text = QString(datagram);

			if (text.startsWith(k_reset)
				&& !text.startsWith(k_keepAlive))
			{
				///<收到服务器连接重置消息
				emit Signal_DisconnectTcpFromHost(g_server_ip);
				///<从连接池删除连接，然后重连
			}
			else if (text.startsWith(k_keepAlive))
			{
				///<服务端心跳询问包

				timeout = 0;
				///<收到心跳就要，重置超时记录标志

				if (udpSendThread_ && !udpSendThread_->isRunning())
				{
					udpSendThread_->start();
					///<启动心跳回执线程
				}

				if (g_server_ip == k_default_ip 
					|| is_first_connecting_)
				{
					is_first_connecting_ = false;
					///<客户端实例之前设置服务器ip，此时仍需要执行这个条件内代码，进行初次连接。
					if (k_default_ip == g_server_ip)
					///<服务器ip是默认初始值
					{
						g_server_ip = ipv4_peer;
						///<获取连接的服务器ip
					}

					emit Signal_GetServerAddress();
					///<g_server_ip获取后才能打开tcp接收服务
				}
				else
				{					
					QTcpSocket *sendSocket = socketManager_->GetSendTcpSocketByIP(g_server_ip);

					if (!sendSocket)
					{
// 						socketManager_->ReCreateSendTcpSocket(g_server_ip);
						emit Signal_BindNewTcpConnection();
						///<reconnect
					}
				}

				QString msg = udpSendThread_->PackageReceiptMessage(text, true);
				///<组装回执心跳
				if (GetOutDebug())
				{
					qDebug() << QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz")
						<< ":.heart."
						<< "<==="
						<< g_server_ip;
					///<收到心跳询问包
				}

// 				emit Signal_AddReceivedMessage(text);
				///<打印心跳包
			}

		}
	}
//end:
//	if (udpSocket_heartbeat_receive_)
//	{
//		udpSocket_heartbeat_receive_->disconnectFromHost();
//		udpSocket_heartbeat_receive_->waitForDisconnected();
//		delete udpSocket_heartbeat_receive_;
//		udpSocket_heartbeat_receive_ = NULL;
//
//	}

}

void UdpReceiveThread::ReadPendingDatagrams()
{
}

