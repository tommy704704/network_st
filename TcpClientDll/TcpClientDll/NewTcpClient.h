#ifndef NEWTCPCLIENT_H
#define NEWTCPCLIENT_H
/************************************!
 * @file NewTcpClient.h
 *
 * @author 宋涛
 * @date 2018/03/06
 *
 * 
 ************************************/
#include <QObject>
#include <QTcpSocket>
#include "LogManager.h"
#include "SocketManager.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
namespace network_client_st{
/************************************!
 * @class 
 *
 * @brief 
 *
 * @author 宋涛
 * @date 2018/03/06
 ************************************/
class NewTcpClient : public QObject
{
	Q_OBJECT
public:
	static NewTcpClient *GetInstance()
	{
		if (!s_instance_)
		{
			s_instance_ = new NewTcpClient();
		}
		return s_instance_;
	}
	NewTcpClient();
	~NewTcpClient();
protected:
private:
	void CreateSignalAndSLot();
	void Init();

	QString GetConnectionInfromation(const int _type);

public slots:
	void Slot_BindNewTcpConnection();
	void Slot_Connected();
	void Slot_DisplayError(QAbstractSocket::SocketError error);
	void Slot_Disconnected();
	void Slot_GetServerAddress();
	void Slot_StateChanged(QAbstractSocket::SocketState _socketState);
signals:
	void Signal_UpdateUITcpReceivedMessage(MessageUnit *_messageUnit);
private:
	static NewTcpClient *s_instance_;

	LogManager *logManager_;

	SocketManager *socketManager_;
	
	TcpReceiveThread *tcpReceiveThread_;

	TcpSendThread *tcpSendThread_;

	QTcpSocket *tcpSocket_connectToServer_;
};
}
#endif