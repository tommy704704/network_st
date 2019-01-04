#include "MainSendThread.h"
using namespace network_st;

MainSendThread::MainSendThread() : address_("")
{
	Init();
}

MainSendThread::~MainSendThread()
{

}

void MainSendThread::Init()
{
	queryThread_ = QueryThread::GetInstance();
	addressManager_ = AddressManager::GetInstance();
	messageManager_ = MessageManager::GetInstance();
	udp_server_send_ = new QUdpSocket(this);
	queryClientThread_ = QueryClientThread::GetInstance();
	queryClientThread_->start();
}

void MainSendThread::run()
{
	int address_index = 0;
	int count_address = 0;
	QString address = "";
	while (true)
	{
		msleep(1000);
		count_address = queryClientThread_->GetClientSize();
		for (int i = 0; i < count_address; i++)
		{
// 			mutex_.lock();
			address_ = queryClientThread_->GetOnlineClient()->at(i)->ipv4;
// 			mutex_.unlock();
			QHostAddress student_address(address_);
			QString msg = messageManager_->sendMessage_queue_->last().msg;
			int size_msg = msg.size();
			qint64 sended_bytes = udp_server_send_->writeDatagram(msg.toLocal8Bit().constData(), size_msg, student_address, 11122);
			queryClientThread_->GetOnlineClient()->clear();
		}
	}
}

