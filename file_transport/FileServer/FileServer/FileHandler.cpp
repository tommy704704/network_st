#include "FileHandler.h"
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHttpPart>
#include <QFileInfo>
#include <QEventLoop>
#include "QMessageBox"

namespace file_transport_st {
FileHandler::FileHandler(QObject *parent) : download_file_(nullptr)
											, network_manager_(nullptr)
											, upload_networkAccessManager_(nullptr)
											, reply_(nullptr)
											, buffer_(nullptr)
{
	Init();
}

FileHandler::~FileHandler()
{
	delete buffer_;

	buffer_ = NULL;

	if (upload_networkAccessManager_ != nullptr)
	{
		delete upload_networkAccessManager_;
		upload_networkAccessManager_ = NULL;
	}

	if (download_file_ != nullptr)
	{
		if (download_file_->isOpen())
		{
			download_file_->close();
		}
		delete download_file_;
		download_file_ = NULL;
	}
	if (reply_ != nullptr)
	{
		delete reply_;
		reply_ = NULL;
	}

}

const QString FileHandler::GetLocalDownloadFileName()
{
	return download_file_name_;
}

const QString FileHandler::GetLocalUploadFileName()
{
	return upload_file_name_;
}

QString FileHandler::GetLocalDownloadFilePath()
{
	return download_file_path_;
}

QString FileHandler::GetLocalUploadFilePath()
{
	return upload_file_path_;
}

QUrl FileHandler::GetDownloadQUrl()
{
	if (!download_file_name_.isEmpty())
	{
		QUrl result_url;

		QString q_result_url = "";

		q_result_url = QString("%1%2%3").arg(q_download_url_).arg("/").arg(download_file_name_);

		result_url = q_result_url;
		//设置url对象，此路径含有目标文件
		return result_url;
	}

	return download_url_;
}

const QString FileHandler::GetDownloadUrl()
{
	if (!download_file_name_.isEmpty())
	{
		QString q_result_url = "";

		q_result_url = QString("%1%2%3").arg(q_download_url_).arg("/").arg(download_file_name_);

		return q_result_url;
	}

	return q_download_url_;
}

const QString FileHandler::GetUploadUrl()
{
	return q_upload_url_;
}

void FileHandler::SetUploadUrl(const QString _url)
{
	q_upload_url_ = _url;
}

void FileHandler::SetDownloadUrl(const QString _url)
{
	q_download_url_ = _url;

	download_url_ = q_download_url_;
	//设置url对象，此路径没有目标文件
}

void FileHandler::SetLocalUploadFilePath(const QString _path)
{
	upload_file_path_ = _path;

	QStringList list_unit = upload_file_path_.split("/");

	int size = list_unit.size();

	if (size > 0)
	{
		upload_file_name_ = list_unit.at(size - 1);
		//文件名
	}
}

void FileHandler::SetLocalDownloadFilePath(const QString _path)
{
	download_file_path_ = _path;
}

void FileHandler::SetLocalDownloadFileName(const QString _name)
{
	download_file_name_ = _name;
}

void FileHandler::CreateSignalAndSlot()
{
	bool is_ok = connect(upload_networkAccessManager_,
		SIGNAL(finished(QNetworkReply*)),
		this,
		SLOT(Slot_UploadReplyFinished(QNetworkReply*)));
}

void FileHandler::Init()
{
	download_file_path_ = "";

	download_file_name_ = "";

	upload_file_path_ = "";

	upload_file_name_ = "";

	q_download_url_ = "";
	//下载链接字符串

	q_upload_url_ = "";
	//上传链接

	upload_networkAccessManager_ = new QNetworkAccessManager(this);

	network_manager_ = new QNetworkAccessManager(this);

	buffer_ = NULL;

	CreateSignalAndSlot();
}

void FileHandler::UploadFile()
{
	QString file_path = GetLocalUploadFilePath();

	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	QHttpPart textPart;
	textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"watermark\""));
	textPart.setBody("my text");
	multiPart->append(textPart);

	QHttpPart imagePart;
	QFile *file = new QFile(file_path);
	if (!file->open(QIODevice::ReadOnly))
	{
		return;
	}
	imagePart.setBodyDevice(file);
	imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"filename\"; filename=\"%1\"").arg(upload_file_name_)));
	//test_stao.txt

	multiPart->append(imagePart);

	QUrl url(GetUploadUrl());
	QNetworkRequest request(url);

	// 	QNetworkAccessManager *networkManager = new QNetworkAccessManager;

	bool is_ok = connect(upload_networkAccessManager_, SIGNAL(finished(QNetworkReply*)), SLOT(Slot_UploadReplyFinished(QNetworkReply*)));

	QNetworkReply *reply = upload_networkAccessManager_->post(request, multiPart);
	multiPart->setParent(reply); // delete the multiPart with the reply

	QEventLoop loop;
	is_ok = connect(reply,
		SIGNAL(error(QNetworkReply::NetworkError)),
		this,
		SLOT(Slot_UpLoadError(QNetworkReply::NetworkError)));

// 	is_ok = connect(reply,
// 		SIGNAL(uploadProgress(qint64, qint64)),
// 		this,
// 		SLOT(Slot_OnUploadProgress(qint64, qint64)));
	is_ok = connect(reply,
		SIGNAL(uploadProgress(qint64, qint64)),
		this,
		SIGNAL(Signal_GetUploadReply(qint64, qint64)));

	is_ok = connect(reply,
		&QNetworkReply::finished,
		&loop,
		&QEventLoop::quit);

	loop.exec();

	//获取http状态码
	int http_code_ = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	// 获取数据
	if (QNetworkReply::NoError == reply->error())
	{
		QByteArray context_ = reply->readAll();
		QJsonObject result_obj = QJsonDocument::fromJson(context_).object();
		int code = result_obj.value("code").toInt();
		qDebug() << "code === " << code << result_obj;
	}

	file->flush();
	file->close();
}

void FileHandler::DownloadFile()
{
	QUrl download_url = GetDownloadQUrl();

	QFileInfo fileInfo(download_url.path());

	QString fileName = fileInfo.fileName();
	///<传递的文件名

	if (fileName.isEmpty())
		fileName = "index.html";

	QString download_file_path = GetLocalDownloadFilePath();
	///<不含文件名

	if (!download_file_path.isEmpty())
	///<存放到指定的目录
	{
		download_file_path = QString("%1%2%3").
									arg(download_file_path).
									arg("/").
									arg(fileName);
		///<路径上加入文件名

		download_file_ = new QFile(download_file_path);

		if (QFile::exists(download_file_path))
		{
			if (QMessageBox::question(0,
				tr("HTTP"),
				tr("There already exists a file called %1 in the current directory. Overwrite?").arg(fileName),
				QMessageBox::Yes | QMessageBox::No,
				QMessageBox::No) == QMessageBox::No)
				return;

			QFile::remove(download_file_path);
		}
	}
	else
	///<存放到默认exe下的download目录
	{
		QDir current_dir(QDir::currentPath());

		bool is_ok = current_dir.mkdir("download");

		if (!is_ok)
		{
			QMessageBox::information(0,
				tr("HTTP"),
				tr("Unable to create download file path"));
			return;
		}

		download_file_ = new QFile(QString("download/%1").arg(fileName));

		if (QFile::exists(QString("download/%1").arg(fileName)))
		{
			if (QMessageBox::question(0,
				tr("HTTP"),
				tr("There already exists a file called %1 in the current directory. Overwrite?").arg(fileName),
				QMessageBox::Yes | QMessageBox::No,
				QMessageBox::No) == QMessageBox::No)
				return;

			QFile::remove(QString("download/%1").arg(fileName));
		}
	}



	if (!download_file_->open(QIODevice::WriteOnly))
	{
		QMessageBox::information(0,
			tr("HTTP"),
			tr("Unable to save the file %1: %2.").arg(fileName).arg(download_file_->errorString()));
		delete download_file_;

		download_file_ = nullptr;

		return;
	}


	// schedule the request
	httpRequestAborted_ = false;

	StartRequest(download_url);
}

void FileHandler::Slot_HttpReadyRead()
{
	// this slot gets called every time the QNetworkReply has new data.
	// We read all of its new data and write it into the file.
	// That way we use less RAM than when reading it at the finished()
	// signal of the QNetworkReply
	if (download_file_)
		download_file_->write(reply_->readAll());
}

void FileHandler::Slot_CancelDownload()
{
	reply_->abort();
}

void FileHandler::Slot_HttpFinished()
{
	if (httpRequestAborted_)
	{
		if (download_file_)
		{
			download_file_->close();

			download_file_->remove();

			delete download_file_;

			download_file_ = nullptr;
		}

		reply_->deleteLater();

		return;
	}


	download_file_->flush();

	download_file_->close();

	download_file_ = nullptr;

	QVariant redirectionTarget = reply_->attribute(QNetworkRequest::RedirectionTargetAttribute);

	if (reply_->error())
	{
		download_file_->remove();

		QMessageBox::information(0,
			tr("HTTP"),
			tr("Download failed: %1.").arg(reply_->errorString()));
	}
	else if (!redirectionTarget.isNull())
	{
		QUrl newUrl = download_url_.resolved(redirectionTarget.toUrl());

		if (QMessageBox::question(0,
			tr("HTTP"),
			tr("Redirect to %1 ?").arg(newUrl.toString()),
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		{
			download_url_ = newUrl;

			reply_->deleteLater();

			download_file_->open(QIODevice::WriteOnly);

			download_file_->resize(0);

			StartRequest(download_url_);

			return;
		}
	}
	else
	{
	}

	reply_->deleteLater();

	reply_ = 0;

	delete download_file_;

	download_file_ = nullptr;
}

void FileHandler::Slot_UploadReplyFinished(QNetworkReply * reply)
{
}

void FileHandler::Slot_UpLoadError(QNetworkReply::NetworkError error)
{

}

void FileHandler::StartRequest(QUrl url)
{
	reply_ = network_manager_->get(QNetworkRequest(url));

	bool is_ok = connect(reply_,
		SIGNAL(finished()),
		this,
		SLOT(Slot_HttpFinished()));
	//下载完成后  

	is_ok = connect(reply_,
		SIGNAL(readyRead()),
		this,
		SLOT(Slot_HttpReadyRead()));
	//有可用数据时  

// 	is_ok = connect(reply_,
// 		SIGNAL(downloadProgress(qint64, qint64)),
// 		this,
// 		SLOT(Slot_UpdateDataReadProgress(qint64, qint64)));
	is_ok = connect(reply_,
		SIGNAL(downloadProgress(qint64, qint64)),
		this,
		SIGNAL(Signal_GetDownloadReply(qint64, qint64)));

	//更新进度条  
}

}