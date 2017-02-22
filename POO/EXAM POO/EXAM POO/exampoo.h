#ifndef EXAMPOO_H
#define EXAMPOO_H

#include <QtWidgets/QMainWindow>
#include "ui_exampoo.h"
#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include "controller.h"

class EXAMPOO : public QWidget
{
	Q_OBJECT

public:

	EXAMPOO(controller& ctrl,Participant actual,QWidget *parent = 0): ctrl(ctrl), me(actual)
	{
		this->initGUI();
		this->setWindowTitle(QString::fromStdString(this->me.getName()));
		this->populateList();
		this->connectSignalSlots();
	};
	~EXAMPOO() {};
	void initGUI();
	void connectSignalSlots();

private:
	controller& ctrl;
	Participant& me;
	QLineEdit* text;
	QListWidget* list;
	QPushButton* answer;
	QLineEdit* score;
signals:
	void change();
public slots:
void populateList() ;
void answerHandler();

};
#endif // EXAMPOO_H
