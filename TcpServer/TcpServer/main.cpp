#include "servercommunication.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
using namespace network_st;

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QApplication a(argc, argv);
	ServerCommunication w;
	w.show();
	return a.exec();
}
