#include "SocketManager.h"
using namespace network_client_st;
SocketManager *SocketManager::instance_ = NULL;
SocketManager::~SocketManager()
{
	mutex_.lock();

	delete map_sended_tcpSocket_;

	map_sended_tcpSocket_ = NULL;

	delete map_accepted_tcpSocket_;

	map_accepted_tcpSocket_ = NULL;
	
	delete map_sended_udpSocket_;

	map_sended_udpSocket_ = NULL;
	
	delete map_accepted_udpSocket_;

	map_accepted_udpSocket_ = NULL;

	mutex_.unlock();
}

QTcpSocket * SocketManager::GetSendTcpSocketByIP(QString _ip)
{
	mutex_.lock();
    QTcpSocket *sendSocket = NULL;
    if(!map_sended_tcpSocket_->contains(_ip))
    {
		mutex_.unlock();
		return NULL;
	}
    else
    {
        sendSocket = map_sended_tcpSocket_->value(_ip);
    }
	mutex_.unlock();
    return sendSocket;
}

QUdpSocket * SocketManager::GetSendUdpSocketByIP(QString _ip)
{
	mutex_.lock();

	QUdpSocket *sendSocket = NULL;
	if (!map_sended_udpSocket_->contains(_ip))
	{
		sendSocket = new QUdpSocket();
		sendSocket->connectToHost(_ip, /*UDP_HEARTBEAT_SERVER_PORT*/k_udp_heart_server_port_);
		map_sended_udpSocket_->insert(_ip, sendSocket);
	}
	else
	{
		sendSocket = map_sended_udpSocket_->value(_ip);
	}

	mutex_.unlock();

	return sendSocket;
}

QTcpSocket * SocketManager::GetAcceptedTcpSocketByIP(QString _ip)
{
	mutex_.lock();
    QTcpSocket *acceptedSocket = NULL;
    if(!map_accepted_tcpSocket_->contains(_ip))
    {
        acceptedSocket = new QTcpSocket();
		acceptedSocket->connectToHost(_ip, /*TCP_SERVER_PORT*/k_tcp_server_port_);
        map_accepted_tcpSocket_->insert(_ip, acceptedSocket);
    }
    else
    {
        acceptedSocket = map_accepted_tcpSocket_->value(_ip);
    }
	mutex_.unlock();
    return acceptedSocket;
}

int network_client_st::SocketManager::GetSendTcpSocketCount()
{
	mutex_.lock();
	int size = map_sended_tcpSocket_->size();
	size = size >= 0 ? size : 0;
	mutex_.unlock();
	return size;
}

QUdpSocket * network_client_st::SocketManager::GetAcceptedUdpSocketByIP(QString _ip)
{
	mutex_.lock();

	QUdpSocket *acceptedSocket = NULL;
	if (!map_accepted_udpSocket_->contains(_ip))
	{
		acceptedSocket = new QUdpSocket();
		acceptedSocket->connectToHost(_ip, /*UDP_HEARTBEAT_SERVER_PORT*/k_udp_heart_server_port_);
		map_accepted_udpSocket_->insert(_ip, acceptedSocket);
	}
	else
	{
		acceptedSocket = map_accepted_udpSocket_->value(_ip);
	}

	mutex_.unlock();

	return acceptedSocket;
}

QTcpSocket * network_client_st::SocketManager::ReCreateSendTcpSocket(const QString _ip)
{
	mutex_.lock();

	QTcpSocket *sendSocket = NULL;
	sendSocket = new QTcpSocket();
	sendSocket->connectToHost(_ip, /*TCP_SERVER_PORT*/k_tcp_server_port_);
	sendSocket->waitForConnected();
	int state = sendSocket->state();
	if (QAbstractSocket::ConnectedState == state)
	{
		if (map_sended_tcpSocket_->contains(_ip))
		{
			map_sended_tcpSocket_->remove(_ip);
		}
		map_sended_tcpSocket_->insert(_ip, sendSocket);
	}

	mutex_.unlock();

	return sendSocket;
}

void SocketManager::AppendSendTcpSocket(QTcpSocket *_sendSocket)
{
	mutex_.lock();
	int state = _sendSocket->state();
	QString ip_client = _sendSocket->peerAddress().toString();
	if (!map_sended_tcpSocket_->contains(ip_client))
	{
		map_sended_tcpSocket_->insert(ip_client, _sendSocket);
	}
	mutex_.unlock();
}

void SocketManager::AppendAccpetedTcpSocket(QTcpSocket *_acceptedSocket)
{
	mutex_.lock();
    QString ip_client = _acceptedSocket->peerAddress().toString();
    if (!map_accepted_tcpSocket_->contains(ip_client))
    {
        map_accepted_tcpSocket_->insert(ip_client, _acceptedSocket);
    }
	mutex_.unlock();
}

void network_client_st::SocketManager::RemoveSendedTcpSocketFromConnected(QString _ip)
{
	QTcpSocket *tcpSocket = GetSendTcpSocketByIP(_ip);
	if (tcpSocket)
	{
		int state = -1;
		if (tcpSocket)
		{
			state = tcpSocket->state();
			if (state == QAbstractSocket::ConnectedState)
			{
				tcpSocket->disconnectFromHost();
				tcpSocket->waitForDisconnected();
				//超时后清除tcp连接，如果服务端断网，tcp状态虽然还是连接状态，但实际消息已无法到达
			}
		}
		mutex_.lock();
		if (!map_sended_tcpSocket_->isEmpty()
			&& state != QAbstractSocket::ConnectedState)
		{
			map_sended_tcpSocket_->remove(_ip);
		}
		mutex_.unlock();
	}
}

void SocketManager::RemoveSendedTcpSocket(QString _ip)
{
	QTcpSocket *tcpSocket = GetSendTcpSocketByIP(_ip);
	mutex_.lock();
	if (tcpSocket)
	{
		int state = -1;
		if (tcpSocket)
		{
			state = tcpSocket->state();
			if (state != QAbstractSocket::ConnectedState)
			{
				tcpSocket->disconnect();
// 	 			tcpSocket->waitForDisconnected();
				//检测客户端断线后但tcp连接还存在，则不清除tcp连接，上线后继续使用
			}
		}
		if (!map_sended_tcpSocket_->isEmpty()
			&& state != QAbstractSocket::ConnectedState)
		{
			map_sended_tcpSocket_->remove(_ip);
			//心跳检测如果掉线，tcp连接还在，则不删除
		}
	}
	mutex_.unlock();
}

void SocketManager::RemoveAcceptedSocket(QString _ip)
{

}

SocketManager::SocketManager()
{
	Init();
}

void SocketManager::Init()
{
	map_sended_tcpSocket_ = new QMap < QString, QTcpSocket * >();
	map_accepted_tcpSocket_ = new QMap<QString, QTcpSocket *>();
	map_sended_udpSocket_ = new QMap<QString, QUdpSocket *>();
	map_accepted_udpSocket_ = new QMap<QString, QUdpSocket *>();
}

void SocketManager::AppendSendUdpSocket(QUdpSocket *_sendUdpSocket)
{
	QString ip_client = _sendUdpSocket->peerAddress().toString();
	if (!map_sended_udpSocket_->contains(ip_client))
	{
		mutex_.lock();

		map_sended_udpSocket_->insert(ip_client, _sendUdpSocket);

		mutex_.unlock();
	}
}

void SocketManager::AppendAccpetedUdpSocket(QUdpSocket *_acceptedUdpSocket)
{
	QString ip_client = _acceptedUdpSocket->peerAddress().toString();
	if (!map_accepted_udpSocket_->contains(ip_client))
	{
		mutex_.lock();

		map_accepted_udpSocket_->insert(ip_client, _acceptedUdpSocket);

		mutex_.unlock();
	}
}

