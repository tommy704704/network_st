#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H
/*!
* @file MainSendThread.h
*
* @author 宋涛
* @date 2018/01/04
*
*/
#include <QMutex>
#include <QQueue>
#include <QThread>
#include <QUdpSocket>
#include "Global.h"
namespace network_client_st {

class UdpSendThread : public QThread
{
public:
	UdpSendThread();
	~UdpSendThread();
	static UdpSendThread *GetInstance()
	{
		if (!instance_)
		{
			instance_ = new UdpSendThread();
		}
		return instance_;
	}
	/************************************
	* @Method:    EnqueueReceipt
	* @FullName:  UdpSendThread::EnqueueReceipt
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _message
	* @comment:		添加回执消息队列
	************************************/
	void EnqueueReceipt(QString _message);
	/************************************
	* @Method:    DequeueReceipt
	* @FullName:  UdpSendThread::DequeueReceipt
	* @Access:    public 
	* @Returns:   QString
	* @Qualifier:
	* @comment:		删除已回执的消息
	************************************/
	QString DequeueReceipt();
	/************************************
	* @Method:    PackageReceiptMessage
	* @FullName:  UdpSendThread::PackageReceiptMessage
	* @Access:    public 
	* @Returns:   QT_NAMESPACE::QString
	* @Qualifier:
	* @Parameter: QString _message
	* @comment:		组装回执消息
	************************************/
	QString PackageReceiptMessage(QString _message, bool _is_heartbeat = false);

	QString GetQueueValueByIndex(int _index);

	QString GetQueueLastValue();

	inline void QuitThread() { is_quit_ = true; };
private:
	void Init();

	virtual void run();

protected:
	
private:
	static UdpSendThread *instance_;

	QMutex mutex_;
	QMutex mutex_socket_;

	QQueue<QString> *queue_receipt_messages_;		///<回执的消息队列

	QUdpSocket *udpSocket_heartbeat_send_;

	bool is_quit_;
};
}
#endif