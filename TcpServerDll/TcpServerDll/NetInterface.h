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

namespace network_server_st {

class AddressManager;
class LogManager;
class TcpReceiveThread;
class TcpSendThread;
class SocketManager;
class MessageManager;
class NewTcpServer;
class UdpReceiveThread;
class UdpSendThread;

class NetInterface : public QObject
{
	Q_OBJECT
public:
    ~NetInterface();
	static NetInterface *GetInstance();
    /************************************
    * @Method:
    * @Access:
    * @Returns:
    * @Qualifier:
    * @Parameter:
    * @comment:     获取队列最新接收消息
    ************************************/
    MessageUnit *GetReceivedNewMessageUnit();
	/************************************
	* @Method:    GetAllClient
	* @FullName:  network_server_st::NetInterface::GetAllClient
	* @Access:    public 
	* @Returns:   QList<Client *> *
	* @Qualifier:
	* @comment: 获取所有客户端
	************************************/
	QList<Client *> *GetAllClient();
	/************************************
	* @Method:    AddMessageToSend
	* @FullName:  network_server_st::NetInterface::AddMessageToSend
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: MessageUnit * _messageUnit
	* @comment: 增加消息到发送队列
	************************************/
	void AddMessageToSend(MessageUnit *_messageUnit);
	/************************************
	* @Method:    RemoveSendMessage
	* @FullName:  network_server_st::NetInterface::RemoveSendMessage
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: char * _msg
	* @comment: 从发送队列删除消息
	************************************/
	void RemoveSendMessage(char *_msg);
	/************************************
	* @Method:    AddClientAddress
	* @FullName:  network_server_st::NetInterface::AddClientAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: Client * _client
	* @comment: 手动增加客户端地址
	************************************/
	void AddClientAddress(Client *_client);
	/************************************
	* @Method:    RemoveClientAddress
	* @FullName:  network_server_st::NetInterface::RemoveClientAddress
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: int _index
	* @comment: 手动删除地址
	************************************/
	void RemoveClientAddress(int _index);
private:
    NetInterface();
    void Init();
    void CreateSignalAndSlot();

	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     广播
	************************************/
	void BroadcastMessage();
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     发送消息给指定客户端
	************************************/
	void SendMessage(MessageUnit *_messageUnit);
	/************************************
	* @Method:
	* @Access:
	* @Returns:
	* @Qualifier:
	* @Parameter:
	* @comment:     应用已取走并成功处理了消息，队列删除消息
	************************************/
	void HadHandleMessage();

private slots:
    void Slot_ReceivedMessage(MessageUnit *_messageUnit);

	void Slot_UpdateOfflineSocket(QList<Client *> *_clients);
signals:
    void Signal_ReceivedMessage(MessageUnit *_messageUnit);

	void Signal_UpdateUIReplyTcpMsg(MessageUnit *_messageUnit);
	//通知UI更新tcp回复表格

	void Signal_UpdateAddressList(Client *_client);

	void Signal_UpdateOfflineAddressList(QList<Client *> *_clients);

private:
    static NetInterface *instance_;

	NewTcpServer *tcpServer_;

	AddressManager *addressManager_;
	
	LogManager *logManager_;
	
	MessageManager *messageManager_;
	
	SocketManager *socketManager_;
	
	TcpSendThread *TcpSendThread_;
	
	TcpReceiveThread *tcpReceiveThread_;
	
	UdpReceiveThread *udpReceiveThread_;
	
	UdpSendThread *udpSendThread_;
};

}

#endif // NETINTERFACE_H
