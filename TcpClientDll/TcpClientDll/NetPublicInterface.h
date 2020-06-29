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
#include "tcpclientdll_global.h"

namespace network_st {
class NetInterface;

class TCPCLIENTDLL_EXPORT NetPublicInterface
{

public:
	~NetPublicInterface();

	static NetPublicInterface *GetInstance();
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
	* @Method:    GetAllServers
	* @FullName:  network_st::AddressManager::GetAllServers
	* @Access:    public
	* @Returns:   QList<Server *> *
	* @Qualifier:
	* @comment:		获取所有服务端的集合
	************************************/
	QList<Server *> *GetAllServers();

	/************************************
	* @Method:    GetReceiveNewMessage
	* @FullName:  network_st::NetPublicInterface::GetReceiveNewMessage
	* @Access:    public
	* @Returns:   MessageUnit * 如果没有消息就为空
	* @Qualifier:
	* @comment: 取最新接收的消息
	************************************/
	MessageUnit * GetReceiveNewMessage();

	/************************************
	* @Method:    AddSendMessage
	* @FullName:  network_st::NetPublicInterface::AddSendMessage
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: 添加要发送的消息到消息队列
	************************************/
	void AddSendMessage(MessageUnit *_messageUnit);

	/************************************
	* @Method:    IsConnectedToHost
	* @FullName:  network_st::NetPublicInterface::IsConnectedToHost
	* @Access:    public
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _ip对点的ip地址（服务器）
	* @comment: 获取与服务端是否连接
	************************************/
	bool IsConnectedToHost(const QString _ip);

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
	* @Method:    SetServerIpv4
	* @FullName:  network_st::NetPublicInterface::SetServerIpv4
	* @Access:    public static 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _ipv4
	* @comment: 设置服务器IPV4地址，强制指定地址，可以让局域网同时存在2台以上服务器
	************************************/
	static void SetServerIpv4(QString _ipv4 = k_default_ip);

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
