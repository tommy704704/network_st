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

	delete list_client_;
	
	list_client_ = NULL;

	delete list_client_timeout_;

	list_client_timeout_ = NULL;

	mutex_.unlock();
}

QList<Client *> * AddressManager::GetAllClient()
{
	return list_client_;	
}

QList<Client *> * AddressManager::UpdateClientState(Client *_client)
{
	mutex_.lock();

	int size = list_client_->size();
	bool is_found = false;
	for (int i = 0; i < size; i++)
	{
		Client *client = list_client_->at(i);
		if (client->ipv4 == _client->ipv4)
		{
			client->is_online = _client->is_online;
			is_found = true;
			client->timeout = _client->timeout;
		}
		///<更新客户端状态
	}
	if (!is_found)
	{
		list_client_->append(_client);
		///<新增客户端
		qDebug() << "+++++++++++++++++++++++++++++++++++ append client to AddressManager by ip :" 
				<< _client->ipv4;

	}
	
	mutex_.unlock();
	
	return list_client_;
}

void AddressManager::Init()
{
	list_client_ = new QList < Client * >();

	list_client_timeout_ = new QList<Client *>();
}

void AddressManager::AddClientAddress(Client *_client)
{
	mutex_.lock();
	list_client_->append(_client);		///<ui和地址列表同步增加操作
	mutex_.unlock();

}

void AddressManager::RemoveClientAddress(int _index)
{
	mutex_.lock();
	list_client_->removeAt(_index);		
	///<ui和地址列表同步删除操作
	mutex_.unlock();

}

int AddressManager::GetAllClientSize()
{
	mutex_.lock();

	if (!list_client_)
	{
		mutex_.unlock();

		return -1;
	}

	int size = list_client_->size();

	int result = size > 0 ? size : 0;

	mutex_.unlock();

	return result;
}

Client * AddressManager::GetClientByIndex(const int _index)
{
	mutex_.lock();

	Client *client = NULL;
	int size = list_client_->size();
	if (_index < size)
	{
		client = list_client_->at(_index);
	}
	else
	{
		client = new Client();
		client->ipv4 = k_default_ip;
		client->is_online = false;
	}
	
	mutex_.unlock();
	return client;
}

QList<Client *> *AddressManager::UpdateClientTimeout()
{
	mutex_.lock();

	list_client_timeout_->clear();
	int size = list_client_->size();
	for (int i = 0; i < size; i++)
	{
		Client *client = list_client_->at(i);
		if (client->timeout >= GetTimeout())
		///<大于默认超时时间
		{
			if (client->is_online)
			{
				client->is_online = false;
				///<已下线则不再实时加入下线缓存
				list_client_timeout_->append(client);
				///<超时，状态改为下线
			}
		}
		client->timeout += GetBroadcastInterval();
		///<实时更新超时时间
	}

	mutex_.unlock();

	return list_client_timeout_;
}

void AddressManager::ResetClientTimeout()
{
	mutex_.lock();

	QList<Client *>::iterator iterator_client_timeout = list_client_timeout_->begin();
	for (; iterator_client_timeout != list_client_timeout_->end(); iterator_client_timeout++)
	{
		Client *client = *iterator_client_timeout;
		client->timeout = 0;
		///<重置
	}

	mutex_.unlock();

}

void AddressManager::SetClientOffline(Client *_client)
{
	mutex_.lock();

	QList<Client *>::iterator iterator_client = list_client_->begin();
	for (; iterator_client != list_client_->end(); iterator_client++)
	{
		Client *client = *iterator_client;
		QString ipv4_cache = client->ipv4;
		if (ipv4_cache == _client->ipv4)
		{
			client->timeout = GetTimeout();
			///<下线标识在UpdateClientTimeout()中设置
		}
	}

	mutex_.unlock();
}

}