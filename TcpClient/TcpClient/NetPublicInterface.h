#ifndef NETPUBLICINTERFACE_H
#define NETPUBLICINTERFACE_H
/************************************!
* @file NetPublicInterface.h
*
* @author ����
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
	* @Returns:   MessageUnit * ���û����Ϣ��Ϊ��
	* @Qualifier:
	* @comment: ȡ���½��յ���Ϣ
	************************************/
	MessageUnit * GetReceiveNewMessage();

	/************************************
	* @Method:    AddSendMessage
	* @FullName:  network_st::NetInterface::AddSendMessage
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: ���Ҫ���͵���Ϣ����Ϣ����
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
