#include "NewTcpClient.h"
#include <QDateTime>
#include "Global.h"
using namespace network_st;
extern QString g_server_ip;

NewTcpClient *NewTcpClient::s_instance_ = nullptr;
network_st::NewTcpClient::NewTcpClient() : tcpReceiveThread_(nullptr)
{
	Init();
}

network_st::NewTcpClient::~NewTcpClient()
{
}

void network_st::NewTcpClient::CreateSignalAndSLot()
{
	bool is_ok = connect(tcpSocket_connectToServer_
		, SIGNAL(connected())
		, this
		, SLOT(Slot_Connected()));
 	
	is_ok = connect(tcpSocket_connectToServer_
		, SIGNAL(error(QAbstractSocket::SocketError))
		, this
		, SLOT(Slot_DisplayError(QAbstractSocket::SocketError)));

	is_ok = connect(tcpSocket_connectToServer_
		, SIGNAL(disconnected())
		, this
		, SLOT(Slot_Disconnected()));

	is_ok = connect(tcpSocket_connectToServer_
		, SIGNAL(stateChanged(QAbstractSocket::SocketState))
		, this
		, SLOT(Slot_StateChanged(QAbstractSocket::SocketState))
		, Qt::DirectConnection);


	is_ok = connect(tcpSocket_connectToServer_
		, SIGNAL(readyRead())
		, tcpReceiveThread_
		, SLOT(Slot_ReadMessage()));

	is_ok = connect(tcpReceiveThread_
		, SIGNAL(Signal_UpdateUITcpReceivedMessage(MessageUnit *))
		, this
		, SIGNAL(Signal_UpdateUITcpReceivedMessage(MessageUnit *)));

	is_ok = connect(tcpReceiveThread_
		, SIGNAL(Signal_SendMessage(MessageUnit *))
		, tcpSendThread_
		, SLOT(Slot_SendMessage(MessageUnit *)));

}

void network_st::NewTcpClient::Init()
{
	logManager_ = LogManager::GetInstance();

	socketManager_ = SocketManager::GetInstance();

	tcpSendThread_ = TcpSendThread::GetInstance();

}
QString network_st::NewTcpClient::GetConnectionInfromation(const int _type)
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

void network_st::NewTcpClient::Slot_BindNewTcpConnection()
{
	QTcpSocket *tcpSocket_send = socketManager_->GetSendTcpSocketByIP(g_server_ip);
	if (!tcpSocket_send)
	{
		tcpSocket_send = socketManager_->ReCreateSendTcpSocket(g_server_ip);
	}

	if (tcpSocket_send)
	{
		if (!tcpReceiveThread_)
		{
			tcpReceiveThread_ = TcpReceiveThread::GetInstance();
		}
		if (!tcpReceiveThread_->isRunning())
		{
			tcpReceiveThread_->start();
		}

		bool is_ok = connect(tcpSocket_send
			, SIGNAL(readyRead())
			, tcpReceiveThread_
			, SLOT(Slot_ReadMessage())
			, Qt::QueuedConnection);

		is_ok = connect(tcpSocket_send
			, SIGNAL(connected())
			, this
			, SLOT(Slot_Connected()));

		is_ok = connect(tcpSocket_send
			, SIGNAL(error(QAbstractSocket::SocketError))
			, this
			, SLOT(Slot_DisplayError(QAbstractSocket::SocketError)));

		is_ok = connect(tcpSocket_send
			, SIGNAL(disconnected())
			, this
			, SLOT(Slot_Disconnected()));

		is_ok = connect(tcpSocket_send
			, SIGNAL(stateChanged(QAbstractSocket::SocketState))
			, this
			, SLOT(Slot_StateChanged(QAbstractSocket::SocketState))
			, Qt::DirectConnection);

		QString ipv4_server = tcpSocket_send->peerAddress().toString();

		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(ipv4_server)
			.arg(" tcp reconnect information: ")
			.arg(GetConnectionInfromation(tcpSocket_send->state()));

		logManager_->AppendLog(logMessage);

		logManager_->OutLog();
		///<输出tcp连接日志

	}
}

void network_st::NewTcpClient::Slot_Connected()
{
	socketManager_->AppendSendTcpSocket(tcpSocket_connectToServer_);
	///<添加到连接池
	QString ipv4_server = tcpSocket_connectToServer_->peerAddress().toString();

	QString logMessage = QString("%1%2%3%4%5")
		.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
		.arg(" IP:")
		.arg(ipv4_server)
		.arg(" tcp connect information: ")
		.arg(GetConnectionInfromation(tcpSocket_connectToServer_->state()));

	logManager_->AppendLog(logMessage);

	logManager_->OutLog();
	///<输出tcp连接日志

}

void network_st::NewTcpClient::Slot_DisplayError(QAbstractSocket::SocketError error)
{
	QTcpSocket *tcpSocket_send = socketManager_->GetSendTcpSocketByIP(g_server_ip);
	if (!tcpSocket_send)
	{
		QString error_information = "tcp connection has deleted!";
		qDebug() << error_information;
		///<输出错误信息
		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(g_server_ip)
			.arg(" tcp error information: ")
			.arg(error_information);

		logManager_->AppendLog(logMessage);
		logManager_->OutLog();
		///<输出tcp连接错误信息
	}
	else
	{
		QString error_information = tcpSocket_send->errorString();
		qDebug() << error_information;
		///<输出错误信息
		QString ipv4_server = tcpSocket_send->peerAddress().toString();

		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(ipv4_server)
			.arg(" tcp error information: ")
			.arg(error_information);

		logManager_->AppendLog(logMessage);
		logManager_->OutLog();
		///<输出tcp连接错误信息

		socketManager_->RemoveSendedTcpSocket(ipv4_server);
		///<删掉连接
	}
}

void network_st::NewTcpClient::Slot_Disconnected()
{

}

void network_st::NewTcpClient::Slot_GetServerAddress()
{
	tcpSocket_connectToServer_ = new QTcpSocket();
	QHostAddress server_address(g_server_ip);
	tcpSocket_connectToServer_->connectToHost(server_address, TCP_SERVER_PORT);


	///<获取服务端地址后，开启tcp接收服务

	if (!tcpReceiveThread_)
	{
		tcpReceiveThread_ = TcpReceiveThread::GetInstance();
	}
	if (!tcpReceiveThread_->isRunning())
	{
		tcpReceiveThread_->start();
	}
	

	CreateSignalAndSLot();

}

void network_st::NewTcpClient::Slot_StateChanged(QAbstractSocket::SocketState _socketState)
{
	QTcpSocket *sendSocket = qobject_cast<QTcpSocket *>(sender());
	if (QAbstractSocket::ClosingState == _socketState)
	{
		sendSocket = qobject_cast<QTcpSocket *>(sender());
// 		QString ipv4 = sendSocket->peerAddress().toString();
		socketManager_->RemoveSendedTcpSocket(g_server_ip);
		///<删掉连接
	}
	if (sendSocket)
	{
		QString ipv4_server = sendSocket->peerAddress().toString();
		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(ipv4_server)
			.arg(" tcp connect information: ")
			.arg(GetConnectionInfromation(_socketState));
		logManager_->AppendLog(logMessage);
		logManager_->OutLog();
		///<输出tcp连接日志
	}

}
