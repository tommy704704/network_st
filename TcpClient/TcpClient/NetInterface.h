#ifndef NETINTERFACE_H
#define NETINTERFACE_H
/************************************!
 * @file global.h
 *
 * @author 宋涛
 * @date 2018/2/2
 *
 ************************************/
#include <QTcpSocket>
#include "Global.h"

namespace network_st {

class UdpReceiveThread;
class UdpSendThread;
class TcpReceiveThread;
class TcpSendThread;

class LogManager;
class MessageManager;
class SocketManager;

class NewTcpClient;

class NetInterface : public QObject
{
    Q_OBJECT
public:
    ~NetInterface();
    static NetInterface *GetInstance()
    {
        if (!instance_)
        {
            instance_ = new NetInterface();
        }
        return instance_;
    }

	/************************************
	* @Method:    GetReceiveNewMessage
	* @FullName:  network_st::NetInterface::GetReceiveNewMessage
	* @Access:    public 
	* @Returns:   MessageUnit *
	* @Qualifier:
	* @comment: 取最新接收的消息
	************************************/
	MessageUnit * GetReceiveNewMessage();
	/************************************
	* @Method:    AddSendMessage
	* @FullName:  network_st::NetInterface::AddSendMessage
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: 添加要发送的消息到消息队列
	************************************/
	void AddSendMessage(MessageUnit *_messageUnit);
private:
    NetInterface();

    void Init();

    void CreateSignalAndSlot();

private slots:
	void Slot_RemoveSendedTcpSocketFromConnected(QString _ip);
signals:
	void Signal_UpdateUITcpReplyMessage(MessageUnit *_messageUnit);

    void Signal_UpdateUITcpReceivedMessage(MessageUnit *_messageUnit);

	void Signal_GetServerAddress();

	void Signal_AddReceivedMessage(QString _message);

	void Signal_BindNewTcpConnection();


private:
    static NetInterface *instance_;

	UdpReceiveThread *udpReceiveThread_;

	UdpSendThread *udpSendThread_;

	TcpSendThread *tcpSendThread_;

	LogManager *logManager_;

	MessageManager *messageManager_;

	SocketManager *socketManager_;

	NewTcpClient *tcpClient_;

};

}

#endif // NETINTERFACE_H
