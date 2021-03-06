#include "LogManager.h"
#include <QTextStream>
using namespace network_st;
LogManager *LogManager::s_logManager_ = nullptr;

network_st::LogManager::LogManager()
{
	Init();
}

network_st::LogManager::~LogManager()
{
	file_.close();

	delete queue_log_message_;

	queue_log_message_ = NULL;
}

void network_st::LogManager::AppendLog(QString _logMessage)
{
	mutex_.lock();
	if (queue_log_message_)
	{
		queue_log_message_->enqueue(_logMessage);
	}
	mutex_.unlock();
}

void network_st::LogManager::OutLog()
{
	mutex_.lock();
	if (!queue_log_message_->isEmpty())
	{
		QString log_message = queue_log_message_->dequeue();

		file_.setFileName("network_log.txt");
		if (!file_.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
		{
			return;
		}
		logFile_out_.setDevice(&file_);

		int status = logFile_out_.status();
		if (QTextStream::Ok == status)
		{
			logFile_out_ << log_message << "\n";
			file_.close();
		}
		else if (QTextStream::WriteFailed == status)
		{
			logFile_out_.reset();
			//����
			if (!file_.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
			{
				mutex_.unlock();
				return;
			}
			logFile_out_.setDevice(&file_);
		}
	}
	mutex_.unlock();
}

void network_st::LogManager::CreatSignalAndSlot()
{
}

void network_st::LogManager::Init()
{
	queue_log_message_ = new QQueue<QString>();

	file_.setFileName("network_log.txt");
	if (!file_.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
	{
		return;
	}
	logFile_out_.setDevice(&file_);
}

