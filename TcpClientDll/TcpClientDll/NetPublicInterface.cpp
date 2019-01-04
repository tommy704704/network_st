#include "NetPublicInterface.h"
#include "NetInterface.h"

using namespace network_st;

extern QString g_local_ip;

extern QString g_server_ip;			///<服务端IP

extern int client_timeout_;

NetPublicInterface *NetPublicInterface::instance_ = NULL;

NetPublicInterface *NetPublicInterface::GetInstance()
{
	if (!instance_)
	{
		instance_ = new NetPublicInterface();
	}
	return instance_;
}

void NetPublicInterface::OpenDebug(bool _is_open)
{
	SetOutDebug(_is_open);
}

QList<Server*>* network_st::NetPublicInterface::GetAllServers()
{
	return netInterface_->GetAllServers();
}

void NetPublicInterface::SetLocalIpv4(QString _ipv4)
{
	g_local_ip = _ipv4;
}


void network_st::NetPublicInterface::SetServerIpv4(QString _ipv4)
{
	g_server_ip = _ipv4;
}

NetPublicInterface::~NetPublicInterface()
{
	delete netInterface_;

	netInterface_ = NULL;
}

network_st::NetPublicInterface::NetPublicInterface()
{
	qDebug() << "NetPublicInterface()";

	Init();
}

void NetPublicInterface::Init()
{
	netInterface_ = NetInterface::GetInstance();

	CreateSignalAndSlot();
}

void NetPublicInterface::CreateSignalAndSlot()
{

}

MessageUnit * network_st::NetPublicInterface::GetReceiveNewMessage()
{
	return netInterface_->GetReceiveNewMessage();
}

void network_st::NetPublicInterface::AddSendMessage(MessageUnit *_messageUnit)
{
	netInterface_->AddSendMessage(_messageUnit);
}

bool network_st::NetPublicInterface::IsConnectedToHost(const QString _ip)
{
	QTcpSocket *socket_toHost = netInterface_->GetSendTcpSocketByIP(_ip);

	if (socket_toHost)
		return true;
	else
		return false;
}

void network_st::NetPublicInterface::SetTimeOut(const int _timeout)
{
	if (_timeout <= 0)
	{
		client_timeout_ = k_client_timeout_;
	}
	else
	{
		client_timeout_ = _timeout;
	}
}
