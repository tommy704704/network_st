#include "NewTcpServer.h"
#include <QDateTime>
using namespace network_server_st;
extern QString g_local_ip;
extern QString g_sender_ip;
extern QString g_server_ip;

NewTcpServer *NewTcpServer::instance_ = NULL;

NewTcpServer::~NewTcpServer()
{
	delete tcp_server_;

	tcp_server_ = NULL;
}

NewTcpServer::NewTcpServer(QObject *parent)/* : QTcpServer(parent)*/
{
    Init();

    CreateSignalAndSlot();
}

void NewTcpServer::CreateSignalAndSlot()
{
    bool is_ok = connect(tcp_server_, SIGNAL(newConnection()), this, SLOT(Slot_NewConnection()));
}

void NewTcpServer::Init()
{
	addressManager_ = AddressManager::GetInstance();

	logManager_ = LogManager::GetInstance();

    socketManager_ = SocketManager::GetInstance();
   
	tcpSendThread_ = TcpSendThread::GetInstance();
    
	tcpReceiveThread_ = TcpReceiveThread::GetInstance();
    
	tcpSendThread_->start();
    
	tcpReceiveThread_->start();
    
	tcp_server_ = new QTcpServer();
    
	tcp_server_->listen(QHostAddress::Any, /*TCP_SERVER_PORT*/k_tcp_server_port_);
    ///<监听
}

void NewTcpServer::Slot_NewConnection()
{
    QTcpSocket *acceptedSocket = tcp_server_->nextPendingConnection();
    socketManager_->AppendAccpetedTcpSocket(acceptedSocket);

	///<收连接 关联 接收槽
	bool is_ok = connect(acceptedSocket
						, SIGNAL(readyRead())
						, tcpReceiveThread_
						, SLOT(Slot_ReadyRead())
						, Qt::QueuedConnection);


	is_ok = connect(acceptedSocket
		, SIGNAL(error(QAbstractSocket::SocketError))
		, this
		, SLOT(Slot_DisplayError(QAbstractSocket::SocketError)));

	is_ok = connect(acceptedSocket
		, SIGNAL(disconnected())
		, this
		, SLOT(Slot_Disconnected())
		, Qt::QueuedConnection);

	is_ok = connect(acceptedSocket
		, SIGNAL(stateChanged(QAbstractSocket::SocketState))
		, this
		, SLOT(Slot_StateChanged(QAbstractSocket::SocketState)));

	//QString ipv4_client = acceptedSocket->peerAddress().toString();
	QString ipv4_client = GetPeerAddressIpv4(acceptedSocket);
	QString logMessage = QString("%1%2%3%4%5")
		.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
		.arg(" IP:")
		.arg(ipv4_client)
		.arg(" tcp connect information: ")
		.arg(GetConnectionInfromation(acceptedSocket->state()));

	logManager_->AppendLog(logMessage);

	qDebug() << "Slot_NewConnection()" << "new connection from client IP : " << ipv4_client;

	logManager_->OutLog();
	///<输出tcp连接日志
}

void network_server_st::NewTcpServer::Slot_Disconnected()
{

}

void network_server_st::NewTcpServer::Slot_DisplayError(QAbstractSocket::SocketError _error)
{
	QTcpSocket *tcpSocket_accepeted = qobject_cast<QTcpSocket *>(sender());

	QString error_information = tcpSocket_accepeted->errorString();

	qDebug() << error_information;

	//QString ipv4_client = tcpSocket_accepeted->peerAddress().toString();
	QString ipv4_client = GetPeerAddressIpv4(tcpSocket_accepeted);
	///<对点IP地址

	QString logMessage = QString("%1%2%3%4%5")
		.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
		.arg(" IP:")
		.arg(ipv4_client)
		.arg(" tcp error information: ")
		.arg(error_information);

	logManager_->AppendLog(logMessage);

	logManager_->OutLog();
	///<输出tcp连接错误信息
	socketManager_->RemoveAcceptedTcpSocket(ipv4_client);
	///<删掉连接
	Client *client_offline = new Client();
	client_offline->ipv4 = ipv4_client;
	addressManager_->SetClientOffline(client_offline);
}

void network_server_st::NewTcpServer::Slot_StateChanged(QAbstractSocket::SocketState _socketState)
{
	QTcpSocket *acceptedSocket = nullptr;
	if (QAbstractSocket::ClosingState == _socketState)
	{
		acceptedSocket = qobject_cast<QTcpSocket *>(sender());
		//QString ipv4 = acceptedSocket->peerAddress().toString();
		QString ipv4 = GetPeerAddressIpv4(acceptedSocket);
		socketManager_->RemoveAcceptedTcpSocket(ipv4);
		///<删掉连接
	}
	if (acceptedSocket)
	{
		QString ipv4_client = GetPeerAddressIpv4(acceptedSocket);

		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(ipv4_client)
			.arg(" tcp connect information: ")
			.arg(GetConnectionInfromation(_socketState));
		logManager_->AppendLog(logMessage);
		logManager_->OutLog();
		///<输出tcp连接日志
	}

}

// void network_server_st::NewTcpServer::incomingConnection(qintptr socketDescriptor)
// {
// 	tcpSendThread_->socketDescriptor_ = socketDescriptor;
// }

QString network_server_st::NewTcpServer::GetConnectionInfromation(const int _type)
{
	QString result = "none information";
	switch (_type)
	{
	case QAbstractSocket::UnconnectedState:
		result = "UnconnectedState:The socket is not connected.";
		break;
	case QAbstractSocket::HostLookupState:
		result = "HostLookupState:The socket is performing a host name lookup.";
		break;
	case QAbstractSocket::ConnectingState:
		result = "ConnectingState:The socket has started establishing a connection.";
		break;
	case QAbstractSocket::ConnectedState:
		result = "ConnectedState:A connection is established.";
		break;
	case QAbstractSocket::BoundState:
		result = "BoundState:The socket is bound to an address and port.";
		break;
	case QAbstractSocket::ClosingState:
		result = "ClosingState:The socket is about to close (data may still be waiting to be written).";
		break;
	case QAbstractSocket::ListeningState:
		result = "ListeningState:For internal use only.";
		break;
	default:
		break;
	}
	return result;
}
