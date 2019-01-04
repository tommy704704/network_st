#include "UdpReceiveThread.h"
#include "Global.h"

#include <QDateTime>
using namespace network_st;
UdpReceiveThread *UdpReceiveThread::instance_ = nullptr;

extern QString g_local_ip;
extern QString g_sender_ip;
UdpReceiveThread::UdpReceiveThread() : is_quit_(false)
{
	qDebug() << "UdpReceiveThread()";

    Init();
}

UdpReceiveThread::~UdpReceiveThread()
{
	is_quit_ = true;
	mutex_.lock();

	//delete list_clients_;

	//list_clients_ = NULL;
	///<list_clients_在此对象内就是AddressManager的实例，所以在addressManager里delete

	delete udpSocket_receive_heartbeat_;

	udpSocket_receive_heartbeat_ = NULL;

	mutex_.unlock();

	wait();
}

QList<Client *> * UdpReceiveThread::GetOnlineClient()
{
	mutex_.lock();

    Client *client = new Client();

    client->ipv4 = GetLocalIP();

    list_clients_->clear();

    list_clients_->append(client);

	mutex_.unlock();

	return list_clients_;
}


void UdpReceiveThread::Init()
{
    addressManager_ = AddressManager::GetInstance();

    list_clients_ = addressManager_->GetAllClient();

	udpSocket_receive_heartbeat_ = new QUdpSocket(this);

    g_local_ip = GetLocalIP();

    QHostAddress server_address(g_local_ip);
    ///<接收客户端心跳回执

	bool is_ok = udpSocket_receive_heartbeat_->bind(QHostAddress::Any/*server_address*/, UDP_HEARTBEAT_SERVER_PORT);
	///<打开UDP连接

}

void UdpReceiveThread::run()
{
	while (!is_quit_)
    {
		//msleep(1000);
		///<会导致udp报文丢失，无法实时性检测到学生端
		///<接收客户端心跳回执
        if (udpSocket_receive_heartbeat_ &&
			udpSocket_receive_heartbeat_->hasPendingDatagrams())
        {
			//mutex_.lock();
			QByteArray datagram;

            datagram.resize(udpSocket_receive_heartbeat_->pendingDatagramSize());
			///<设置接收缓存，避免有数据被丢弃

            QHostAddress sender;

            quint16 senderPort;

            udpSocket_receive_heartbeat_->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

            QString text = QString(datagram);

            if (text.startsWith(k_receipt_keepAlive))
            {
				///<客户端心跳回执

                //QString ip = sender.toString();
				QString ip = QHostAddress(sender.toIPv4Address()).toString();

                Client *client = new Client();

                client->ipv4 = ip;

				client->timeout = 0;

				client->is_online = true;
				///<收到心跳回执 超时重置

                addressManager_->UpdateClientState(client);
				///<更新地址 cache

				if (GetOutDebug())
				{
					qDebug() << QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz")
						<< ":.ark_heart."
						<< "<==="
						<< ip;
					///<收到心跳回执包
				}
				//emit Signal_UpdateAddressList(client);
				///<通知更新地址列表
			}
			//mutex_.unlock();
		}
		msleep(1);
    }
}
