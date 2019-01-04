#ifndef UDPADDRESSTHREAD_H
#define UDPADDRESSTHREAD_H
/************************************!
 * @file UdpReceiveThread.h
 *
 * @author 宋涛
 * @date 2018/01/04
 *
 *
 ************************************/
#include <QHostAddress>
#include <QThread>
#include <QUdpSocket>
#include "AddressManager.h"
namespace network_st{
class UdpReceiveThread : public QThread
{
	Q_OBJECT
public:
    UdpReceiveThread();
    ~UdpReceiveThread();
public:
    /************************************
    * @Method:    GetInstance
    * @FullName:  UdpReceiveThread::GetInstance
    * @Access:    public static
    * @Returns:   UdpReceiveThread *
    * @Qualifier:
    * @comment:
    ************************************/
    static UdpReceiveThread *GetInstance()
    {
        if (!instance_)
        {
            instance_ = new UdpReceiveThread();
        }
        return instance_;
    }
    /************************************
    * @Method:    GetOnlineClient
    * @FullName:  UdpReceiveThread::GetOnlineClient
    * @Access:    public
    * @Returns:   QVector<Client *> *
    * @Qualifier:
    * @comment:			获取在线的客户端
    ************************************/
    QList<Client *> *GetOnlineClient();
    /************************************
    * @Method:    GetClientSize
    * @FullName:  UdpReceiveThread::GetClientSize
    * @Access:    public
    * @Returns:   int
    * @Qualifier:
    * @comment:			获取在线客户端数量
    ************************************/

signals:
	void Signal_UpdateAddressList(Client *_client);

protected:
private:
    void Init();
    virtual void run();
private:
    static UdpReceiveThread *instance_;

    AddressManager *addressManager_;

    QList<Client *> *list_clients_;

	QMutex mutex_;

	bool is_quit_;

    QUdpSocket *udpSocket_receive_heartbeat_;
};
}
#endif
