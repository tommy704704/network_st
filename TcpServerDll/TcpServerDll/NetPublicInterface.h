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
#include "tcpserverdll_global.h"

namespace network_st {
class NetInterface;

class TCPSERVERDLL_EXPORT NetPublicInterface
{

public:
	~NetPublicInterface();

	/*
	* @file
	* @author
	* @brief 设置心跳包，区分服务器类型，客户端也需要设置一样的心跳参数
	* @param _heartValue 心跳参数
	* @return
	* @retval
	* @see
	*/
	bool SetHeartServer(QString _heartValue);

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
	/*
	* @file
	* @author
	* @brief 设置是否打开心跳debug输出
	* @param bool _is_open打开debug输出
	* @return
	* @retval
	* @see
	*/
	static void OpenDebug(bool _is_open = true);

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

	/*
	* @file
	* @author
	* @brief 在初始化之前设置udp判定心跳超时的时间值，默认是30秒
	* @param const int _timeout单位是秒
	* @return
	* @retval
	* @see
	*/
	static void SetTimeOut(const int _timeout);

	/*
	* @file
	* @author
	* @brief 在初始化之前设置udp广播发送间隔时间，一般情况不建议设置，有默认值
	* @param const int _interval单位是秒
	* @return
	* @retval
	* @see
	*/
	static void SetBroadcastInterval(const int _interval);

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
