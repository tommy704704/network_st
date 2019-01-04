#ifndef QUERYTHREAD_H
#define QUERYTHREAD_H
/************************************!
 * @file QueryThread.h
 *
 * @author ����
 * @date 2018/01/04
 *
 * 
 ************************************/
#include <QThread>
#include <QVector>
#include "Global.h"
namespace network_st{

/************************************!
 * @class 
 *
 * @brief ��ѯ��Ϣ�Ƿ��յ����пͻ��˵Ļ�ִ
 *
 * @author ����
 * @date 2018/01/04
 ************************************/
class QueryThread : public QThread
{
public:
	QueryThread();
	~QueryThread();
	/************************************
	* @Method:    GetInstance
	* @FullName:  QueryThread::GetInstance
	* @Access:    public static 
	* @Returns:   QueryThread *
	* @Qualifier:
	* @comment: ��ȡȫ��ʵ��
	************************************/
	static QueryThread *GetInstance()
	{
		if (!instance_)
		{
			instance_ = new QueryThread();
		}
		return instance_;
	}

protected:
private:
	void Init();
private:
	QVector<Client *> *list_clients_;
	static QueryThread *instance_;
};
}
#endif