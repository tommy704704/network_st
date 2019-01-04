#ifndef GLOBAL_H
#define GLOBAL_H
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

namespace network_st {

const QString k_keepAlive = "KeepAlive";					///<心跳询问包

const QString k_receipt_keepAlive = "Ark_KeepAlive";		///<心跳回执包

const QString k_reset = "Reset";							///<客户端清除连接

const QString k_receipt_reset = "Ark_Reset";				///<客户端清除连接回执

const QString k_default_ip = "0.0.0.0";

const int k_client_timeout = 30;						///<客户端超时时间

const QString k_header_message = "-head-";				///<消息头

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
QList<MessageUnit *> * UnpackMessage(QByteArray byteArray_message);

MessageUnit PackageMessage(MessageUnit *_messageUnit);

QString GetPeerAddressIpv4(QTcpSocket *_acceptedSocket);

QString GetPeerAddressIpv4(QUdpSocket *_acceptedSocket);

}
#endif // GLOBAL_H

