#include "MessageManager.h"

using namespace network_st;

MessageManager *MessageManager::instance_ = nullptr;

MessageManager::MessageManager()
{
	Init();
}

MessageManager::~MessageManager()
{
	mutex_.lock();

	delete queue_sending_message_;         ///<要发送的消息缓存

	queue_sending_message_ = NULL;

	delete queue_received_message_;        ///<接收到的消息缓存

	queue_received_message_ = NULL;

	mutex_.unlock();
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


void MessageManager::AppendSendedMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();

	queue_sending_message_->enqueue(_messageUnit);

	mutex_.unlock();
}

void MessageManager::AppendReceivedMessage(MessageUnit *_messageUnit)
{
	mutex_.lock();

	queue_received_message_->enqueue(_messageUnit);
	/*加入队列*/

	mutex_.unlock();
}

MessageUnit *MessageManager::GetSendingMessage()
{
	mutex_.lock();
	
	if (!queue_sending_message_->isEmpty())
	{
		mutex_.unlock();
	
		return queue_sending_message_->head();
	}
	MessageUnit *messageUnit = new MessageUnit();

	messageUnit->ip = k_default_ip;

	messageUnit->msg = "";

	mutex_.unlock();

	return messageUnit;
}

int MessageManager::GetSizeSendingMessage()
{
	mutex_.lock();

	int size = queue_sending_message_->size();

	mutex_.unlock();

	return size;
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

MessageUnit * network_st::MessageManager::GetNewReceivedMessageUnit()
{
	mutex_.lock();
	
	if (queue_received_message_ && !queue_received_message_->isEmpty())
	{
// 		MessageUnit *messageUnit = queue_received_message_->last();

		MessageUnit *messageUnit = queue_received_message_->dequeue();
		
		mutex_.unlock();
		
		return messageUnit;
	}
	
	mutex_.unlock();
	
	return NULL;

}

