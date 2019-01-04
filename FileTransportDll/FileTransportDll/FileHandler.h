#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QFile>
#include <QNetworkReply>

namespace file_transport_st {
class FileHandler : public QObject
{
	Q_OBJECT
public:
	FileHandler(QObject *parent = Q_NULLPTR);
	~FileHandler();

	const QString GetLocalDownloadFileName();

	const QString GetLocalUploadFileName();

	QString GetLocalDownloadFilePath();

	QString GetLocalUploadFilePath();

	QUrl GetDownloadQUrl();

	const QString GetDownloadUrl();

	const QString GetUploadUrl();

	void SetUploadUrl(const QString _url);

	void SetDownloadUrl(const QString _url);

	void SetLocalUploadFilePath(const QString _path);

	void SetLocalDownloadFilePath(const QString _path);

	void SetLocalDownloadFileName(const QString _name);

	void UploadFile();

	void DownloadFile();
signals :
	void Signal_GetUploadReply(qint64 bytesRead, qint64 totalBytes);

	void Signal_GetDownloadReply(qint64 bytesRead, qint64 totalBytes);

protected:
private slots :
	void Slot_CancelDownload();

	void Slot_HttpFinished();

	void Slot_HttpReadyRead();

	void Slot_UploadReplyFinished(QNetworkReply * reply);

	void Slot_UpLoadError(QNetworkReply::NetworkError error);

private:
	void CreateSignalAndSlot();

	void Init();

	void StartRequest(QUrl url);

private:
	char *buffer_;

	bool httpRequestAborted_;

	QNetworkAccessManager *network_manager_;

	QNetworkAccessManager *upload_networkAccessManager_;

	QString download_file_path_;

	QString download_file_name_;

	QString upload_file_path_;

	QString upload_file_name_;

	QFile *download_file_;

	QNetworkReply *reply_;

	QUrl download_url_;
	//下载链接

	QString q_download_url_;
	//下载链接字符串

	QString q_upload_url_;
	//上传链接

};
}
#endif 