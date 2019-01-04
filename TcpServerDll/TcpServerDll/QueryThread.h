#ifndef QUERYTHREAD_H
#define QUERYTHREAD_H
/************************************!
 * @file QueryThread.h
 *
 * @author 宋涛
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
 * @brief 轮询消息是否收到所有客户端的回执
 *
 * @author 宋涛
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
	* @comment: 获取全局实例
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