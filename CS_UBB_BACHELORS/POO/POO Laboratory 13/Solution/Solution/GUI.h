#ifndef MOVIESGUI_H
#define MOVIESGUI_H
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include<QListWidget>
#include<QPushButton>
#include<QTextEdit>
#include "controller.h"
class GUI : public QWidget
{
	Q_OBJECT

public:
	void initGUI();
	GUI(QWidget *parent = 0);
	~GUI();

private:
	Repository hello;
	Controller* controller = new Controller(hello);
	QLineEdit* titleEdit;
	QLineEdit* genreEdit;
	QLineEdit* linkEdit;
	QLineEdit* yearEdit;
	QLineEdit* likesEdit;
	QListWidget* moviesList;
	QListWidget* watchList;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* updateButton;
	QPushButton* playButton;
	QPushButton* likeButton;
	QPushButton* addWatchButton;



	//void initGUI();
	void connectSignalSlots();
	int getSelectedIndexML();
	int getSelectedIndexWL();

signals:
	void movieListChange();
	void watchListChange();
	void addMovieSignal(std::string title, std::string genre, std::string link, int year, int likes);


	public slots:
	void populateML();
	void populateWL();
	void addButtonHandler();
	void removeButtonHandler();
	void updateButtonHandler();
	void filterButtonHandler();
	void likeButtonHandler();
	void playButtonHandler();
	void addWatchButtonHandler();
	void showInfo();
	void addMovie(std::string title, std::string genre, std::string link, int year, int likes);

};


#endif // MOVIESGUI_H