#ifndef MAINSENDTHREAD_H
#define MAINSENDTHREAD_H
/*!
 * @file MainSendThread.h
 *
 * @author ����
 * @date 2018/01/04
 * 
 */
#include <QUdpSocket>
#include <QThread>
#include <QVector>
#include "AddressManager.h"
#include "Global.h"
#include "MessageManager.h"
#include "QueryThread.h"
#include "UdpReceiveThread.h"
namespace network_st{

class MainSendThread : public QThread
{
public:
	MainSendThread();
	~MainSendThread();

protected:
private:
	void Init();
	virtual void run();
private:
	QUdpSocket *udp_server_send_;		///<�����socket
	MessageManager *messageManager_;
	AddressManager *addressManager_;
	QMutex mutex_;
	QString address_;
	QueryThread *queryThread_;			///<��ѯ�߳�
	UdpReceiveThread *udpReceiveThread_;			///<�ͻ��˼���߳�
};
}
#endif