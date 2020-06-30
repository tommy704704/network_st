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
namespace network_client_st{

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
	* @Method:    AddServerAddress
	* @FullName:  network_client_st::AddressManager::AddServerAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Server * _server
	* @comment: 手动增加地址
	************************************/
	void AddServerAddress(Server *_server);
	/************************************
	* @Method:    RemoveServerAddress
	* @FullName:  network_client_st::AddressManager::RemoveServerAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: int _index
	* @comment: 手动删除地址
	************************************/
	void RemoveServerAddress(int _index);
	/************************************
	* @Method:    GetAllServerSize
	* @FullName:  network_client_st::AddressManager::GetAllServerSize
	* @Access:    public 
	* @Returns:   int
	* @Qualifier:
	* @comment:	获取接入过的所有客户端数量
	************************************/
	int GetAllServerSize();
	/************************************
	* @Method:    GetServerByIndex
	* @FullName:  network_client_st::AddressManager::GetServerByIndex
	* @Access:    public 
	* @Returns:   Server *
	* @Qualifier:
	* @Parameter: const int _index
	* @comment: 获取指定在线客户端
	************************************/
	Server *GetServerByIndex(const int _index);
	/************************************
	* @Method:    GetAllServers
	* @FullName:  network_client_st::AddressManager::GetAllServers
	* @Access:    public 
	* @Returns:   QList<Server *> *
	* @Qualifier:
	* @comment:		获取所有客户端的集合
	************************************/
	QList<Server *> *GetAllServers();
	/************************************
	* @Method:    UpdateServerState
	* @FullName:  network_client_st::AddressManager::UpdateServerState
	* @Access:    public 
	* @Returns:   QList<Server *> *
	* @Qualifier:
	* @Parameter: Server * _server
	* @comment:		更新客户端UI状态
	************************************/
	QList<Server *> *UpdateServerState(Server *_server);
	/************************************
	* @Method:    UpdateServerTimeout
	* @FullName:  network_client_st::AddressManager::UpdateServerTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 更新所有客户端超时时间
	************************************/
	QList<Server *> *UpdateServerTimeout();
	/************************************
	* @Method:    ResetServerTimeout
	* @FullName:  network_client_st::AddressManager::ResetServerTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 重置所有客户端超时时间
	************************************/
	void ResetServerTimeout();
	/************************************
	* @Method:    SetServerOffline
	* @FullName:  network_client_st::AddressManager::SetServerOffline
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Server * _server
	* @comment: 客户端未超时，强行断开时设置
	************************************/
	void SetServerOffline(Server *_server);
protected:
private:
	void Init();
public:
	QList<Server *> *list_server_;			///<客户端IP地址列表
private:
	static AddressManager *instance_;

	QList<Server *> *list_server_timeout_;	///<下线客户端

	QMutex mutex_;
};
}
#endif
