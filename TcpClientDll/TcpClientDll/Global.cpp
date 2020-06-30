#include "Global.h"

using namespace network_client_st;
QString network_client_st::k_keepAlive = "KeepAlive";					///<默认心跳询问包

QString network_client_st::k_receipt_keepAlive = "Ark_KeepAlive";		///<默认心跳回执包
QMap<QString, QByteArray> k_temp_big_bytes_map_;

bool is_out_log_ = false;
///<全局是否输出debug

QString g_local_ip = k_default_ip;			///<本地IP

QString g_server_ip = k_default_ip;			///<服务端IP

bool g_is_stream_handle = true;
int client_timeout_ = k_client_timeout_;					///<设置的超时值
int broadcast_interval_ = k_broadcast_interval_;			///<广播发送的默认间隔3，单位秒

bool network_client_st::IsStreamHandle()
{
	return g_is_stream_handle;
}

void network_client_st::SetStreamHandle(bool _is_stream_handle)
{
	g_is_stream_handle = _is_stream_handle;
}
int network_client_st::GetBroadcastInterval()
{
	return broadcast_interval_;
}
int network_client_st::GetTimeout()
{
	return client_timeout_;
}

bool network_client_st::SetHeartServer(QString _heartValue)
{
	k_keepAlive = _heartValue;					///<心跳询问包

	k_receipt_keepAlive = QString("%1%2").arg("Ark_").arg(_heartValue);		///<心跳回执包

	return true;
}

QString network_client_st::GetLocalIP()
{
	qDebug() << "GetLocalIP()";

	if (g_local_ip != k_default_ip)
	{
		qDebug() << "GetLocalIP() return ip: " << g_local_ip;
		return g_local_ip;
	}

	///<获取本地IP片地址

	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	///<获取第一个本主机的IPv4地址  
	int size_address = ipAddressesList.size();
	for (int i = 0; i < size_address; ++i)
	{
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
			ipAddressesList.at(i).toIPv4Address())
		{
			g_local_ip = ipAddressesList.at(i).toString();
			qDebug() << "ipv4: " << ipAddressesList.at(i).toString();
			continue;
		}
		qDebug() << ipAddressesList.at(i).toString();
	}
	///<如果没有找到，则以本地IP地址为IP  
	if (k_default_ip == g_local_ip)
		g_local_ip = QHostAddress(QHostAddress::LocalHost).toString();

	qDebug() << "GetLocalIP() return ip: " << g_local_ip;

	return g_local_ip;





// 	QList<QHostAddress> addList = QNetworkInterface::allAddresses();
// 
// 	foreach(QHostAddress address, addList)
// 	{
// 		/*排除IPV6，排除回环地址 */
// 		if (address.protocol() == QAbstractSocket::IPv4Protocol
// 			&& address != QHostAddress(QHostAddress::LocalHost))
// 		{
// 			/*输出，转换为字符串格式 */
// 			qDebug() << address.toString();
// 
// 			local_ip = address.toString();
// 
// 			return local_ip;
// 		}
// 	}
// 	return local_ip;

}

QByteArray GetWholeBytes(QString _ip, QByteArray _bytes, bool _is_receive_over)
{
	if (_is_receive_over)
	{
		if (k_temp_big_bytes_map_.contains(_ip))
		{
			QByteArray result(k_temp_big_bytes_map_.value(_ip));
			result.append(_bytes);
			k_temp_big_bytes_map_.remove(_ip);
			return result;
		}
		else
		{
			return _bytes;
		}
	}
	else
	{
		if (k_temp_big_bytes_map_.contains(_ip))
		{
			QByteArray result(k_temp_big_bytes_map_.value(_ip));
			result.append(_bytes);
			return result;
		}
		else
		{
			k_temp_big_bytes_map_.insert(_ip, _bytes);
		}

	}
}


void RemoveHeadFromByteArray(QList<MessageUnit *> *_list_messageUnit, QByteArray _byteArray_message, QString _ip)
{
	QString qstring_head = k_header_message;

	QByteArray byteArray_head = qstring_head.toLocal8Bit();

	char *c_head = byteArray_head.data();

	int count_head = _byteArray_message.count(c_head);

	if (0 == count_head)
	{
		/////////////////////////////////////////////////////////////////////////////
		QByteArray *result_bytes = nullptr;
		QByteArray temp_bytes(_byteArray_message);
		bool is_receive_over = true;
		if (QString(temp_bytes).contains(k_end_message_))
		{
			int size_end_flag = k_end_message_.size();
			int size = temp_bytes.size();
			int left_size = size - size_end_flag;
			result_bytes = new QByteArray(GetWholeBytes(_ip, temp_bytes.left(left_size), is_receive_over));
		}
		else
		{
			is_receive_over = false;
			result_bytes = &(GetWholeBytes(_ip, temp_bytes, is_receive_over));
		}
		///<去掉结尾标识
		//////////////////////////////////////////////////////////////////////////

		if (is_receive_over)
		{
			MessageUnit * messageUnit_receive = new MessageUnit();
			//说明已不包含头，不用截取
			messageUnit_receive->byteArray_msg = result_bytes/*byteArray_message_nohead*/;

			messageUnit_receive->msg = /*byteArray_message_nohead*/result_bytes->data();

			_list_messageUnit->append(messageUnit_receive);
		}
		return;
	}


	for (int i = 0; i < count_head * 2; i++)
	{

		int head_occur_index = _byteArray_message.indexOf(k_header_message, 0);

		if (0 == head_occur_index)
		{
			QByteArray *byteArray_message_nohead = new QByteArray(_byteArray_message.remove(0, k_header_message.size()));
			///<去掉最前面的头
			
			continue;
		}

		MessageUnit * messageUnit_receive = new MessageUnit();

		QByteArray *byteArray_message_nohead = new QByteArray(_byteArray_message);

		if (head_occur_index < 0)
		{
			/////////////////////////////////////////////////////////////////////////////
			QByteArray *result_bytes = nullptr;
			bool is_receive_over = true;
			if (QString(*byteArray_message_nohead).contains(k_end_message_))
			{
				int size_end_flag = k_end_message_.size();
				int size = byteArray_message_nohead->size();
				int left_size = size - size_end_flag;
				result_bytes = new QByteArray(GetWholeBytes(_ip, byteArray_message_nohead->left(left_size), is_receive_over));
			}
			else
			{
				is_receive_over = false;
				result_bytes = new QByteArray((GetWholeBytes(_ip, *byteArray_message_nohead, is_receive_over)));
			}
			///<去掉结尾标识
			//////////////////////////////////////////////////////////////////////////


			if (is_receive_over)
			{
				//说明已不包含头，不用截取
				messageUnit_receive->byteArray_msg = result_bytes/*byteArray_message_nohead*/;

				messageUnit_receive->msg = /*byteArray_message_nohead*/result_bytes->data();

				_list_messageUnit->append(messageUnit_receive);
			}
		}
		else
		{
			byteArray_message_nohead->truncate(head_occur_index);
			//截取后面出现的head左边的消息

			/////////////////////////////////////////////////////////////////////////////
			QByteArray *result_bytes = nullptr;
			bool is_receive_over = true;
			if (QString(*byteArray_message_nohead).contains(k_end_message_))
			{
				int size_end_flag = k_end_message_.size();
				int size = byteArray_message_nohead->size();
				int left_size = size - size_end_flag;
				result_bytes = new QByteArray(GetWholeBytes(_ip, byteArray_message_nohead->left(left_size), is_receive_over));
			}
			else
			{
				is_receive_over = false;
				result_bytes = new QByteArray((GetWholeBytes(_ip, *byteArray_message_nohead, is_receive_over)));
			}
			///<去掉结尾标识
			//////////////////////////////////////////////////////////////////////////


			messageUnit_receive->byteArray_msg = /*byteArray_message_nohead*/result_bytes;

			messageUnit_receive->msg = /*byteArray_message_nohead*/result_bytes->data();

			_list_messageUnit->append(messageUnit_receive);

			int count_truncate_message = byteArray_message_nohead->count();

			_byteArray_message = _byteArray_message.remove(0, count_truncate_message);
			//剔除前一条消息
		}
		continue;
	}
}

QList<MessageUnit *> * network_client_st::UnpackMessage(QByteArray byteArray_message, QString _ip)
{
	QList<MessageUnit *> *list_messageUnit = new QList<MessageUnit *>();

	if (IsStreamHandle())
	{
// 		多条消息融合

// 		MessageUnit * messageUnit_receive = new MessageUnit();
// 		 
// 		QByteArray *byteArray_message_nohead = new QByteArray(byteArray_message.remove(0, k_header_message.size()));
// 
// 
// 		messageUnit_receive->byteArray_msg = byteArray_message_nohead;
// 		 
// 		messageUnit_receive->msg = byteArray_message_nohead->data();
// 		 
// 		list_messageUnit->append(messageUnit_receive);

		RemoveHeadFromByteArray(list_messageUnit, byteArray_message, _ip);
	}
	else
	{
		char *c_message = byteArray_message.data();

		QString qs_message = QString::fromLocal8Bit(c_message);

		QStringList list_message = qs_message.split(k_header_message, QString::SkipEmptyParts);
		
		int size = list_message.size();

		for (int i = 0; i < size; i++)
		{
			QString qs_message_each = list_message.at(i);

			MessageUnit * messageUnit_receive = new MessageUnit();

			QByteArray byteArray_message_each = qs_message_each.toLocal8Bit();
			
			messageUnit_receive->msg = byteArray_message_each.data();

			messageUnit_receive->byteArray_msg = new QByteArray(byteArray_message_each);

			list_messageUnit->append(messageUnit_receive);

		}
	}
	
	return list_messageUnit;
}

MessageUnit network_client_st::PackageMessage(MessageUnit *_messageUnit)
{
	MessageUnit messageUnit;

	if (IsStreamHandle())
	{
		QString qs_message = QString::fromLocal8Bit(_messageUnit->msg);

		//QString qs_header_message = QString("%1%2").arg(k_header_message).arg(qs_message);
		QString qs_header_message = QString("%1%2%3").arg(k_header_message).arg(qs_message).arg(k_end_message_);

		QByteArray *byteArray_header_message = new QByteArray(qs_header_message.toLocal8Bit());

		messageUnit.msg = byteArray_header_message->data();


		// 	QByteArray byteArray_message(*_messageUnit->byteArray_msg, QIODevice::ReadWrite);

		// 		QDataStream dataStream_message(_messageUnit->byteArray_msg, QIODevice::ReadWrite);
		// 
		// 		// 	dataStream_message << byteArray_message;
		// 
		// 		dataStream_message.device()->seek(0);
		// 
		// 		char * qs_message_temp2 = "";
		// 
		// 		char * qs_message_temp3 = "";
		// 
		// 		int int_temp = 0;
		// 
		// 		double double_temp = 0;
		// 
		// 		dataStream_message >> double_temp;
		// 
		// 		dataStream_message >> qs_message_temp2;
		// 
		// 		dataStream_message >> qs_message_temp3;
		// 
		// 		QByteArray *byteArray_message_head = new QByteArray();
		// 
		// 		QDataStream dataStream_message_head(byteArray_message_head, QIODevice::ReadWrite);
		// 
		// 		QByteArray byteArray_head = k_header_message.toLocal8Bit();
		// 
		// 		char * header = byteArray_head.data();
		// 
		// 		dataStream_message_head << header << double_temp << qs_message_temp2 << qs_message_temp3;

		QByteArray *byteArray_message_head = new QByteArray(_messageUnit->byteArray_msg->insert(0, k_header_message));

		if (!QString(*byteArray_message_head).contains(k_end_message_))
		{
			byteArray_message_head->append(k_end_message_);
			///<添加结尾标识
		}


		messageUnit.byteArray_msg = byteArray_message_head;
		//重新打包加头
	}
	else
	{
		char *c_message = _messageUnit->byteArray_msg->data();

		QString qs_message_from_bytes = QString::fromLocal8Bit(c_message);

		//QString qs_header_message_from_bytes = QString("%1%2").arg(k_header_message).arg(qs_message_from_bytes);
		QString qs_header_message_from_bytes = QString("%1%2%3").arg(k_header_message).arg(qs_message_from_bytes).arg(k_end_message_);
		///<添加结尾标识

		QByteArray byteArray_header_message_from_bytes = qs_header_message_from_bytes.toLocal8Bit();

		messageUnit.byteArray_msg = new QByteArray(byteArray_header_message_from_bytes);
		//重新打包加头
	}

	return messageUnit;
}
void network_client_st::SetOutDebug(bool _is_out_debug)
{
	is_out_log_ = _is_out_debug;
}
bool network_client_st::GetOutDebug()
{
	return is_out_log_;
}
