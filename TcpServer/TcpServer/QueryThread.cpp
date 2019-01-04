#include "QueryThread.h"
using namespace network_st;

QueryThread *QueryThread::instance_ = nullptr;
QueryThread::QueryThread()
{
	Init();
}

QueryThread::~QueryThread()
{

}

void QueryThread::Init()
{
	list_clients_ = new QVector<Client *>();
}

