#ifndef SERVERCOMMUNICATION_H
#define SERVERCOMMUNICATION_H
/*!
* @file AddressManager.h
*
* @author 宋涛
* @date 2018/01/04
*
*
*/
#include <QtWidgets/QWidget>
#include "AddressManager.h"
#include "LogManager.h"
#include "MainSendThread.h"
#include "MessageManager.h"
#include "NetInterface.h"
#include "UdpReceiveThread.h"
#include "UdpSendThread.h"
#include "TcpReceiveThread.h"
#include "SocketManager.h"
#include "ui_servercommunication.h"
namespace network_st{

class ServerCommunication : public QWidget
{
	Q_OBJECT

public:
	ServerCommunication(QWidget *parent = 0);
	~ServerCommunication();
	void CreateSignalAndSlot();
	void Init();
private:

private slots:
	void Slot_ClickAdd(bool checked = false);
	void Slot_ClickDelete(bool checked = false);
	void Slot_ClickAddAddress(bool checked = false);
	void Slot_ClickDeleteAddress(bool checked = false);
	void Slot_ClickAutomaticGenerate(bool checked = false);
	void Slot_ClickSend(bool checked = false);
	void SLot_ClickStop(bool checked = false);
	void Slot_ClickItemSendList(QListWidgetItem * item);
	void Slot_ClickCellAddressList(int row, int column);

	void Slot_Receipt(MessageUnit *_messageUnit);

	void Slot_TimeOut();

	void Slot_UpdateAddressList(Client *_client);

	void Slot_UpdateOfflineClientList(QList<Client *> *_clients);
private:
	Ui::ServerCommunicationClass ui_;

	int current_address_rowIndex_;

	AddressManager *addressManager_;
	LogManager *logManager_;
	MessageManager *messageManager_;
	SocketManager *socketManager_;

	MainSendThread *send_thread_;
	TcpReceiveThread *receive_thread_;
	UdpReceiveThread *udpReceiveThread_;
	UdpSendThread *udpSendThread_;

	bool is_automatic_send_;

	QMutex mutex_;

	NetInterface *netInterface_;

	QTimer *timer_;			///<模拟发送定时器
};
}

#endif // SERVERCOMMUNICATION_H
