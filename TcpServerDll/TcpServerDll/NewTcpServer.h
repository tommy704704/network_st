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
#include "MessageManager.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "SocketManager.h"
namespace network_server_st {

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
	QTcpServer *Get_TcpServer();
// protected:
// 	void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

	public slots:
	bool Slot_SendTcpMessage(const QString _ipv4);
	void Slot_RemoveSendedMessage();

private slots:
    void Slot_NewConnection();
	void Slot_Disconnected();
	void Slot_DisplayError(QAbstractSocket::SocketError _error);
	void Slot_StateChanged(QAbstractSocket::SocketState _socketState);

private:
	NewTcpServer(QObject *parent = 0);
    void CreateSignalAndSlot();
    void Init();

	QString GetConnectionInfromation(const int _type);
private:
    static NewTcpServer *instance_;

    QTcpServer *tcp_server_;

    TcpReceiveThread *tcpReceiveThread_;

    TcpSendThread *tcpSendThread_;

	AddressManager *addressManager_;

	MessageManager *messageManager_;

	LogManager *logManager_;

    SocketManager *socketManager_;
};

}

#endif // TCPSERVER_H

