#include "MessageManager.h"
using namespace network_st;

MessageManager *MessageManager::instance_ = nullptr;
MessageManager::MessageManager()
{
	Init();
}

MessageManager::~MessageManager()
{
	delete queue_sending_message_;         ///<Ҫ���͵���Ϣ����

	queue_sending_message_ = NULL;

	delete queue_received_message_;        ///<���յ�����Ϣ����

	queue_received_message_ = NULL;

}

void MessageManager::Init()
{
	queue_sending_message_ = new QQueue<MessageUnit *>();

	queue_received_message_ = new QQueue<MessageUnit *>();

}

void MessageManager::RemoveSendedMessage()
{
	mutex_.lock();
	if (!queue_sending_message_->isEmpty())
	{
		queue_sending_message_->dequeue();
	}
	mutex_.unlock();
}

void MessageManager::RemoveReceivedMessage()
{
	mutex_.lock();
	if (!queue_received_message_->isEmpty())
	{
		queue_received_message_->dequeue();
	}
	mutex_.unlock();
}


MessageUnit * MessageManager::AppendSendedReceiptMessage(MessageUnit *_messageUnit)
{
	MessageUnit *messageUnit_send = new MessageUnit();

	QString receive_message = QString::fromLocal8Bit(_messageUnit->msg);

	QString send_message = QString("%1%2").arg("Ark_").arg(receive_message);
	//���ӻ�ִ���

	messageUnit_send->ip = _messageUnit->ip;

	QByteArray *byteArray_msg = new QByteArray(send_message.toLocal8Bit());

	messageUnit_send->byteArray_msg= byteArray_msg;

	messageUnit_send->msg = byteArray_msg->data();

	mutex_.lock();

	queue_sending_message_->enqueue(messageUnit_send);
	//���뷢�Ͷ���β

	mutex_.unlock();

	return messageUnit_send;
}

void MessageManager::AppendReceivedMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();
	queue_received_message_->enqueue(_messageUnit);
	/*�������*/
	mutex_.unlock();
}

MessageUnit *MessageManager::GetSendingMessage()
{
	mutex_.lock();
	if (!queue_sending_message_->isEmpty())
	{
		mutex_.unlock();
		return queue_sending_message_->dequeue();
	}
	mutex_.unlock();
	return NULL;
}

int MessageManager::GetSizeSendingMessage()
{
	int size = queue_sending_message_->size();
	int result = size >= 0 ? size : 0;
	return result;
}

void MessageManager::RemoveSendMessage(char *_msg)
{
	mutex_.lock();
	int size = queue_sending_message_->size();
	for (int i = 0; i < size;i++)
	{
		MessageUnit *messageUnit = queue_sending_message_->at(i);
		if (messageUnit->msg == _msg)
		{
			queue_sending_message_->takeAt(i);
			mutex_.unlock();
			return;
		}
	}
	mutex_.unlock();
}

void network_st::MessageManager::AddSendMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();
	queue_sending_message_->enqueue(_messageUnit);
	//���뷢�Ͷ���β
	mutex_.unlock();
}

MessageUnit * network_st::MessageManager::GetReceivedMessage()
{
	mutex_.lock();
	if (!queue_received_message_->isEmpty())
	{
		mutex_.unlock();
		return queue_received_message_->dequeue();
	}
	mutex_.unlock();
	return NULL;
}
