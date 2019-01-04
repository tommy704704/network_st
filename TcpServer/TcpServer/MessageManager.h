#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
/*!
* @file AddressManager.h
*
* @author ����
* @date 2018/01/04
*
*
*/
#include <QMutex>
#include <QQueue>
#include "QString"
#include "Global.h"
namespace network_st{

class MessageManager
{
public:
	~MessageManager();

	static MessageManager *GetInstance()
	{
		if (!instance_)
		{
			instance_ = new MessageManager();
		}
		return instance_;
	}
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ���ӷ��ͻ�����Ϣ������
	************************************/
	void AppendSendedMessage(MessageUnit *_messageUnit);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ���ӽ��տͻ��˵���Ϣ������
	************************************/
	void AppendReceivedMessage(MessageUnit *_messageUnit);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ɾ�����ͻ�����Ϣ
	************************************/
	void RemoveSendedMessage();
	/************************************
	* @Method:    RemoveSendMessage
	* @FullName:  network_st::MessageManager::RemoveSendMessage
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: char * _msg
	* @comment:		ɾ��������ָ������Ϣ
	************************************/
	void RemoveSendMessage(char *_msg);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ɾ���տͻ�����Ϣ
	************************************/
	void RemoveReceivedMessage();
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ��ȡ��˳��Ҫ���͵���Ϣ
	************************************/
	MessageUnit * GetSendingMessage();
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     ��ȡ���Ͷ�����Ϣ����
	************************************/
	int GetSizeSendingMessage();
	/************************************
	* @Method:    GetNewReceivedMessageUnit
	* @FullName:  network_st::MessageManager::GetNewReceivedMessageUnit
	* @Access:    public 
	* @Returns:   MessageUnit *
	* @Qualifier:
	* @comment: ��ȡ���յ�������Ϣ
	************************************/
	MessageUnit *GetNewReceivedMessageUnit();

protected:
private:
	MessageManager();

	void Init();

public:

private:
	static MessageManager *instance_;

	QQueue<MessageUnit *> *queue_sending_message_;         ///<Ҫ���͵���Ϣ����

	QQueue<MessageUnit *> *queue_received_message_;        ///<���յ�����Ϣ����

	QMutex mutex_;

};
}
#endif