#pragma once
/************************************!
 * @file FileTransportInterface.h
 *
 * @author 宋涛
 * @date 2018/05/25
 *
 *  文件传输客户端接口
 ************************************/
#include "filetransportdll_global.h"
#include <QObject>

namespace file_transport_st {
class FileHandler;

class FILETRANSPORTDLL_EXPORT FileTransportInterface : public QObject
{
	Q_OBJECT

public:
	static FileTransportInterface *GetInstance();
	FileTransportInterface(QObject *parent = Q_NULLPTR);

	~FileTransportInterface();

	/************************************
	* @Method:    SetUploadUrl
	* @FullName:  file_transport_st::FileTransportInterface::SetUploadUrl
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: const QString _url
	* @comment: 设置上传文件到服务器的url
	************************************/
	void SetUploadUrl(const QString _url);

	/************************************
	* @Method:    SetDownloadUrl
	* @FullName:  file_transport_st::FileTransportInterface::SetDownloadUrl
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: const QString _url
	* @comment: 设置下载文件从服务器的url
	************************************/
	void SetDownloadUrl(const QString _url);

	/************************************
	* @Method:    SetLocalUploadFilePath
	* @FullName:  file_transport_st::FileTransportInterface::SetLocalUploadFilePath
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: const QString _path
	* @comment: 设置本地选取文件的绝对路径，用来解析此文件并上传
	************************************/
	void SetLocalUploadFilePath(const QString _path);

	/************************************
	* @Method:    SetLocalDownloadFileName
	* @FullName:  file_transport_st::FileTransportInterface::SetLocalDownloadFileName
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: const QString _name
	* @comment: 设置从服务端下载的文件名
	************************************/
	void SetLocalDownloadFileName(const QString _name);

	/************************************
	* @Method:    SetLocalDownloadFilePath
	* @FullName:  file_transport_st::FileTransportInterface::SetLocalDownloadFilePath
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: const QString _path
	* @comment: 设置将下载的文件保存到指定的目录，如果没有设置指定目录，文件将默认被保存在exe当前目录的download文件夹下
	************************************/
	void SetLocalDownloadFilePath(const QString _path);

	/************************************
	* @Method:    UploadFile
	* @FullName:  file_transport_st::FileTransportInterface::UploadFile
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 上传文件到指定url的服务器
				注意：调用此接口之前一定需要先调用SetUploadUrl接口，如果每次上传的服务器上传服务url不变的话只需要设置一次
				和SetLocalUploadFilePath接口
	************************************/
	void UploadFile();

	/************************************
	* @Method:    DownloadFile
	* @FullName:  file_transport_st::FileTransportInterface::DownloadFile
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: 从指定url的服务器下载指定的文件
				注意：调用此接口之前一定需要先调用SetDownloadUrl接口，如果每次下载的服务器下载服务url不变的话只需要设置一次
				和SetLocalDownloadFileName接口
	************************************/
	void DownloadFile();

signals:
	/************************************
	* @Method:    Signal_GetUploadReply
	* @FullName:  file_transport_st::FileTransportInterface::Signal_GetUploadReply
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: qint64 bytesRead 已接收的字节数
	* @Parameter: qint64 totalBytes	文件总字节数
	* @comment:	上传文件进度信号
	************************************/
	void Signal_GetUploadReply(qint64 bytesRead, qint64 totalBytes);

	/************************************
	* @Method:    Signal_GetDownloadReply
	* @FullName:  file_transport_st::FileTransportInterface::Signal_GetDownloadReply
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: qint64 bytesRead 已接收的字节数
	* @Parameter: qint64 totalBytes	文件总字节数
	* @comment: 下载文件进度信号
	************************************/
	void Signal_GetDownloadReply(qint64 bytesRead, qint64 totalBytes);

private slots :
	void Slot_OnUploadProgress(qint64 bytesRead, qint64 totalBytes);

protected:
	
private:

	void Init();

	void CreateSignalAndSlot();
private:
	static FileTransportInterface * s_instance_;

	FileHandler *fileHandler_;
};
}