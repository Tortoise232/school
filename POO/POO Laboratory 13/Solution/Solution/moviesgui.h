#ifndef MOVIESGUI_H
#define MOVIESGUI_H
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include<QListWidget>
#include "ui_moviesgui.h"
#include<QPushButton>
#include"controller.h"

class MoviesGUI : public QWidget
{
	Q_OBJECT

public:
	void initGUI();
	MoviesGUI(QWidget *parent = 0);
	~MoviesGUI();

private:
	Repository repo;
	Controller* controller = new Controller(repo);
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
	QPushButton* filterButton;
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
