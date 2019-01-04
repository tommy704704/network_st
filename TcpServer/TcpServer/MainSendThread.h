#ifndef MAINSENDTHREAD_H
#define MAINSENDTHREAD_H
/*!
 * @file MainSendThread.h
 *
 * @author 宋涛
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
	QUdpSocket *udp_server_send_;		///<服务端socket
	MessageManager *messageManager_;
	AddressManager *addressManager_;
	QMutex mutex_;
	QString address_;
	QueryThread *queryThread_;			///<轮询线程
	UdpReceiveThread *udpReceiveThread_;			///<客户端监控线程
};
}
#endif