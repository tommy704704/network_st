#ifndef TCPSENDTHREAD_H
#define TCPSENDTHREAD_H
#include <QMutex>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QThread>
#include "Global.h"

namespace network_st {

class MessageManager;

class SocketManager;

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
	~TcpSendThread();
signals:
	void Signal_SendMessage(MessageUnit *_messageUnit);

	void Signal_UpdateUITcpReplyMessage(MessageUnit *_messageUnit);

	public slots:
	void Slot_SendMessage(MessageUnit *_messageUnit);
protected:

private:
	TcpSendThread();

	void CreateSignalAndSlot();

	void Init();

	virtual void run();

private:
	static TcpSendThread *instance_;

	QTcpSocket *tcpSocket_client_;

	bool is_quit_;

	QString ipv4_;

	QString receive_message_;  ///<存放从服务器接收到的字符串

	quint16 blockSize_;  ///<存放文件的大小信息

	MessageManager *messageManager_;

	SocketManager *socketManager_;

	QMutex mutex_;
};
}
#endif