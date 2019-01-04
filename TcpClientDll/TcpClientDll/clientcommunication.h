#ifndef CLIENTCOMMUNICATION_H
#define CLIENTCOMMUNICATION_H
/*!
* @file MainSendThread.h
*
* @author кнлн
* @date 2018/01/04
*
*/
#include <QtWidgets/QWidget>
#include "LogManager.h"
#include "NewTcpClient.h"
#include "NetInterface.h"
#include "SocketManager.h"
#include "UdpReceiveThread.h"
#include "TcpReceiveThread.h"
#include "TcpSendThread.h"
#include "ui_clientcommunication.h"
namespace network_st {

class UdpSendThread;
class ClientCommunication : public QWidget
{
	Q_OBJECT

public:
	ClientCommunication(QWidget *parent = 0);
	~ClientCommunication();
	void Init();
	public slots:
	void Slot_AddReceivedMessage(QString _message);
	void Slot_UpdateUITcpReceivedMessage(MessageUnit *_messageUnit);
	void Slot_UpdateUITcpReplyMessage(MessageUnit *_messageUnit);
private:
	Ui::ClientCommunicationClass ui_;

	NetInterface *netInterface_;
};
}

#endif // CLIENTCOMMUNICATION_H
