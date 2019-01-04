#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H
/************************************!
 * @file global.h
 *
 * @author 宋涛
 * @date 2018/2/2
 *
 ************************************/
#include <QMap>
#include <QMutex>
#include <QQueue>
#include <QString>
#include <QTcpSocket>
#include <QUdpSocket>
#include "Global.h"
namespace network_st{

class SocketManager
{
public:
	SocketManager();

    ~SocketManager();
    static SocketManager *GetInstance()
    {
        if (!instance_)
        {
            instance_ = new SocketManager();
        }
        return instance_;
    }
    QMap<QString, QTcpSocket *> * GetMapSendedSocket(){return map_sended_tcpSocket_;};
    QMap<QString, QTcpSocket *> * GetMapAcceptedSocket(){return map_accepted_tcpSocket_;};
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     获取发客户端的tcp连接
    ************************************/
	int GetSendTcpSocketCount();
    QTcpSocket * GetSendTcpSocketByIP(QString _ip);
	/************************************
	* @Method:    GetSendUdpSocketByIP
	* @FullName:  network_st::SocketManager::GetSendUdpSocketByIP
	* @Access:    public 
	* @Returns:   QUdpSocket *
	* @Qualifier:
	* @Parameter: QString _ip
	* @comment:      获取发客户端的udp连接
	************************************/
	QUdpSocket *GetSendUdpSocketByIP(QString _ip);
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     获取收客户端的tcp连接
    ************************************/
    QTcpSocket * GetAcceptedTcpSocketByIP(QString _ip);
	/************************************
	* @Method:    GetAcceptedUdpSocketByIP
	* @FullName:  network_st::SocketManager::GetAcceptedUdpSocketByIP
	* @Access:    public 
	* @Returns:   QUdpSocket *
	* @Qualifier:
	* @Parameter: QString _ip
	* @comment:      获取收客户端的udp连接
	************************************/
	QUdpSocket *GetAcceptedUdpSocketByIP(QString _ip);
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:      增加发客户端的tcp连接
    ************************************/
	void AppendSendTcpSocket(QTcpSocket *_sendSocket);
	/************************************
	* @Method:    AppendSendUdpSocket
	* @FullName:  network_st::SocketManager::AppendSendUdpSocket
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QUdpSocket * _appendUdpSocket
	* @comment:		增加发客户端udp连接
	************************************/
	void AppendSendUdpSocket(QUdpSocket *_sendUdpSocket);
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     增加收客户端的tcp连接
    ************************************/
    void AppendAccpetedTcpSocket(QTcpSocket *_acceptedSocket);
	/************************************
	* @Method:    AppendAccpetedUdpSocket
	* @FullName:  network_st::SocketManager::AppendAccpetedUdpSocket
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QUdpSocket * _acceptedUdpSocket
	* @comment:		增加收客户端的udp连接
	************************************/
	void AppendAccpetedUdpSocket(QUdpSocket *_acceptedUdpSocket);
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     删除发客户端的连接
    ************************************/
    void RemoveSendedTcpSocket(QString _ip);
	/************************************
	* @Method:    RemoveSendedTcpSocketFromConnected
	* @FullName:  network_st::SocketManager::RemoveSendedTcpSocketFromConnected
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _ip
	* @comment: 删除连接状态的tcp连接，用在心跳超时的时候
	************************************/
	void RemoveSendedTcpSocketFromConnected(QString _ip);
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     删除客户端收的连接
    ************************************/
    void RemoveAcceptedSocket(QString _ip);
	/************************************
	* @Method:    ReCreateSendTcpSocket
	* @FullName:  network_st::SocketManager::ReCreateSendTcpSocket
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 重新创建新的tcp连接
	************************************/
	QTcpSocket * ReCreateSendTcpSocket(const QString _ip);
private:
    void Init();
private:
    static SocketManager *instance_;

    QMap<QString, QTcpSocket *> *map_sended_tcpSocket_;
    QMap<QString, QTcpSocket *> *map_accepted_tcpSocket_;
	QMap<QString, QUdpSocket *> *map_sended_udpSocket_;
	QMap<QString, QUdpSocket *> *map_accepted_udpSocket_;

	QMutex mutex_;

};

}

#endif // SOCKETMANAGER_H
