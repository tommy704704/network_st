#ifndef LOGMANAGER_H
#define LOGMANAGER_H
/************************************!
 * @file LogManager.h
 *
 * @author ����
 * @date 2018/03/08
 *
 * 
 ************************************/
#include <QFile>
#include <QQueue>
#include <QString>
#include <QTextStream>
namespace network_st{
/************************************!
 * @class 
 *
 * @brief 
 *
 * @author ����
 * @date 2018/03/08
 ************************************/
class LogManager
{
public:
	static LogManager *GetInstance()
	{
		if (!s_logManager_)
		{
			s_logManager_ = new LogManager();
		}
		return s_logManager_;
	}
	LogManager();
	~LogManager();

	/************************************
	* @Method:    AppendLog
	* @FullName:  network_st::LogManager::AppendLog
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @Parameter: QString _logMessage
	* @comment: ������־��Ϣ
	************************************/
	void AppendLog(QString _logMessage);
	/************************************
	* @Method:    OutLog
	* @FullName:  network_st::LogManager::OutLog
	* @Access:    public 
	* @Returns:   void
	* @Qualifier:
	* @comment: �����־
	************************************/
	void OutLog();
protected:

private:
	void CreatSignalAndSlot();
	void Init();
private:
	static LogManager *s_logManager_;

	QFile file_;

	QTextStream logFile_out_;

	QMutex mutex_;

	QQueue<QString> *queue_log_message_;

};
}
#endif