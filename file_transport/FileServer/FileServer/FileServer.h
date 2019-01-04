#ifndef FILESERVER_H
#define FILESERVER_H

#include <QtWidgets/QWidget>
#include <QFile>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "FileHandler.h"
#include "ui_FileServer.h"

namespace file_transport_st {
class FileServer : public QWidget
{
	Q_OBJECT

public:
	FileServer(QWidget *parent = 0);
	~FileServer();

signals:
	void Signal_GetUploadReply(qint64 bytesRead, qint64 totalBytes);
	void Signal_GetDownloadReply(qint64 bytesRead, qint64 totalBytes);

private:
	void CreateSignalAndSlot();

	void Init();

private slots:

	void Slot_DownloadFile();

	void Slot_SelectFile(bool checked = false);

	void Slot_SendFile(bool checked = false);

	void Slot_UpdateDataReadProgress(qint64 bytesRead, qint64 totalBytes);

	void Slot_OnUploadProgress(qint64 bytesSent, qint64 bytesTotal);

	void Slot_OnUpload(qint64 bytesSent, qint64 bytesTotal);

private:
	Ui::FileServerClass ui;
	FileHandler *fileHandler_;
};
}
#endif // FILESERVER_H
