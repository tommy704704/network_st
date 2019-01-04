#include "NetPublicInterface.h"
#include "NetInterface.h"
#include "QDateTime"
#include "QFile"

using namespace network_st;
NetPublicInterface *NetPublicInterface::instance_ = NULL;

extern QString g_local_ip;

extern int client_timeout_;
extern int broadcast_interval_;

// void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
// {
// 	static QMutex mutex;
// 	mutex.lock();
// 
// 	QString text;
// 	switch (type)
// 	{
// 	case QtDebugMsg:
// 		text = QString("Debug:");
// 		break;
// 
// 	case QtWarningMsg:
// 		text = QString("Warning:");
// 		break;
// 
// 	case QtCriticalMsg:
// 		text = QString("Critical:");
// 		break;
// 
// 	case QtFatalMsg:
// 		text = QString("Fatal:");
// 	}
// 
// 	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
// 	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
// 	QString current_date = QString("(%1)").arg(current_date_time);
// 	QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);
// 
// 	QFile file("log.txt");
// 	file.open(QIODevice::WriteOnly | QIODevice::Append);
// 	QTextStream text_stream(&file);
// 	text_stream << message << "\r\n";
// 	file.flush();
// 	file.close();
// 
// 	mutex.unlock();
// }

void NetPublicInterface::OpenDebug(bool _is_open)
{
	SetOutDebug(_is_open);
}


NetPublicInterface *NetPublicInterface::GetInstance()
{
	if (!instance_)
	{
		instance_ = new NetPublicInterface();
	}
	return instance_;
}


void NetPublicInterface::SetLocalIpv4(QString _ipv4)
{
	g_local_ip = _ipv4;
	qDebug() << "SetLocalIpv4()" << "server IP : " << g_local_ip;

}

void network_st::NetPublicInterface::SetTimeOut(const int _timeout)
{
	if (_timeout <= 0)
	{
		client_timeout_ = k_client_timeout_;
	}
	else
	{
		client_timeout_ = _timeout;
	}
}
void network_st::NetPublicInterface::SetBroadcastInterval(const int _interval)
{
	if (_interval <= 0)
	{
		broadcast_interval_ = k_broadcast_interval_;
	}
	else
	{
		broadcast_interval_ = _interval;
	}
}

QStringList NetPublicInterface::GetLocalAllIPv4()
{
	qDebug() << "GetLocalAllIPv4()";

	QStringList list_all_ip;

	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// 获取第一个本主机的IPv4地址  
	int size_address = ipAddressesList.size();

	for (int i = 0; i < size_address; ++i)
	{
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
			ipAddressesList.at(i).toIPv4Address())
		{
			QString ipv4 = ipAddressesList.at(i).toString();

			qDebug() << "ipv4: " << ipv4;

			list_all_ip.append(ipv4);

// 			g_local_ip = ipv4;

			continue;
		}
		qDebug() << ipAddressesList.at(i).toString();
	}
	// 如果没有找到，则以本地IP地址为IP  
// 	if (k_default_ip == g_local_ip)
// 		g_local_ip = QHostAddress(QHostAddress::LocalHost).toString();

	return list_all_ip;

}



NetPublicInterface::~NetPublicInterface()
{
	delete netInterface_;

	netInterface_ = NULL;
}

NetPublicInterface::NetPublicInterface()
{
// 	qInstallMessageHandler(outputMessage);
	//注册MessageHandler

	qDebug("NetPublicInterface()");

	Init();
}

void NetPublicInterface::Init()
{
	netInterface_ = NetInterface::GetInstance();

	CreateSignalAndSlot();

}

void NetPublicInterface::CreateSignalAndSlot()
{
	
}

MessageUnit * network_st::NetPublicInterface::GetReceivedNewMessageUnit()
{
	return netInterface_->GetReceivedNewMessageUnit();
}

QList<Client *> * network_st::NetPublicInterface::GetAllClient()
{
	return netInterface_->GetAllClient();
}

void network_st::NetPublicInterface::AddMessageToSend(MessageUnit *_messageUnit)
{
	netInterface_->AddMessageToSend(_messageUnit);
}

void network_st::NetPublicInterface::RemoveSendMessage(char *_msg)
{
	netInterface_->RemoveSendMessage(_msg);

}

void network_st::NetPublicInterface::AddClientAddress(Client *_client)
{
	netInterface_->AddClientAddress(_client);
}

void network_st::NetPublicInterface::RemoveClientAddress(int _index)
{
	netInterface_->RemoveClientAddress(_index);
}

