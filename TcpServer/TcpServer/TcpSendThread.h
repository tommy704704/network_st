#ifndef SENDTHREAD_H
#define SENDTHREAD_H
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
#include <QTcpServer>
#include <QTcpSocket>
#include "AddressManager.h"
#include "Global.h"
#include "MessageManager.h"
#include "SocketManager.h"
namespace network_st {

class TcpSendThread : public QThread
{
	Q_OBJECT
public:
	static TcpSendThread *GetInstance()
    {
        if (!instance_)
        {
			instance_ = new TcpSendThread();
        }
        return instance_;
    }
	TcpSendThread(QObject *parent = 0);
    ~TcpSendThread();
public slots:
	void Slot_NewConnection();
private:
    void Init();
    virtual void run();
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     发送消息给指定客户端
    ************************************/
	bool SendMessage(const QString _ipv4);
public:
	SocketManager *socketManager_;		///<发送线程有单独的socket管理器

	int socketDescriptor_;

private:
    bool is_quit_ = false;

    static TcpSendThread *instance_;

	AddressManager *addressManager_;

	MessageManager *messageManager_;

	QMutex mutex_;

	QTcpServer *tcp_server_;
};
}

#endif // SENDTHREAD_H
