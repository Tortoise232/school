#include "gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUI w;
	w.initGUI();
	w.show();
	return a.exec();
}
