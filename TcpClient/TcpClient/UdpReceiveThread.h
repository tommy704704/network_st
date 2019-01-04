#ifndef UDPRECEIVETHREAD_H
#define UDPRECEIVETHREAD_H
/*!
* @file MainSendThread.h
*
* @author ËÎÌÎ
* @date 2018/01/04
*
*/
#include <QThread>
#include <QUdpSocket>
#include "Global.h"
#include "UdpSendThread.h"
namespace network_st {
class SocketManager;
class TcpReceiveThread;

class UdpReceiveThread : public QThread
{
	Q_OBJECT
public:
	UdpReceiveThread();
	~UdpReceiveThread();
	void Init();
	virtual void run();
protected:
signals :
	void Signal_AddReceivedMessage(QString _message);
	void Signal_BindNewTcpConnection();
	void Signal_GetServerAddress();
	void Signal_DisconnectTcpFromHost(QString _ip);
public slots :
	void ReadPendingDatagrams();
	
private:
	SocketManager *socketManager_;

	QUdpSocket *udpSocket_heartbeat_receive_;			///<ÐÄÌø

	UdpSendThread *udpSendThread_;
};
}
#endif