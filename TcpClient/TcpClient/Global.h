#ifndef GLOBAL_H
#define GLOBAL_H
/************************************!
* @file global.h
*
* @author ����
* @date 2018/2/2
*
************************************/
#include <QHostAddress>
#include <QList>
#include <QNetworkInterface>
#include <QString>

#define TCP_SERVER_PORT 10086

#define TCP_CLIENT_PORT 10099

#define UDP_HEARTBEAT_SERVER_PORT 10065

#define UDP_HEARTBEAT_CLIENT_PORT 10066

namespace network_st {

const QString k_keepAlive = "KeepAlive";					///<����ѯ�ʰ�

const QString k_receipt_keepAlive = "Ark_KeepAlive";		///<������ִ��

const QString k_reset = "Reset";							///<�ͻ����������

const QString k_receipt_reset = "Ark_Reset";				///<�ͻ���������ӻ�ִ

const QString k_default_ip = "0.0.0.0";

const int k_client_timeout = 30;						///<�ͻ��˳�ʱʱ��

const QString k_header_message = "-head-";				///<��Ϣͷ

/************************************************************************/
/*��ϢĬ����QByteArray����QDataStream������ʽ��Ϊҵ����Ҫ��IsStreamHandle����Ϊtrue
�����������ʽ��ֵQByteArray��IsStreamHandle����false                           */
/************************************************************************/
bool IsStreamHandle();

void SetStreamHandle(bool _is_stream_handle = true);

typedef struct Client
{
	QString ipv4 = "0.0.0.0";				///<�ͻ���IP

	bool is_online = true;					///<�Ƿ�����
} Client;

typedef struct MessageUnit
{
	char * msg = nullptr;

	QByteArray *byteArray_msg = NULL;
	//�ṩ���������������

	QString ip = k_default_ip;
}MessageUnit;

/************************************
* @Method:    GetLocalIP
* @Access:
* @Returns:   QString
* @Qualifier:
* @Parameter:
* @comment: ��ȡ����IP
************************************/
QString GetLocalIP();

/************************************
* @Method:    UnpackMessage
* @FullName:  UnpackMessage
* @Access:    public
* @Returns:   QList<MessageUnit *> *
* @Qualifier:
* @Parameter: QByteArray byteArray_message
* @comment: �����Ϣͷ
************************************/
QList<MessageUnit *> * UnpackMessage(QByteArray byteArray_message);

MessageUnit PackageMessage(MessageUnit *_messageUnit);

}
#endif // GLOBAL_H

