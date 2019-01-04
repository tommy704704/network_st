#ifndef RESENDTHREAD_H
#define RESENDTHREAD_H
/*!
* @file AddressManager.h
*
* @author кнлн
* @date 2018/01/04
*
*
*/
#include <QThread>
namespace network_st{

class ReSendThread : public QThread
{
public:
	ReSendThread();
	~ReSendThread();
protected:

private:
};
}
#endif