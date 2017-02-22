#pragma once
#include "exampoo.h"
#include "errorGUI.h"
class presenter : public QWidget
{
	Q_OBJECT
public:
	presenter(controller& ctrl, QWidget *parent = 0): ctrl(ctrl) 
	{
		this->initGUI();
		this->connectSignalSlots();
		this->populateList();
	};
	~presenter() {};
	void initGUI();
	void connectSignalSlots() ;
private:
	controller& ctrl;
	QLineEdit* idQ;
	QLineEdit* textQ;
	QLineEdit* answerQ;
	QLineEdit* scoreQ;
	QPushButton* add;
	QPushButton* remove;
	QListWidget* list;

signals:
	void change();
public slots:
void addHandler() ;
void removeHandler() ;
void populateList() ;
void save();

};

