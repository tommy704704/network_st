#include "FileHandler.h"
#include "FileTransportInterface.h"


namespace file_transport_st {

FileTransportInterface * FileTransportInterface::s_instance_ = nullptr;

FileTransportInterface * FileTransportInterface::GetInstance()
{
	if (!s_instance_)
	{
		s_instance_ = new FileTransportInterface();
	}
	
	return s_instance_;
}

FileTransportInterface::FileTransportInterface(QObject *parent)
{
	Init();
}

void FileTransportInterface::Init()
{
	fileHandler_ = new FileHandler();

	CreateSignalAndSlot();
}

void FileTransportInterface::CreateSignalAndSlot()
{
	bool is_ok = connect(fileHandler_,
						SIGNAL(Signal_GetUploadReply(qint64, qint64)),
						this,
						SIGNAL(Signal_GetUploadReply(qint64, qint64)));

	is_ok = connect(fileHandler_,
		SIGNAL(Signal_GetDownloadReply(qint64, qint64)),
		this,
		SIGNAL(Signal_GetDownloadReply(qint64, qint64)));
	
	is_ok = connect(this,
		SIGNAL(Signal_GetUploadReply(qint64, qint64)),
		this,
		SLOT(Slot_OnUploadProgress(qint64, qint64)));

}
void FileTransportInterface::Slot_OnUploadProgress(qint64 bytesRead, qint64 totalBytes)
{

}

FileTransportInterface::~FileTransportInterface()
{
	delete fileHandler_;

	fileHandler_ = NULL;
}

void FileTransportInterface::SetUploadUrl(const QString _url)
{
	fileHandler_->SetUploadUrl(_url);
}

void FileTransportInterface::SetDownloadUrl(const QString _url)
{
	fileHandler_->SetDownloadUrl(_url);
}

void FileTransportInterface::SetLocalUploadFilePath(const QString _path)
{
	fileHandler_->SetLocalUploadFilePath(_path);
}

void FileTransportInterface::SetLocalDownloadFileName(const QString _name)
{
	fileHandler_->SetLocalDownloadFileName(_name);
}

void FileTransportInterface::SetLocalDownloadFilePath(const QString _path)
{
	fileHandler_->SetLocalDownloadFilePath(_path);
}

void FileTransportInterface::UploadFile()
{
	fileHandler_->UploadFile();
}

void FileTransportInterface::DownloadFile()
{
	fileHandler_->DownloadFile();
}

}
