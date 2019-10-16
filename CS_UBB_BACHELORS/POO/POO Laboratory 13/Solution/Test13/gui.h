#ifndef GUI_H
#define GUI_H

#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include<QListWidget>
#include<QPushButton>
#include<QTextEdit>
#include <QtWidgets/QMainWindow>
#include "ui_gui.h"
#include"controller.h"
class GUI : public QWidget
{
	Q_OBJECT

public:
	void initGUI();
	GUI(QWidget *parent = 0);
	~GUI();

private:
	repository repo;
	controller* controler = new controller(repo);
	QLineEdit* descEdit;
	QLineEdit* durEdit;
	QLineEdit* priEdit;
	QListWidget* taskList;
	QPushButton* sortButton;
	QPushButton* filterButton;
	Ui::GUIClass ui;
	void connectSignalSlots();
signals:
	void listchange();

public slots:
void populateList();
void filterButtonHandler();
void sortButtonHandler();
	

};

#endif // GUI_H
