#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H
/************************************!
 * @file UdpSendThread.h
 *
 * @author 宋涛
 * @date 2018/03/08
 *
 * 
 ************************************/
#include <QThread>
#include <QUdpSocket>
#include "AddressManager.h"
#include "SocketManager.h"
/************************************!
 * @class 
 *
 * @brief 
 *
 * @author 宋涛
 * @date 2018/03/08
 ************************************/
namespace network_server_st{
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
	* @FullName:  network_server_st::UdpSendThread::NoticeClientClearTcpConnect
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 通知客户端清理tcp连接
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