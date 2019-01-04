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
//#include "tcpserverdll_global.h"

namespace network_st {
class NetInterface;

class NetPublicInterface
{

public:
	~NetPublicInterface();
	/************************************
	* @Method:    GetInstance
	* @FullName:  network_st::NetPublicInterface::GetInstance
	* @Access:    public static 
	* @Returns:   NetPublicInterface *
	* @Qualifier:
	* @Parameter:
	* @comment: 
	************************************/
	static NetPublicInterface *GetInstance();

	/************************************
	* @Method:    SetLocalIpv4
	* @FullName:  network_st::SetLocalIpv4
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _ipv4
	* @comment: 设置本机IPV4地址
	************************************/
	static void SetLocalIpv4(QString _ipv4 = k_default_ip);

	/************************************
	* @Method:    GetLocalAllIPv4
	* @FullName:  network_st::GetLocalAllIPv4
	* @Access:    public
	* @Returns:   QT_NAMESPACE::QStringList
	* @Qualifier:
	* @comment: 获取本机所有IPv4地址列表
	************************************/
	static QStringList GetLocalAllIPv4();

	/************************************
	* @Method:
	* @Access:
	* @Returns:		如果没消息，返回空指针
	* @Qualifier:
	* @Parameter:	QString _ip本机本地连接的ip
	* @comment:     获取队列最新接收消息，如需要缓存需要自己另外处理
	************************************/
	MessageUnit *GetReceivedNewMessageUnit();
	/************************************
	* @Method:    GetAllClient
	* @FullName:  network_st::NetPublicInterface::GetAllClient
	* @Access:    public
	* @Returns:   QList<Client *> *如果没有在线，则列表里数据为0
	* @Qualifier:
	* @comment: 获取所有客户端
	************************************/
	QList<Client *> *GetAllClient();
	/************************************
	* @Method:    AddMessageToSend
	* @FullName:  network_st::NetPublicInterface::AddMessageToSend
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: 增加消息到发送队列
	************************************/
	void AddMessageToSend(MessageUnit *_messageUnit);
	/************************************
	* @Method:    RemoveSendMessage
	* @FullName:  network_st::NetPublicInterface::RemoveSendMessage
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: char * _msg
	* @comment: 从发送队列删除消息
	************************************/
	void RemoveSendMessage(char *_msg);
	/************************************
	* @Method:    AddClientAddress
	* @FullName:  network_st::NetPublicInterface::AddClientAddress
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment: 手动增加客户端地址
	************************************/
	void AddClientAddress(Client *_client);
	/************************************
	* @Method:    RemoveClientAddress
	* @FullName:  network_st::NetPublicInterface::RemoveClientAddress
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: int _index 客户端链表的序号
	* @comment: 手动删除地址
	************************************/
	void RemoveClientAddress(int _index);
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
