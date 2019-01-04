#ifndef ADDRESSMANAGER_H
#define ADDRESSMANAGER_H
/*!
* @file AddressManager.h
*
* @author ����
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
	* @comment: �ֶ����ӵ�ַ
	************************************/
	void AddClientAddress(Client *_client);
	/************************************
	* @Method:    RemoveClientAddress
	* @FullName:  network_st::AddressManager::RemoveClientAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: int _index
	* @comment: �ֶ�ɾ����ַ
	************************************/
	void RemoveClientAddress(int _index);
	/************************************
	* @Method:    GetAllClientSize
	* @FullName:  network_st::AddressManager::GetAllClientSize
	* @Access:    public 
	* @Returns:   int
	* @Qualifier:
	* @comment:	��ȡ�ͻ�������
	************************************/
	int GetAllClientSize();
	/************************************
	* @Method:    GetClientByIndex
	* @FullName:  network_st::AddressManager::GetClientByIndex
	* @Access:    public 
	* @Returns:   Client *
	* @Qualifier:
	* @Parameter: const int _index
	* @comment: ��ȡָ�����߿ͻ���
	************************************/
	Client *GetClientByIndex(const int _index);
	/************************************
	* @Method:    GetAllClient
	* @FullName:  network_st::AddressManager::GetAllClient
	* @Access:    public 
	* @Returns:   QList<Client *> *
	* @Qualifier:
	* @comment:		��ȡ���пͻ��˵ļ���
	************************************/
	QList<Client *> *GetAllClient();
	/************************************
	* @Method:    UpdateClientState
	* @FullName:  network_st::AddressManager::UpdateClientState
	* @Access:    public 
	* @Returns:   QList<Client *> *
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment:		���¿ͻ���UI״̬
	************************************/
	QList<Client *> *UpdateClientState(Client *_client);
	/************************************
	* @Method:    UpdateClientTimeout
	* @FullName:  network_st::AddressManager::UpdateClientTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: �������пͻ��˳�ʱʱ��
	************************************/
	QList<Client *> *UpdateClientTimeout();
	/************************************
	* @Method:    ResetClientTimeout
	* @FullName:  network_st::AddressManager::ResetClientTimeout
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: �������пͻ��˳�ʱʱ��
	************************************/
	void ResetClientTimeout();
	/************************************
	* @Method:    SetClientOffline
	* @FullName:  network_st::AddressManager::SetClientOffline
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment: �ͻ���δ��ʱ��ǿ�жϿ�ʱ����
	************************************/
	void SetClientOffline(Client *_client);
protected:
private:
	void Init();
public:
	QList<Client *> *list_client_;			///<�ͻ���IP��ַ�б�
private:
	static AddressManager *instance_;

	QList<Client *> *list_client_timeout_;	///<���߿ͻ���

	QMutex mutex_;
};
}
#endif
