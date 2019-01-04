#ifndef NETPUBLICINTERFACE_H
#define NETPUBLICINTERFACE_H
/************************************!
* @file NetPublicInterface.h
*
* @author 宋涛
* @date 2018/2/2
*
************************************/
#include "Global.h"

namespace network_st {
class NetInterface;

class NetPublicInterface
{

public:
	~NetPublicInterface();

	static NetPublicInterface *GetInstance();

	/************************************
	* @Method:    GetReceiveNewMessage
	* @FullName:  network_st::NetInterface::GetReceiveNewMessage
	* @Access:    public
	* @Returns:   MessageUnit * 如果没有消息就为空
	* @Qualifier:
	* @comment: 取最新接收的消息
	************************************/
	MessageUnit * GetReceiveNewMessage();

	/************************************
	* @Method:    AddSendMessage
	* @FullName:  network_st::NetInterface::AddSendMessage
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: 添加要发送的消息到消息队列
	************************************/
	void AddSendMessage(MessageUnit *_messageUnit);

private:
	NetPublicInterface();

	void Init();

	void CreateSignalAndSlot();

private:
	static NetPublicInterface *instance_;

	NetInterface *netInterface_;
};

}

#endif // NETPUBLICINTERFACE_H
