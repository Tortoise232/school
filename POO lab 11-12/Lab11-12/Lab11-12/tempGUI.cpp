
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	

	//list of movies before any processing is done
	QLabel*  initialMovieLabel = new QLabel{ "All Movies:" };
	QListWidget *initialMovieList = new QListWidget;

	//showing properties of a given movie/ adding new movie by filling info
	QLineEdit* titleEdit = new QLineEdit{};
	QLabel*  titleLabel = new QLabel{ "Title:" };
	titleLabel->setBuddy(titleEdit);
	QLineEdit* genreEdit = new QLineEdit{};
	QLabel*  genreLabel = new QLabel{ "Genre:" };
	genreLabel->setBuddy(genreEdit);
	QLineEdit* linkEdit = new QLineEdit{};
	QLabel*  linkLabel = new QLabel{ "URL:" };
	linkLabel->setBuddy(linkEdit);
	QLineEdit* yearEdit = new QLineEdit{};
	QLabel* yearLabel = new QLabel{ "Year of Release:" };
	yearLabel->setBuddy(yearEdit);
	QLineEdit* likesEdit = new QLineEdit{};
	QLabel*  likesLabel = new QLabel{ "Number of likes:" };
	likesLabel->setBuddy(likesEdit);
	//making the first layout containing list and info of all movies
	QFormLayout *moviePropLayout = new QFormLayout;
	moviePropLayout->addRow(initialMovieLabel);
	moviePropLayout->addRow(initialMovieList);
	moviePropLayout->addRow(titleLabel,titleEdit);
	moviePropLayout->addRow(genreLabel, genreEdit);
	moviePropLayout->addRow(linkLabel, linkEdit);
	moviePropLayout->addRow(yearLabel, yearEdit);
	moviePropLayout->addRow(likesLabel, likesEdit);

	QPushButton* addButton = new QPushButton{ "Add" };
	QPushButton* removeButton = new QPushButton{ "Remove" };
	QPushButton* updateButton = new QPushButton{ "Update" };
	QPushButton* filterButton = new QPushButton{ "Filter by genre" };
	QGridLayout* crudLayout = new QGridLayout;
	crudLayout->addWidget(addButton, 0, 0);
	crudLayout->addWidget(removeButton, 0, 1);
	crudLayout->addWidget(updateButton, 0, 2);
	crudLayout->addWidget(filterButton, 1, 1);
	QWidget* crudWidget = new QWidget;
	crudWidget->setLayout(crudLayout);
	moviePropLayout->addRow(crudWidget);
	QWidget *leftHandSide = new QWidget;
	leftHandSide->setLayout(moviePropLayout);
	
	//middle side
	QPushButton* addToPlaylist = new QPushButton{ "-->" };

	//right hand side 
	QLabel* playListLabel = new QLabel{ "Movie Playlist:" };
	QListWidget* playList = new QListWidget;
	
	//buttons corresponding to the playlist
	QPushButton* playTrailer = new QPushButton{ "Trailer" };
	QPushButton* nextMovie = new QPushButton{ "Next" };
	QPushButton* likeMovie = new QPushButton{ "Like" };
	QGridLayout* listButtonLayout = new QGridLayout;
	listButtonLayout->addWidget(playTrailer, 0, 0);
	listButtonLayout->addWidget(nextMovie, 0, 1);
	listButtonLayout->addWidget(likeMovie, 0, 2);
	QWidget* playlistButtons = new QWidget;
	playlistButtons->setLayout(listButtonLayout);
	QFormLayout* rightHandSideLayout = new QFormLayout;
	rightHandSideLayout->addRow(playListLabel);
	rightHandSideLayout->addRow(playList);
	rightHandSideLayout->addRow(playlistButtons);
	QWidget* rightHandSide = new QWidget;
	rightHandSide->setLayout(rightHandSideLayout);


	QGridLayout* mainLayout = new QGridLayout;
	QWidget* starter = new QWidget;
	mainLayout->addWidget(leftHandSide, 0, 0);
	mainLayout->addWidget(addToPlaylist, 0, 1);
	mainLayout->addWidget(rightHandSide, 0, 2);
	starter->setLayout(mainLayout);
	starter->show();
	return a.exec();
}
