#include "clientcommunication.h"
#include <QtWidgets/QApplication>
using namespace network_st;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClientCommunication w;
	w.show();
	return a.exec();
}
