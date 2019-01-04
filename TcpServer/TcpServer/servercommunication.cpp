#include <QTimer>
#include <QDateTime>
#include "QueryThread.h"
#include "servercommunication.h"
using namespace network_st;

extern QString g_local_ip;
extern QString g_sender_ip;

ServerCommunication::ServerCommunication(QWidget *parent)
	: QWidget(parent), is_automatic_send_(false)
{
	ui_.setupUi(this);

	Init();
}

ServerCommunication::~ServerCommunication()
{
// 	delete logManager_;
}

void ServerCommunication::CreateSignalAndSlot()
{
	connect(ui_.pushButton_add_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickAdd(bool)));
	
	connect(ui_.pushButton_delete_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickDelete(bool)));
	
	connect(ui_.pushButton_add_address_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickAddAddress(bool)));
	
	connect(ui_.pushButton_delete_address_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickDeleteAddress(bool)));
	
	connect(ui_.pushButton_automatic_generate_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickAutomaticGenerate(bool)));
	
	connect(ui_.pushButton_send_, SIGNAL(clicked(bool)), this, SLOT(Slot_ClickSend(bool)));
	
	connect(ui_.pushButton_stop_, SIGNAL(clicked(bool)), this, SLOT(SLot_ClickStop(bool)));
	
	connect(ui_.listWidget_sendMessage_, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(Slot_ClickItemSendList(QListWidgetItem *)));
	
	connect(ui_.tableWidget_address_, SIGNAL(cellClicked(int, int)), this, SLOT(Slot_ClickCellAddressList(int, int)));

// 	bool is_ok = connect(receive_thread_
// 		, SIGNAL(Signal_AddReceivedMessage(Message))
// 		, this
// 		, SLOT(Slot_Receipt(Message))
// 		, Qt::DirectConnection);

	bool is_ok = connect(netInterface_
		, SIGNAL(Signal_UpdateAddressList(Client *))
		, this
		, SLOT(Slot_UpdateAddressList(Client *))
		, Qt::DirectConnection);

	is_ok = connect(netInterface_
		, SIGNAL(Signal_UpdateOfflineAddressList(QList<Client *> *))
		, this
		, SLOT(Slot_UpdateOfflineClientList(QList<Client *> *))
		, Qt::DirectConnection);

	is_ok = connect(netInterface_
		, SIGNAL(Signal_UpdateUIReplyTcpMsg(MessageUnit *))
		, this
		, SLOT(Slot_Receipt(MessageUnit *)));

	is_ok = connect(timer_
		, SIGNAL(timeout())
		, this
		, SLOT(Slot_TimeOut()));

}

void ServerCommunication::Init()
{
// 	SetStreamHandle(false);


	timer_ = new QTimer();

	netInterface_ = NetInterface::GetInstance();

	CreateSignalAndSlot();
}

void ServerCommunication::Slot_ClickAdd(bool checked)
{
	QString qs_message;

	char *c_msg = "中文msg: ";

	qs_message = QString::fromLocal8Bit(c_msg);
	
	QString msg = qs_message + QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss:zzz");

	ui_.listWidget_sendMessage_->addItem(msg);

	MessageUnit *messageUnit = new MessageUnit();

// 	messageUnit->ip = g_local_ip;

	QByteArray *byteArray_msg = new QByteArray(msg.toLocal8Bit());

	messageUnit->msg = byteArray_msg->data();


	QByteArray *bb = new QByteArray;
	QDataStream data(bb, QIODevice::WriteOnly);
// 	data << double(5.6) << "aaa" << "7*8.23";
	data << "parameter001" << "-head-" << "parameter003";

	messageUnit->byteArray_msg = bb/*byteArray_msg*/;

// 	messageManager_->AppendSendedMessage(messageUnit);			///<ui和队列同步增加操作

	netInterface_->AddMessageToSend(messageUnit);
}

void ServerCommunication::Slot_ClickDelete(bool checked)
{
	int current_row = ui_.listWidget_sendMessage_->currentRow();
	
	if (current_row >= 0)
	{
		char *msg = ui_.listWidget_sendMessage_->item(current_row)->text().toLocal8Bit().data();

		ui_.listWidget_sendMessage_->takeItem(current_row);

		///<ui和队列同步删除操作
// 		messageManager_->RemoveSendMessage(msg);

		netInterface_->RemoveSendMessage(msg);
	}
}

void ServerCommunication::Slot_ClickAddAddress(bool checked /*= false*/)
{
	int count_rows = ui_.tableWidget_address_->rowCount();

	ui_.tableWidget_address_->insertRow(count_rows);

	QTableWidgetItem *item_status = new QTableWidgetItem();
	
	item_status->setData(Qt::DisplayRole, 0);
	
	QTableWidgetItem *item_ip = new QTableWidgetItem();
	
	item_ip->setData(Qt::DisplayRole, "192.168.0.171");
	
	ui_.tableWidget_address_->setItem(count_rows, 0, item_ip);
	
	ui_.tableWidget_address_->setItem(count_rows, 1, item_status);
	
	mutex_.lock();
	
	Client *client = new Client();
	
	client->ipv4 = "192.168.0.171";

// 	addressManager_->list_client_->append(client);		///<ui和地址列表同步增加操作
	
	netInterface_->AddClientAddress(client);
	
	mutex_.unlock();
}

void ServerCommunication::Slot_ClickDeleteAddress(bool checked /*= false*/)
{
	if (current_address_rowIndex_ >= 0)
	{
		ui_.tableWidget_address_->removeRow(current_address_rowIndex_);
	
		mutex_.lock();

// 		addressManager_->list_client_->removeAt(current_address_rowIndex_);		///<ui和地址列表同步删除操作

		netInterface_->RemoveClientAddress(current_address_rowIndex_);

		mutex_.unlock();
	}
}

void ServerCommunication::Slot_ClickAutomaticGenerate(bool checked)
{
	is_automatic_send_ = is_automatic_send_ ? false : true;

	if (is_automatic_send_)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

		int random = qrand() % 10;

		timer_->setInterval(random * 100);

		timer_->start();
	}
	else
	{
		timer_->stop();
	}
}

void ServerCommunication::Slot_ClickSend(bool checked)
{
	UdpReceiveThread::GetInstance()->GetOnlineClient();
}

void ServerCommunication::SLot_ClickStop(bool checked)
{

}

void ServerCommunication::Slot_ClickItemSendList(QListWidgetItem * item)
{
}

void ServerCommunication::Slot_ClickCellAddressList(int row, int column)
{
	current_address_rowIndex_ = row;
}

void ServerCommunication::Slot_Receipt(MessageUnit *_messageUnit)
{
	/*更新接收列表*/

	int row_count = ui_.tableWidget_ReceivedMessage_->rowCount();

	ui_.tableWidget_ReceivedMessage_->insertRow(row_count);

	QTableWidgetItem * item_ip = new QTableWidgetItem();

	item_ip->setData(Qt::DisplayRole, _messageUnit->ip);

	QTableWidgetItem * item_msg = new QTableWidgetItem();

	item_msg->setData(Qt::DisplayRole, QString::fromLocal8Bit(_messageUnit->msg));

	ui_.tableWidget_ReceivedMessage_->setItem(row_count, 0, item_ip);

	ui_.tableWidget_ReceivedMessage_->setItem(row_count, 1, item_msg);
	
	ui_.tableWidget_ReceivedMessage_->resizeColumnsToContents();
}

void ServerCommunication::Slot_UpdateAddressList(Client *_client)
{
	/*更新UI地址列表*/

	int count_rows = ui_.tableWidget_address_->rowCount();

	bool is_found = false;

	QString ipv4 = _client->ipv4;

	for (int i = 0; i < count_rows; i++)
	{
		QTableWidgetItem *item_ipv4 = ui_.tableWidget_address_->item(i, 0);

		QString current_item_ipv4 = item_ipv4->text();

		if (current_item_ipv4 == ipv4)
		{
			/*更新已有客户端*/

			QTableWidgetItem *item_status = new QTableWidgetItem();

			item_status->setData(Qt::DisplayRole, "1");

			ui_.tableWidget_address_->setItem(i, 1, item_status);

			is_found = true;

			return;
		}
	}
	if (!is_found)
	{
		QTableWidgetItem *item_ip = new QTableWidgetItem();

		item_ip->setData(Qt::DisplayRole, ipv4);

		QTableWidgetItem *item_status = new QTableWidgetItem();

		item_status->setData(Qt::DisplayRole, "1");

		ui_.tableWidget_address_->insertRow(count_rows);
		/*在列表最后新增到地址*/

		ui_.tableWidget_address_->setItem(count_rows, 0, item_ip);

		ui_.tableWidget_address_->setItem(count_rows, 1, item_status);
	}
}

void network_st::ServerCommunication::Slot_UpdateOfflineClientList(QList<Client *> *_clients)
{
	/*更新下线客户端UI状态*/

	int size_client_offline = _clients->size();

	int count_rows = ui_.tableWidget_address_->rowCount();

	for (int i = 0; i < size_client_offline; i++)
	{
		Client *client = _clients->at(i);

		QString ipv4 = client->ipv4;

		for (int j = 0; j < count_rows; j++)
		{
			QTableWidgetItem *item_ipv4 = ui_.tableWidget_address_->item(j, 0);

			QString current_item_ipv4 = item_ipv4->text();

			if (current_item_ipv4 == ipv4)
			{
				QTableWidgetItem *item_status = new QTableWidgetItem();

				item_status->setData(Qt::DisplayRole, "0");

				ui_.tableWidget_address_->setItem(j, 1, item_status);
			}
		}
	}
}

void network_st::ServerCommunication::Slot_TimeOut()
{
	Slot_ClickAdd();

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

	int random = qrand() % 10;

	timer_->setInterval(random * 10);

}
