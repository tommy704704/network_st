#include "NewTcpClient.h"
#include <QDateTime>
#include "Global.h"
using namespace network_st;
extern QString g_server_ip;

NewTcpClient *NewTcpClient::s_instance_ = nullptr;
network_st::NewTcpClient::NewTcpClient()
{
	Init();
}

network_st::NewTcpClient::~NewTcpClient()
{
	delete logManager_;

	logManager_ = NULL;
	
	tcpReceiveThread_->quit();
	
	tcpReceiveThread_->wait();

	delete tcpReceiveThread_;

	tcpReceiveThread_ = NULL;

	tcpSendThread_->quit();

	tcpSendThread_->wait();

	delete tcpSendThread_;
	
	tcpSendThread_ = NULL;

	delete socketManager_;

	socketManager_ = NULL;
	
	delete tcpSocket_connectToServer_;

	tcpSocket_connectToServer_ = NULL;
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

void network_st::NewTcpClient::Slot_BindNewTcpConnection()
{
	QTcpSocket *tcpSocket_send = socketManager_->GetSendTcpSocketByIP(g_server_ip);
	if (!tcpSocket_send)
	{
		tcpSocket_send = socketManager_->ReCreateSendTcpSocket(g_server_ip);
	}

	if (tcpSocket_send)
	{
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
			.arg(tcpSocket_send->state());

		logManager_->AppendLog(logMessage);

		logManager_->OutLog();
		//输出tcp连接日志

	}
}

void network_st::NewTcpClient::Slot_Connected()
{
	socketManager_->AppendSendTcpSocket(tcpSocket_connectToServer_);
	//添加到连接池
	QString ipv4_server = tcpSocket_connectToServer_->peerAddress().toString();

	QString logMessage = QString("%1%2%3%4%5")
		.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
		.arg(" IP:")
		.arg(ipv4_server)
		.arg(" tcp connect information: ")
		.arg(tcpSocket_connectToServer_->state());

	logManager_->AppendLog(logMessage);

	logManager_->OutLog();
	//输出tcp连接日志

}

void network_st::NewTcpClient::Slot_DisplayError(QAbstractSocket::SocketError error)
{
	QTcpSocket *tcpSocket_send = socketManager_->GetSendTcpSocketByIP(g_server_ip);
	if (!tcpSocket_send)
	{
		QString error_information = "tcp connection has deleted!";
		qDebug() << error_information;
		//输出错误信息
		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(g_server_ip)
			.arg(" tcp error information: ")
			.arg(error_information);

		logManager_->AppendLog(logMessage);

		logManager_->OutLog();
		//输出tcp连接错误信息
	}
	else
	{
		QString error_information = tcpSocket_send->errorString();
		qDebug() << error_information;
		//输出错误信息
		QString ipv4_server = tcpSocket_send->peerAddress().toString();

		QString logMessage = QString("%1%2%3%4%5")
			.arg(QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz"))
			.arg(" IP:")
			.arg(ipv4_server)
			.arg(" tcp error information: ")
			.arg(error_information);

		logManager_->AppendLog(logMessage);

		logManager_->OutLog();
		//输出tcp连接错误信息

		socketManager_->RemoveSendedTcpSocket(ipv4_server);
		//删掉连接
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


	/*获取服务端地址后，开启tcp接收服务*/

	tcpReceiveThread_ = TcpReceiveThread::GetInstance();
	tcpReceiveThread_->start();

	CreateSignalAndSLot();

}

void network_st::NewTcpClient::Slot_StateChanged(QAbstractSocket::SocketState _socketState)
{
	if (QAbstractSocket::ClosingState == _socketState)
	{
		QTcpSocket *sendSocket = qobject_cast<QTcpSocket *>(sender());
// 		QString ipv4 = sendSocket->peerAddress().toString();
		socketManager_->RemoveSendedTcpSocket(g_server_ip);
		//删掉连接
	}

}
