#ifndef TCPRECEIVETHREAD_H
#define TCPRECEIVETHREAD_H
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QThread>
#include "Global.h"

namespace network_st {
class MessageManager;

class SocketManager;

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
	void Signal_UpdateUITcpReceivedMessage(MessageUnit *_messageUnit);
	void Signal_SendMessage(MessageUnit *_messageUnit);
public slots:
	void Slot_ReadMessage();
protected:
	
private:
	TcpReceiveThread();
	void CreateSignalAndSlot();
	void Init();
	virtual void run();

private:
	static TcpReceiveThread *instance_;


	QString receive_message_;  ///<��Ŵӷ��������յ����ַ���

	quint16 blockSize_;  ///<����ļ��Ĵ�С��Ϣ

	MessageManager *messageManager_;

	SocketManager *socketManager_;
};
}
#endif