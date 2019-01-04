#include "Global.h"

using namespace network_st;

QString g_local_ip = k_default_ip;							///<����IP

QString g_sender_ip = k_default_ip;							///<���ͷ�IP

bool g_is_stream_handle = true;

bool network_st::IsStreamHandle()
{
	return g_is_stream_handle;
}

void network_st::SetStreamHandle(bool _is_stream_handle /*= true*/)
{
	g_is_stream_handle = _is_stream_handle;
}

QString network_st::GetLocalIP()
{
	qDebug() << "GetLocalIP()";

	if (g_local_ip != k_default_ip)
	{
		return g_local_ip;
	}

	/*��ȡ����IPƬ��ַ*/

	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// ��ȡ��һ����������IPv4��ַ  
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
	// ���û���ҵ������Ա���IP��ַΪIP  
	if (k_default_ip == g_local_ip)
		g_local_ip = QHostAddress(QHostAddress::LocalHost).toString();

	return g_local_ip;




// 	QList<QHostAddress> addList = QNetworkInterface::allAddresses();
// 
// 	foreach(QHostAddress address, addList)
// 	{
// 		qDebug() << address.toString();
// 		/*�ų�IPV6���ų��ػ���ַ */
// 		if (address.protocol() == QAbstractSocket::IPv4Protocol
// 			&& address != QHostAddress::Null
// 			&& address != QHostAddress::LocalHost)
// 		{
// 			/*�����ת��Ϊ�ַ�����ʽ */
// 			qDebug() << address.toString();
// 
// 			local_ip = address.toString();
// 
// 			return local_ip;
// 		}
// 	}
// 	return local_ip;

}

void RemoveHeadFromByteArray(QList<MessageUnit *> *_list_messageUnit, QByteArray _byteArray_message)
{
	QString qstring_head = k_header_message;

	QByteArray byteArray_head = qstring_head.toLocal8Bit();

	char *c_head = byteArray_head.data();

	int count_head = _byteArray_message.count(c_head);

	for (int i = 0; i < count_head * 2; i++)
	{

		int head_occur_index = _byteArray_message.indexOf(k_header_message, 0);

		if (0 == head_occur_index)
		{
			QByteArray *byteArray_message_nohead = new QByteArray(_byteArray_message.remove(0, k_header_message.size()));
			///<ȥ����ǰ���ͷ

			continue;
		}

		MessageUnit * messageUnit_receive = new MessageUnit();

		QByteArray *byteArray_message_nohead = new QByteArray(_byteArray_message);

		if (head_occur_index < 0)
		{
			//˵���Ѳ�����ͷ�����ý�ȡ
			messageUnit_receive->byteArray_msg = byteArray_message_nohead;

			messageUnit_receive->msg = byteArray_message_nohead->data();

			_list_messageUnit->append(messageUnit_receive);
		}
		else
		{
			byteArray_message_nohead->truncate(head_occur_index);
			//��ȡ������ֵ�head��ߵ���Ϣ

			messageUnit_receive->byteArray_msg = byteArray_message_nohead;

			messageUnit_receive->msg = byteArray_message_nohead->data();

			_list_messageUnit->append(messageUnit_receive);

			int count_truncate_message = byteArray_message_nohead->count();

			_byteArray_message = _byteArray_message.remove(0, count_truncate_message);
			//�޳�ǰһ����Ϣ
		}
		continue;
	}
}

QList<MessageUnit *> * network_st::UnpackMessage(QByteArray byteArray_message)
{
	QList<MessageUnit *> *list_messageUnit = new QList<MessageUnit *>();

	if (IsStreamHandle())
	{
// 		������Ϣ�ں�

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

		RemoveHeadFromByteArray(list_messageUnit, byteArray_message);
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

MessageUnit network_st::PackageMessage(MessageUnit *_messageUnit)
{
	MessageUnit messageUnit;

	if (IsStreamHandle())
	{
		QString qs_message = QString::fromLocal8Bit(_messageUnit->msg);

		QString qs_header_message = QString("%1%2").arg(k_header_message).arg(qs_message);

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

		messageUnit.byteArray_msg = byteArray_message_head;
		//���´����ͷ
	}
	else
	{
		char *c_message = _messageUnit->byteArray_msg->data();

		QString qs_message_from_bytes = QString::fromLocal8Bit(c_message);

		QString qs_header_message_from_bytes = QString("%1%2").arg(k_header_message).arg(qs_message_from_bytes);

		QByteArray byteArray_header_message_from_bytes = qs_header_message_from_bytes.toLocal8Bit();

		messageUnit.byteArray_msg = new QByteArray(byteArray_header_message_from_bytes);
		//���´����ͷ
	}

	return messageUnit;
}

QString network_st::GetPeerAddressIpv4(QTcpSocket * _acceptedSocket)
{
	QString result = QHostAddress(_acceptedSocket->peerAddress().toIPv4Address()).toString();
	
	return result;
}

QString network_st::GetPeerAddressIpv4(QUdpSocket * _acceptedSocket)
{
	QString result = QHostAddress(_acceptedSocket->peerAddress().toIPv4Address()).toString();

	return result;
}
