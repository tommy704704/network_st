#include "AddressManager.h"
using namespace network_st;
AddressManager *AddressManager::instance_ = nullptr;
namespace network_st {
AddressManager::AddressManager()
{
	Init();
}

AddressManager::~AddressManager()
{
	mutex_.lock();

	delete list_server_;
	
	list_server_ = NULL;

	delete list_server_timeout_;

	list_server_timeout_ = NULL;

	mutex_.unlock();
}

QList<Server *> * AddressManager::GetAllServers()
{
	return list_server_;	
}

QList<Server *> * AddressManager::UpdateServerState(Server *_server)
{
	mutex_.lock();

	int size = list_server_->size();
	bool is_found = false;
	for (int i = 0; i < size; i++)
	{
		Server *server = list_server_->at(i);
		if (server->ipv4 == _server->ipv4)
		{
			server->is_online = _server->is_online;
			is_found = true;
			server->timeout = _server->timeout;
		}
		///<更新服务端状态
	}
	if (!is_found)
	{
		list_server_->append(_server);
		///<新增服务端
		qDebug() << "+++++++++++++++++++++++++++++++++++ append server to AddressManager by ip :" 
				<< _server->ipv4;

	}
	
	mutex_.unlock();
	
	return list_server_;
}

void AddressManager::Init()
{
	list_server_ = new QList < Server * >();

	list_server_timeout_ = new QList<Server *>();
}

void AddressManager::AddServerAddress(Server *_server)
{
	mutex_.lock();
	list_server_->append(_server);		///<ui和地址列表同步增加操作
	mutex_.unlock();

}

void AddressManager::RemoveServerAddress(int _index)
{
	mutex_.lock();
	list_server_->removeAt(_index);		
	mutex_.unlock();

}

int AddressManager::GetAllServerSize()
{
	mutex_.lock();

	if (!list_server_)
	{
		mutex_.unlock();

		return -1;
	}

	int size = list_server_->size();

	int result = size > 0 ? size : 0;

	mutex_.unlock();

	return result;
}

Server * AddressManager::GetServerByIndex(const int _index)
{
	mutex_.lock();

	Server *server = NULL;
	int size = list_server_->size();
	if (_index < size)
	{
		server = list_server_->at(_index);
	}
	else
	{
		server = new Server();
		server->ipv4 = k_default_ip;
		server->is_online = false;
	}
	
	mutex_.unlock();
	return server;
}

QList<Server *> *AddressManager::UpdateServerTimeout()
{
	mutex_.lock();

	list_server_timeout_->clear();
	int size = list_server_->size();
	for (int i = 0; i < size; i++)
	{
		Server *server = list_server_->at(i);
		if (server->timeout >= GetTimeout())
		///<大于默认超时时间
		{
			if (server->is_online)
			{
				server->is_online = false;
				///<已下线则不再实时加入下线缓存
				list_server_timeout_->append(server);
				///<超时，状态改为下线
			}
		}
		//server->timeout += GetBroadcastInterval();
		server->timeout += 1;
		///<实时更新超时时间，改接口是1秒调用一次，所以递增1秒

	}

	mutex_.unlock();

	return list_server_timeout_;
}

void AddressManager::ResetServerTimeout()
{
	mutex_.lock();

	QList<Server *>::iterator iterator_client_timeout = list_server_timeout_->begin();
	for (; iterator_client_timeout != list_server_timeout_->end(); iterator_client_timeout++)
	{
		Server *server = *iterator_client_timeout;
		server->timeout = 0;
		///<重置
	}

	mutex_.unlock();

}

void AddressManager::SetServerOffline(Server *_server)
{
	mutex_.lock();

	QList<Server *>::iterator iterator_client = list_server_->begin();
	for (; iterator_client != list_server_->end(); iterator_client++)
	{
		Server *server = *iterator_client;
		QString ipv4_cache = server->ipv4;
		if (ipv4_cache == _server->ipv4)
		{
			server->timeout = GetTimeout();
			///<下线标识在UpdateServerTimeout()中设置
		}
	}

	mutex_.unlock();
}

}