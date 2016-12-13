#include "moviesgui.h"
#include <QtWidgets/QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MoviesGUI w;
	w.show();

	return a.exec();
}
/*
int main(int argc, char *argv[])
{
	//sliderExample(argc, argv);

	QApplication a(argc, argv);
	std::vector<Gene> genes{ Gene{ "yqgE", "E_Coli_K12", "ATGAATTTACAGCAT" }, Gene{ "ppiA", "M_tuberculosis", "TTTTCATCACCGTCGG" }, Gene{ "Col2a1", "Mouse", "TTAAAGCATGGCTCTGTG" } };
	GenesGUI gui{ genes };
	gui.show();
	return a.exec();
}
*/