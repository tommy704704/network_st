#include "FileServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	file_transport_st::FileServer w;
	w.show();
	return a.exec();
}
