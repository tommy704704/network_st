#ifndef ADDRESSMANAGER_H
#define ADDRESSMANAGER_H
/*!
* @file AddressManager.h
*
* @author 宋涛
* @date 2018/01/04
*
*
*/
#include <QList>
#include <QMutex>
#include "Global.h"
namespace network_st{

class AddressManager
{
public:
	AddressManager();
	~AddressManager();
	static AddressManager *GetInstance()
	{
		if (!instance_)
		{
			instance_ = new AddressManager();
		}
		return instance_;
	}
	/************************************
	* @Method:    AddClientAddress
	* @FullName:  network_st::AddressManager::AddClientAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment: 手动增加地址
	************************************/
	void AddClientAddress(Client *_client);
	/************************************
	* @Method:    RemoveClientAddress
	* @FullName:  network_st::AddressManager::RemoveClientAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: int _index
	* @comment: 手动删除地址
	************************************/
	void RemoveClientAddress(int _index);
	/************************************
	* @Method:    GetAllClientSize
	* @FullName:  network_st::AddressManager::GetAllClientSize
	* @Access:    public 
	* @Returns:   int
	* @Qualifier:
	* @comment:	获取客户端数量
	************************************/
	int GetAllClientSize();
	/************************************
	* @Method:    GetClientByIndex
	* @FullName:  network_st::AddressManager::GetClientByIndex
	* @Access:    public 
	* @Returns:   Client *
	* @Qualifier:
	* @Parameter: const int _index
	* @comment: 获取指定在线客户端
	************************************/
	Client *GetClientByIndex(const int _index);
	/************************************
	* @Method:    GetAllClient
	* @FullName:  network_st::AddressManager::GetAllClient
	* @Access:    public 
	* @Returns:   QList<Client *> *
	* @Qualifier:
	* @comment:		获取所有客户端的集合
	************************************/
	QList<Client *> *GetAllClient();
	/************************************
	* @Method:    UpdateClientState
	* @FullName:  network_st::AddressManager::UpdateClientState
	* @Access:    public 
	* @Returns:   QList<Client *> *
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment:		更新客户端UI状态
	************************************/
	QList<Client *> *UpdateClientState(Client *_client);
	/************************************
	* @Method:    UpdateClientTimeout
	* @FullName:  network_st::AddressManager::UpdateClientTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 更新所有客户端超时时间
	************************************/
	QList<Client *> *UpdateClientTimeout();
	/************************************
	* @Method:    ResetClientTimeout
	* @FullName:  network_st::AddressManager::ResetClientTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 重置所有客户端超时时间
	************************************/
	void ResetClientTimeout();
	/************************************
	* @Method:    SetClientOffline
	* @FullName:  network_st::AddressManager::SetClientOffline
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment: 客户端未超时，强行断开时设置
	************************************/
	void SetClientOffline(Client *_client);
protected:
private:
	void Init();
public:
	QList<Client *> *list_client_;			///<客户端IP地址列表
private:
	static AddressManager *instance_;

	QList<Client *> *list_client_timeout_;	///<下线客户端

	QMutex mutex_;
};
}
#endif
