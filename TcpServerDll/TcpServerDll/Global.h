#ifndef GLOBAL_SERVER_H
#define GLOBAL_SERVER_H
/************************************!
* @file global.h
*
* @author 宋涛
* @date 2018/2/2
*
************************************/
#include <QHostAddress>
#include <QList>
#include <QNetworkInterface>
#include <QString>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QHostAddress>

#define TCP_SERVER_PORT 60086

#define TCP_CLIENT_PORT 60099

#define UDP_HEARTBEAT_SERVER_PORT 60065

#define UDP_HEARTBEAT_CLIENT_PORT 60066

extern int k_tcp_server_port_;
extern int k_tcp_client_port_;
extern int k_udp_heart_server_port_;
extern int k_udp_heart_client_port_;

namespace network_server_st {
extern QString k_keepAlive;
extern QString k_receipt_keepAlive;

//const QString k_keepAlive = "KeepAlive";					///<默认心跳询问包

//const QString k_receipt_keepAlive = "Ark_KeepAlive";		///<默认心跳回执包

const QString k_reset = "Reset";							///<客户端清除连接

const QString k_receipt_reset = "Ark_Reset";				///<客户端清除连接回执

const QString k_default_ip = "0.0.0.0";

const int k_client_timeout_ = 30;						///<客户端超时的默认时间30，单位秒

const int k_broadcast_interval_ = 3;					///<广播发送的默认间隔3，单位秒

const QString k_header_message = "-head-";				///<消息头
const QString k_end_message_ = "-end-";		///<消息结束，解决大消息融合


/************************************************************************/
/*消息默认是QByteArray接收QDataStream这种形式因为业务需要，IsStreamHandle返回为true
如果是其他形式赋值QByteArray则IsStreamHandle返回false                           */
/************************************************************************/
bool IsStreamHandle();

void SetStreamHandle(bool _is_stream_handle = true);

typedef struct Client
{
	QString ipv4 = "0.0.0.0";				///<客户端IP

	bool is_online = true;					///<是否在线

	int timeout = 0;						///<超时时间 秒
} Client;

typedef struct MessageUnit
{
	char * msg = nullptr;

	QByteArray *byteArray_msg = NULL;
	//提供多种数据类型入口

	QString ip = k_default_ip;
	/************************************************************************/
	/* IP为默认值得时候，服务端会将该消息进行广播
		如果设置为某具体IP后，服务端会单独只将该消息发送给指定IP*/
	/************************************************************************/
}MessageUnit;

/*
* @file
* @author
* @brief 获取广播发送间隔时间，单位秒
* @param
* @return
* @retval
* @see
*/
int GetBroadcastInterval();

/*
* @file
* @author
* @brief 获取超时判定值
* @param
* @return
* @retval
* @see
*/
int GetTimeout();


/************************************
* @Method:    GetLocalIP
* @Access:
* @Returns:   QString
* @Qualifier:
* @Parameter:
* @comment: 获取本机IP
************************************/
QString GetLocalIP();

/************************************
* @Method:    UnpackMessage
* @FullName:  UnpackMessage
* @Access:    public
* @Returns:   QList<MessageUnit *> *
* @Qualifier:
* @Parameter: QByteArray byteArray_message
* @comment: 拆解消息头
************************************/
QList<MessageUnit *> * UnpackMessage(QByteArray byteArray_message, QString _ip);

MessageUnit PackageMessage(MessageUnit *_messageUnit);

QString GetPeerAddressIpv4(QTcpSocket *_acceptedSocket);

QString GetPeerAddressIpv4(QUdpSocket *_acceptedSocket);

/*
* @file
* @author
* @brief 设置输出debug日志
* @param
* @return
* @retval
* @see
*/
void SetOutDebug(bool _is_out_debug);
/*
* @file
* @author
* @brief 获取debug输出标识
* @param
* @return
* @retval
* @see
*/
bool GetOutDebug();

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
* \Method:    Set_Ports
* \FullName:  network_server_st::NetPublicInterface::Set_Ports
* \Access:    public
* \Returns:   void
* \Qualifier:
* \Parameter: int _tcp_server_port tcp服务端端口
* \Parameter: int _tcp_client_port tcp客户端端口
* \Parameter: int _udp_server_port udp服务端心跳包端口
* \Parameter: int _udp_client_port udp客户端心跳包端口
* \comment: 如果要设置端口，需要在实例化interface之前调用
************************************/
void Set_Ports(int _tcp_server_port, int _tcp_client_port, int _udp_server_port, int _udp_client_port);

}

#endif // GLOBAL_SERVER_H
