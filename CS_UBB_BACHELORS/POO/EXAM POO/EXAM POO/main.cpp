#pragma once
#include "exampoo.h"
#include <QtWidgets/QApplication>
#include "presenter.h"
#include "tests.h"
int main(int argc, char *argv[])
{
	test tryTests;
	QApplication a(argc, argv);
	controller mainCtrl;
	presenter* Presenter = new presenter(mainCtrl);
	Presenter->show();
	EXAMPOO* participant;
	for (auto participants : mainCtrl.getUsers())
	{
		
		participant = new EXAMPOO(mainCtrl, participants);
		participant->show();
		QObject::connect(participant, SIGNAL(change()), Presenter, SLOT(populateList()));
		QObject::connect(Presenter, SIGNAL(change()), participant, SLOT(populateList()));
	}

	return a.exec();
}
