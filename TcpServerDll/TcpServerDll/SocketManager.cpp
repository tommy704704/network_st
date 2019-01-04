#include "SocketManager.h"
using namespace network_st;

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
        sendSocket = new QTcpSocket();
        sendSocket->connectToHost(_ip, TCP_CLIENT_PORT);
        map_sended_tcpSocket_->insert(_ip, sendSocket);
    }
    else
    {
        sendSocket = map_sended_tcpSocket_->value(_ip);
    }
	mutex_.unlock();
    return sendSocket;
}

QUdpSocket * SocketManager::GetSendUdpSocketByUP(QString _ip)
{
	QUdpSocket *sendSocket = NULL;
	if (!map_sended_udpSocket_->contains(_ip))
	{
		sendSocket = new QUdpSocket();
		sendSocket->connectToHost(_ip, UDP_HEARTBEAT_CLIENT_PORT);
		map_sended_udpSocket_->insert(_ip, sendSocket);
	}
	else
	{
		sendSocket = map_sended_udpSocket_->value(_ip);
	}
	return sendSocket;
}

QTcpSocket * SocketManager::GetAcceptedTcpSocketByIP(QString _ip)
{
	mutex_.lock();
    QTcpSocket *acceptedSocket = NULL;
    if(!map_accepted_tcpSocket_->contains(_ip))
    {
//         acceptedSocket = new QTcpSocket();
//         acceptedSocket->connectToHost(_ip, TCP_CLIENT_PORT);
// 		acceptedSocket->waitForConnected();
// 		int state = acceptedSocket->state();
// 		if (QAbstractSocket::ConnectedState == state)
// 		{
// 			map_accepted_tcpSocket_->insert(_ip, acceptedSocket);
// 		}
// 		else
// 		{
// 			mutex_.unlock();
// 			return NULL;
// 		}
		mutex_.unlock();
		return NULL;
    }
    else
    {
        acceptedSocket = map_accepted_tcpSocket_->value(_ip);
    }
	mutex_.unlock();
    return acceptedSocket;
}

QUdpSocket * network_st::SocketManager::GetAcceptedUdpSocketByIP(QString _ip)
{
	QUdpSocket *acceptedSocket = NULL;
	if (!map_accepted_udpSocket_->contains(_ip))
	{
		acceptedSocket = new QUdpSocket();
		acceptedSocket->connectToHost(_ip, UDP_HEARTBEAT_CLIENT_PORT);
		map_accepted_udpSocket_->insert(_ip, acceptedSocket);
	}
	else
	{
		acceptedSocket = map_accepted_udpSocket_->value(_ip);
	}
	return acceptedSocket;
}

void SocketManager::AppendSendTcpSocket(MessageUnit *_messageUnit)
{
	mutex_.lock();
    QTcpSocket *sendSocket = NULL;
    if(!map_sended_tcpSocket_->contains(_messageUnit->ip))
    {
        sendSocket = new QTcpSocket();
        sendSocket->connectToHost(_messageUnit->ip, TCP_CLIENT_PORT);
        map_sended_tcpSocket_->insert(_messageUnit->ip, sendSocket);
    }
    else
    {
        sendSocket = map_sended_tcpSocket_->value(_messageUnit->ip);
    }
	mutex_.unlock();
}

void SocketManager::AppendAccpetedTcpSocket(QTcpSocket *_acceptedSocket)
{
	mutex_.lock();
    //QString ip_client = _acceptedSocket->peerAddress().toString();
	QString ip_client = QHostAddress(_acceptedSocket->peerAddress().toIPv4Address()).toString();
    if (!map_accepted_tcpSocket_->contains(ip_client))
    {
        map_accepted_tcpSocket_->insert(ip_client, _acceptedSocket);
    }
	mutex_.unlock();
}

void SocketManager::RemoveSendedTcpSocket(QString _ip)
{
	QTcpSocket *tcpSocket = GetSendTcpSocketByIP(_ip);
	mutex_.lock();
	if (tcpSocket->state() != QAbstractSocket::UnconnectedState)
	{
		tcpSocket->disconnect();
		tcpSocket->waitForDisconnected();
	}
	if (!map_sended_tcpSocket_->isEmpty())
	{
		map_sended_tcpSocket_->remove(_ip);
	}
	mutex_.unlock();
}

void SocketManager::RemoveAcceptedTcpSocket(QString _ip)
{
	QTcpSocket *tcpSocket = GetAcceptedTcpSocketByIP(_ip);
	mutex_.lock();
	if (tcpSocket)
	{
		int state = -1;
		if (tcpSocket)
		{
			state = tcpSocket->state();
			if (state != QAbstractSocket::ConnectedState)
			{
				//检测客户端断线后但tcp连接还存在，则不清除tcp连接，上线后继续使用

				tcpSocket->disconnect();
				// 	 		tcpSocket->waitForDisconnected();
			}
		}
		if (!map_accepted_tcpSocket_->isEmpty()
			&& state != QAbstractSocket::ConnectedState)
		{
			//心跳检测如果掉线，tcp连接还在，则不删除
			map_accepted_tcpSocket_->remove(_ip);
		}
	}
	mutex_.unlock();
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
	//QString ip_client = _sendUdpSocket->peerAddress().toString();
	QString ip_client = GetPeerAddressIpv4(_sendUdpSocket);
	if (!map_sended_udpSocket_->contains(ip_client))
	{
		map_sended_udpSocket_->insert(ip_client, _sendUdpSocket);
	}
}

void SocketManager::AppendAccpetedUdpSocket(QUdpSocket *_acceptedUdpSocket)
{
	//QString ip_client = _acceptedUdpSocket->peerAddress().toString();
	QString ip_client = GetPeerAddressIpv4(_acceptedUdpSocket);
	if (!map_accepted_udpSocket_->contains(ip_client))
	{
		map_accepted_udpSocket_->insert(ip_client, _acceptedUdpSocket);
	}
}

