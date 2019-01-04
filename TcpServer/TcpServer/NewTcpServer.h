#ifndef TCPSERVER_H
#define TCPSERVER_H
/************************************!
 * @file global.h
 *
 * @author 宋涛
 * @date 2018/2/2
 *
 ************************************/
#include <QMap>
#include <QTcpServer>
#include <QTcpSocket>
#include "AddressManager.h"
#include "Global.h"
#include "LogManager.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "SocketManager.h"
namespace network_st {

class NewTcpServer : public QObject
{
    Q_OBJECT
public:
    /************************************
    * @Method:  GetInstance
    * @Access:
    * @Returns:    NewTcpServer *
    * @Qualifier:
    * @Parameter:
    * @comment:
    ************************************/
    static NewTcpServer *GetInstance()
    {
        if (!instance_)
        {
            instance_ = new NewTcpServer();
        }
        return instance_;
    };
    ~NewTcpServer();
// protected:
// 	void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
private slots:
    void Slot_NewConnection();
	void Slot_Disconnected();
	void Slot_DisplayError(QAbstractSocket::SocketError _error);
	void Slot_StateChanged(QAbstractSocket::SocketState _socketState);

private:
	NewTcpServer(QObject *parent = 0);
    void CreateSignalAndSlot();
    void Init();
private:
    static NewTcpServer *instance_;

    QTcpServer *tcp_server_;

    TcpReceiveThread *tcpReceiveThread_;

    TcpSendThread *tcpSendThread_;

	AddressManager *addressManager_;

	LogManager *logManager_;

    SocketManager *socketManager_;
};

}

#endif // TCPSERVER_H

