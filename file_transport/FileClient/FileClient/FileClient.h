#ifndef FILECLIENT_H
#define FILECLIENT_H

#include <QtWidgets/QWidget>
#include "ui_FileClient.h"

class FileClient : public QWidget
{
	Q_OBJECT

public:
	FileClient(QWidget *parent = 0);
	~FileClient();

private:
	Ui::FileClientClass ui;
};

#endif // FILECLIENT_H
