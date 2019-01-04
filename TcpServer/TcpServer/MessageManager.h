#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H
/*!
* @file AddressManager.h
*
* @author 宋涛
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
	* @comment:     增加发客户端消息到队列
	************************************/
	void AppendSendedMessage(MessageUnit *_messageUnit);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     增加接收客户端的消息到队列
	************************************/
	void AppendReceivedMessage(MessageUnit *_messageUnit);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     删除发客户端消息
	************************************/
	void RemoveSendedMessage();
	/************************************
	* @Method:    RemoveSendMessage
	* @FullName:  network_st::MessageManager::RemoveSendMessage
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: char * _msg
	* @comment:		删除队列中指定的消息
	************************************/
	void RemoveSendMessage(char *_msg);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     删除收客户端消息
	************************************/
	void RemoveReceivedMessage();
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     获取按顺序将要发送的消息
	************************************/
	MessageUnit * GetSendingMessage();
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     获取发送队列消息数量
	************************************/
	int GetSizeSendingMessage();
	/************************************
	* @Method:    GetNewReceivedMessageUnit
	* @FullName:  network_st::MessageManager::GetNewReceivedMessageUnit
	* @Access:    public 
	* @Returns:   MessageUnit *
	* @Qualifier:
	* @comment: 获取接收的最新消息
	************************************/
	MessageUnit *GetNewReceivedMessageUnit();

protected:
private:
	MessageManager();

	void Init();

public:

private:
	static MessageManager *instance_;

	QQueue<MessageUnit *> *queue_sending_message_;         ///<要发送的消息缓存

	QQueue<MessageUnit *> *queue_received_message_;        ///<接收到的消息缓存

	QMutex mutex_;

};
}
#endif