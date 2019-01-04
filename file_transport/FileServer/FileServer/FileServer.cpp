#include <QFileDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHttpPart>
#include "FileServer.h"
namespace file_transport_st {
FileServer::FileServer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	Init();
}

FileServer::~FileServer()
{
	delete fileHandler_;

	fileHandler_ = NULL;
}

void FileServer::CreateSignalAndSlot()
{
	bool is_ok = connect(ui.pushButton_selectFile_,
		SIGNAL(clicked(bool)),
		this,
		SLOT(Slot_SelectFile()));

	is_ok = connect(ui.pushButton_send_,
		SIGNAL(clicked(bool)),
		this,
		SLOT(Slot_SendFile()));

	is_ok = connect(ui.pushButton_download_,
		SIGNAL(clicked(bool)),
		this,
		SLOT(Slot_DownloadFile()));

// 	is_ok = connect(upload_networkAccessManager_, 
// 		SIGNAL(finished(QNetworkReply*)), 
// 		this,
// 		SLOT(Slot_UploadReplyFinished(QNetworkReply*)));

	is_ok = connect(fileHandler_, 
		SIGNAL(Signal_GetUploadReply(qint64, qint64)),
		this, 
		SLOT(Slot_OnUploadProgress(qint64, qint64)));

	is_ok = connect(fileHandler_,
		SIGNAL(Signal_GetDownloadReply(qint64, qint64)),
		this,
		SLOT(Slot_UpdateDataReadProgress(qint64, qint64)));

	is_ok = connect(fileHandler_,
		SIGNAL(Signal_GetUploadReply(qint64, qint64)),
		this,
		SIGNAL(Signal_GetUploadReply(qint64, qint64)));

	is_ok = connect(this,
		SIGNAL(Signal_GetUploadReply(qint64, qint64)),
		this,
		SLOT(Slot_OnUpload(qint64, qint64)));
	;
}

void FileServer::Init()
{
	fileHandler_ = new FileHandler();

	//fileHandler_->SetUploadUrl("http://192.168.0.66:8989/FileServer/UploadFile");

	fileHandler_->SetDownloadUrl("http://192.168.0.66:8989/FileServer");

	fileHandler_->SetLocalDownloadFileName("YoudaoDict_flh.exe");

// 	fileHandler_->SetLocalDownloadFilePath("D:\\project_test");

	CreateSignalAndSlot();
}

void FileServer::Slot_SelectFile(bool checked)
{
// 	upload_file_path_ = QFileDialog::getOpenFileName(this,	tr("Select File"), "", tr(""));
	fileHandler_->SetLocalUploadFilePath(QFileDialog::getOpenFileName(this, tr("Select File"), "", tr("")));

	QString file_path = fileHandler_->GetLocalUploadFilePath();

	ui.lineEdit_url_->setText(file_path);

	ui.progressBar_upload_->setValue(0);

}

void FileServer::Slot_SendFile(bool checked)
{
	//////////////////////////////////////////////////////////////////////////

	QString upload_ip = ui.lineEdit_ip_->text();
	QString upload_url = QString("%1%2%3").arg("http://").arg(upload_ip).arg(":8989/FileServer/UploadFile");
	fileHandler_->SetUploadUrl(upload_url);

	fileHandler_->UploadFile();
}


void FileServer::Slot_UpdateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
// 	if (httpRequestAborted_)
// 		return;

	ui.progressBar_received_->setMaximum(totalBytes);

	ui.progressBar_received_->setValue(bytesRead);
}


void FileServer::Slot_OnUploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
	if (bytesTotal > 0)
	{
		ui.progressBar_upload_->setMaximum(bytesTotal);

		ui.progressBar_upload_->setValue(bytesSent);
	}
}

void FileServer::Slot_OnUpload(qint64 bytesSent, qint64 bytesTotal)
{
}

void FileServer::Slot_DownloadFile()
{
// 	fileHandler_->SetDownloadUrl(ui.lineEdit_download_url_->text());
	QStringList list_unit = ui.lineEdit_download_url_->text().split("/");

	int size = list_unit.size();

	if (size > 0)
	{
		QString download_file_name = list_unit.at(size - 1);
		//ÎÄ¼þÃû
		fileHandler_->SetLocalDownloadFileName(download_file_name);
	}

	fileHandler_->DownloadFile();
}
}