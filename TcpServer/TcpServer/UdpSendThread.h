#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H
/************************************!
 * @file UdpSendThread.h
 *
 * @author ����
 * @date 2018/03/08
 *
 * 
 ************************************/
#include <QThread>
#include <QUdpSocket>
#include "AddressManager.h"
#include "SocketManager.h"
#include "Global.h"
/************************************!
 * @class 
 *
 * @brief 
 *
 * @author ����
 * @date 2018/03/08
 ************************************/
namespace network_st{
class UdpSendThread : public QThread
{
	Q_OBJECT
public:
	static UdpSendThread *GetInstance()
	{
		if (!s_instance_)
		{
			s_instance_ = new UdpSendThread();
		}
		return s_instance_;
	}
	UdpSendThread();
	~UdpSendThread();

	void BroadcastAllOnlineClient();

	/************************************
	* @Method:    NoticeClientClearTcpConnect
	* @FullName:  network_st::UdpSendThread::NoticeClientClearTcpConnect
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: ֪ͨ�ͻ�������tcp����
	************************************/
	void NoticeClientClearTcpConnect();
signals:
	void Signal_UpdateOfflineAddressList(QList<Client *> *_clients);

protected:
private:
	void Init();
	void virtual run();

private:
	static UdpSendThread *s_instance_;

	AddressManager *addressManager_;

	bool is_quit_;

	QMutex mutex_;

	QUdpSocket *udpSocket_send_heartbeat_;

	SocketManager *socketManager_;
};
}
#endif