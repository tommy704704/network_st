#include "FileClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileClient w;
	w.show();
	return a.exec();
}
