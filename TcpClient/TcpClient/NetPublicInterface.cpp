#include "NetPublicInterface.h"
#include "NetInterface.h"

using namespace network_st;
NetPublicInterface *NetPublicInterface::instance_ = NULL;

NetPublicInterface *NetPublicInterface::GetInstance()
{
	if (!instance_)
	{
		instance_ = new NetPublicInterface();
	}
	return instance_;
}


NetPublicInterface::~NetPublicInterface()
{
	delete netInterface_;

	netInterface_ = NULL;
}

network_st::NetPublicInterface::NetPublicInterface()
{
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
