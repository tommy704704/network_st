#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H
/*!
* @file MainSendThread.h
*
* @author ����
* @date 2018/01/04
*
*/
#include <QQueue>
#include <QThread>
#include <QUdpSocket>
#include "Global.h"
namespace network_st {

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
	* @comment:		��ӻ�ִ��Ϣ����
	************************************/
	void EnqueueReceipt(QString _message);
	/************************************
	* @Method:    DequeueReceipt
	* @FullName:  UdpSendThread::DequeueReceipt
	* @Access:    public 
	* @Returns:   QString
	* @Qualifier:
	* @comment:		ɾ���ѻ�ִ����Ϣ
	************************************/
	QString DequeueReceipt();
	/************************************
	* @Method:    PackageReceiptMessage
	* @FullName:  UdpSendThread::PackageReceiptMessage
	* @Access:    public 
	* @Returns:   QT_NAMESPACE::QString
	* @Qualifier:
	* @Parameter: QString _message
	* @comment:		��װ��ִ��Ϣ
	************************************/
	QString PackageReceiptMessage(QString _message, bool _is_heartbeat = false);

	QString GetQueueValueByIndex(int _index);

	QString GetQueueLastValue();
private:
	void Init();

	virtual void run();

protected:
	
private:
	QMutex mutex_;

	QQueue<QString> *queue_receipt_messages_;		///<��ִ����Ϣ����

	QUdpSocket *udpSocket_heartbeat_send_;

	static UdpSendThread *instance_;
};
}
#endif