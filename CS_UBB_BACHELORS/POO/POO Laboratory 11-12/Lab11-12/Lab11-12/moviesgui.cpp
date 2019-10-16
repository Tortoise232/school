#include "moviesgui.h"

MoviesGUI::MoviesGUI(QWidget *parent)
	: QWidget(parent)
{
	this->initGUI();
	//this->connectSignalSlots();
	//this->populateML();
}

MoviesGUI::~MoviesGUI()
{

}

void MoviesGUI::initGUI()
{
	QGridLayout* mainLayout = new QGridLayout{ this };
	//list of movies before any processing is done
	/*
	QLabel*  initialMovieLabel = new QLabel{ "All Movies:" };
	this->moviesList = new QListWidget{};
	this->moviesList->setSelectionMode(QAbstractItemView::SingleSelection);
	//showing properties of a given movie/ adding new movie by filling info
	this->titleEdit = new QLineEdit{};
	QLabel*  titleLabel = new QLabel{ "Title:" };
	titleLabel->setBuddy(this->titleEdit);

	this->genreEdit = new QLineEdit{};
	QLabel*  genreLabel = new QLabel{ "Genre:" };
	genreLabel->setBuddy(this->genreEdit);

	this->linkEdit = new QLineEdit{};
	QLabel*  linkLabel = new QLabel{ "URL:" };
	linkLabel->setBuddy(this->linkEdit);

	this->yearEdit = new QLineEdit{};
	QLabel* yearLabel = new QLabel{ "Year of Release:" };
	yearLabel->setBuddy(this->yearEdit);

	this->likesEdit = new QLineEdit{};
	QLabel*  likesLabel = new QLabel{ "Number of likes:" };
	likesLabel->setBuddy(this->likesEdit);

	//making the first layout containing list and info of all movies
	QWidget *leftHandSide = new QWidget;
	QFormLayout *moviePropLayout = new QFormLayout{ leftHandSide };
	moviePropLayout->addRow(initialMovieLabel);
	moviePropLayout->addRow(this->moviesList);
	moviePropLayout->addRow(titleLabel, this->titleEdit);
	moviePropLayout->addRow(genreLabel, this->genreEdit);
	moviePropLayout->addRow(linkLabel, this->linkEdit);
	moviePropLayout->addRow(yearLabel, this->yearEdit);
	moviePropLayout->addRow(likesLabel, this->likesEdit);

	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton = new QPushButton{ "Update" };
	this->filterButton = new QPushButton{ "Filter by genre" };
	QWidget* crudWidget = new QWidget;
	QGridLayout* crudLayout = new QGridLayout{ crudWidget };
	crudLayout->addWidget(this->addButton, 0, 0);
	crudLayout->addWidget(this->removeButton, 0, 1);
	crudLayout->addWidget(this->updateButton, 0, 2);
	crudLayout->addWidget(this->filterButton, 1, 1);
	moviePropLayout->addRow(crudWidget);
	*/
	//middle side
	//this->addWatchButton = new QPushButton{ "-->" };

	//right hand side 
	
	this->watchList = new QListWidget{};
	QLabel* playListLabel = new QLabel{ "Movie Playlist:" };
	this->watchList->setSelectionMode(QAbstractItemView::SingleSelection);
	QWidget* playlistButtons = new QWidget;
	//buttons corresponding to the playlist
	QPushButton* playTrailer = new QPushButton{ "Trailer" };
	QPushButton* nextMovie = new QPushButton{ "Next" };
	QPushButton* likeMovie = new QPushButton{ "Like" };
	QGridLayout* listButtonLayout = new QGridLayout{ playlistButtons };
	listButtonLayout->addWidget(playTrailer, 0, 0);
	listButtonLayout->addWidget(nextMovie, 0, 1);
	listButtonLayout->addWidget(likeMovie, 0, 2);
	
	QWidget* rightHandSide = new QWidget;
	QFormLayout* rightHandSideLayout = new QFormLayout{ rightHandSide };
	rightHandSideLayout->addRow(playListLabel);
	rightHandSideLayout->addRow(this->watchList);
	rightHandSideLayout->addRow(playlistButtons);
	
	//mainLayout->addWidget(leftHandSide, 0, 0);
	mainLayout->addWidget(addWatchButton, 0, 1);
	mainLayout->addWidget(rightHandSide, 0, 2);
}

void MoviesGUI::connectSignalSlots()
{
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addButtonHandler()));
	QObject::connect(this->removeButton, SIGNAL(clicked()), this, SLOT(removeButtonHandler()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateButtonHandler()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterButtonHandler()));
	QObject::connect(this->addWatchButton, SIGNAL(clicked()), this, SLOT(addWatchButtonHandler()));
	QObject::connect(this->likeButton, SIGNAL(clicked()), this, SLOT(likeButtonHandler));
	QObject::connect(this->playButton, SIGNAL(clicked()), this, SLOT(playButtonHandler));
	QObject::connect(this, SIGNAL(movieListChange()), this, SLOT(populateML()));
	QObject::connect(this, SIGNAL(watchListChange()), this, SLOT(populateWL()));
	QObject::connect(this, SIGNAL(addMovieSignal(std::string title, std::string genre, std::string link, int year, int likes)), this, SLOT(addMovie(std::string title, std::string genre, std::string link, int year, int likes)));

}

int MoviesGUI::getSelectedIndexML()
{
	if (this->moviesList->count() == 0)
		return -1;
	QModelIndexList index = this->moviesList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;

}

int MoviesGUI::getSelectedIndexWL()
{
	if (this->watchList->count() == 0)
		return -1;
	QModelIndexList index = this->watchList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;

}

void MoviesGUI::populateML()
{
	std::vector<Movie> movies = controller->getVector();
	for (auto movie : movies)
	{
		QString movieToString = QString::fromStdString(movie.toString());
		this->moviesList->addItem(movieToString);
	}
	if (this->controller->getVector().size() > 0)
		this->moviesList->setCurrentRow(0);
}

void MoviesGUI::populateWL()
{
 //redo watchList;	
}

void MoviesGUI::addButtonHandler()
{
	QString title = this->titleEdit->text();
	QString genre = this->genreEdit->text();
	QString link = this->linkEdit->text();
	QString year = this->yearEdit->text();
	QString likes = this->likesEdit->text();
	emit addMovie(title.toStdString(), genre.toStdString(), link.toStdString(), year.toInt(), likes.toInt());
}

void MoviesGUI::removeButtonHandler()
{
	int index = this->getSelectedIndexML();
	this->controller->removeByIndex(index);
	emit movieListChange();
}

void MoviesGUI::updateButtonHandler()
{
	int index = this->getSelectedIndexML();
	this->controller->removeByIndex(index);
	this->addButtonHandler();
}

void MoviesGUI::filterButtonHandler()
{
	QString genre = this->genreEdit->text();
	std::vector<Movie> vectorOfGenre = this->controller->getVectorGenre(genre.toStdString());
	
	for (auto movie : vectorOfGenre)
	{
		QString movieToString = QString::fromStdString(movie.toString());
		this->moviesList->addItem(movieToString);
	}
	if (this->controller->getVector().size() > 0)
		this->moviesList->setCurrentRow(0);
}

void MoviesGUI::likeButtonHandler() {}
void MoviesGUI::playButtonHandler() {}
void MoviesGUI::addWatchButtonHandler() {}
void MoviesGUI::showInfo() {}
void MoviesGUI::addMovie(std::string title, std::string genre, std::string link, int year, int likes) 
{
	char title2[30], genre2[30], link2[150];
	strcpy(title2, title.c_str());
	strcpy(genre2, genre.c_str());
	strcpy(title2, title.c_str());
	this->controller->add(title2, genre2, link2, year, likes);
	
}