#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H
/************************************!
 * @file global.h
 *
 * @author 宋涛
 * @date 2018/2/2
 *
 ************************************/
#include <QMap>
#include <QMutex>
#include <QThread>
#include <QTcpSocket>
#include <QUdpSocket>
#include "Global.h"
#include "MessageManager.h"
#include "SocketManager.h"

namespace network_server_st {

class TcpReceiveThread : public QThread
{
    Q_OBJECT
public:
    static TcpReceiveThread *GetInstance()
    {
        if (!instance_)
        {
            instance_ = new TcpReceiveThread();
        }
        return instance_;
    }
    ~TcpReceiveThread();
signals:
    void Signal_ReceivedMessage(MessageUnit *_messageUnit);
	/*通知应用*/
private:
    TcpReceiveThread();
    void Init();
    virtual void run();
public slots:
    void Slot_ReadyRead();


private:
    bool is_quit_ = false;

    static TcpReceiveThread *instance_;

	MessageManager *messageManager_;

    SocketManager *socketManager_;

	QTcpSocket *accept_tcpSocket_;
	
	QUdpSocket *accept_udpSocket_;

	QMutex mutex_;
};
}

#endif // RECEIVETHREAD_H
