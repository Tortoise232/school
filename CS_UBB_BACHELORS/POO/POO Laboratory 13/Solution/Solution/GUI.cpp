#include "GUI.h"

GUI::GUI(QWidget *parent)
	: QWidget(parent)
{
	this->initGUI();
	this->connectSignalSlots();
	this->populateML();
}

GUI::~GUI()
{

}

void GUI::initGUI()
{
	QGridLayout* mainLayout = new QGridLayout{ this };
	//list of movies before any processing is done

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
	QFormLayout *propLayout = new QFormLayout{ leftHandSide };
	propLayout->addRow(initialMovieLabel);
	propLayout->addRow(this->moviesList);
	propLayout->addRow(titleLabel, this->titleEdit);
	propLayout->addRow(genreLabel, this->genreEdit);
	propLayout->addRow(linkLabel, this->linkEdit);
	propLayout->addRow(yearLabel, this->yearEdit);
	propLayout->addRow(likesLabel, this->likesEdit);

	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton = new QPushButton{ "Update" };
	QWidget* crudWidget = new QWidget;
	QGridLayout* crudLayout = new QGridLayout{ crudWidget };
	crudLayout->addWidget(this->addButton, 0, 0);
	crudLayout->addWidget(this->removeButton, 0, 1);
	crudLayout->addWidget(this->updateButton, 0, 2);
	propLayout->addRow(crudWidget);

	mainLayout->addWidget(leftHandSide, 0, 0);

}

void GUI::connectSignalSlots() {
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addButtonHandler()));
	QObject::connect(this->removeButton, SIGNAL(clicked()), this, SLOT(removeButtonHandler()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateButtonHandler()));
	QObject::connect(this->addWatchButton, SIGNAL(clicked()), this, SLOT(addWatchButtonHandler()));

	QObject::connect(this->likeButton, SIGNAL(clicked()), this, SLOT(likeButtonHandler()));

	QObject::connect(this->playButton, SIGNAL(clicked()), this, SLOT(playButtonHandler()));

	QObject::connect(this, SIGNAL(movieListChange()), this, SLOT(populateML()));

	QObject::connect(this, SIGNAL(watchListChange()), this, SLOT(populateWL()));

	QObject::connect(this, SIGNAL(addMovieSignal(std::string title, std::string genre, std::string link, int year, int likes)), this, SLOT(addMovie(std::string title, std::string genre, std::string link, int year, int likes)));

};

void GUI::addMovie(std::string title, std::string genre, std::string link, int year, int likes) {
	char title2[30], genre2[30], link2[100];
	strcpy(title2, title.c_str());
	strcpy(genre2, genre.c_str());
	strcpy(title2, title.c_str());
	this->controller->add(title2, genre2, link2, year, likes);
	emit movieListChange();
};

void GUI::addButtonHandler() {
	QString title = this->titleEdit->text();
	QString genre = this->genreEdit->text();
	QString link = this->linkEdit->text();
	QString year = this->yearEdit->text();
	QString likes = this->likesEdit->text();
	emit addMovie(title.toStdString(), genre.toStdString(), link.toStdString(), year.toInt(), likes.toInt());
};

void GUI::removeButtonHandler()
{
	QListWidgetItem* nameLW = new QListWidgetItem;
	nameLW = this->moviesList->selectedItems()[0];
	QString name = nameLW->text();
	std::string nameSS = name.toStdString();
	char *dup = strdup(nameSS.c_str());
	char* token;
	token = strtok(dup, " ");
	nameSS = token;
	free(dup);
	this->controller->remove(this->controller->findByName(nameSS).getTitle());






	//int index = this->getSelectedIndexML();
	//this->controller->removeByIndex(index);
	emit movieListChange();
}

void GUI::populateWL() {
	if (this->watchList->count() > 0)
		this->watchList->clear();
	std::vector<Movie> movies = controller->getWatchList();
	for (auto movie : movies)
	{
		QString movieToString = QString::fromStdString(movie.toString());
		this->watchList->addItem(movieToString);
	}
	if (this->controller->getVector().size() > 0)
		this->watchList->setCurrentRow(0);
};

void GUI::populateML() {
	if (this->moviesList->count() > 0)
		this->moviesList->clear();
	std::vector<Movie> movies = controller->getVector();
	for (auto movie : movies)
	{
		QString movieToString = QString::fromStdString(movie.toString());
		this->moviesList->addItem(movieToString);
	}
	if (this->controller->getVector().size() > 0)
		this->moviesList->setCurrentRow(0);
};

int GUI::getSelectedIndexML()
{
	if (this->moviesList->count() == 0)
		return -1;
	QModelIndexList index = this->moviesList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;

}

int GUI::getSelectedIndexWL()
{
	if (this->watchList->count() == 0)
		return -1;
	QModelIndexList index = this->watchList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;

}

void GUI::updateButtonHandler()
{
	int index = this->getSelectedIndexML();
	this->controller->removeByIndex(index);
	this->addButtonHandler();
}

void GUI::filterButtonHandler()
{
	if (this->moviesList->count() > 0)
		this->moviesList->clear();
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

void GUI::addWatchButtonHandler()
{
	int index = this->getSelectedIndexML();
	this->controller->addWatchList(this->controller->getVector().at(index));
	emit watchListChange();
}

void GUI::likeButtonHandler()
{
	int index = this->getSelectedIndexWL();
	this->controller->getWatchList().at(index).increaseLikes();
	emit watchListChange();
}

void GUI::playButtonHandler()
{
	int index = this->getSelectedIndexWL();
	this->controller->getWatchList().at(index).showTrailer();
}

void GUI::showInfo()
{
	QListWidgetItem* temp = this->moviesList->selectedItems().at(0);
	QString temp2 = temp->text();
	this->watchList->addItem(temp2);

}