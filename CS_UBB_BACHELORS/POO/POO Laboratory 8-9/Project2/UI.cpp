#pragma once
#include "UI.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "MovieExceptions.h"
#include "Playlist.h"
#include "CSVPlaylist.h"
#include "HTMLPlaylist.h"
void UI::displayOptUser()
{
	std::cout << "\n1.Show movies of genre";
	std::cout << "\n2.Show watch list";
	std::cout << "\nx.Exit user mode";
}



UI::UI(Controller controller)
{
	this->controller = controller;
	Vector<Movie> watchList;
	this->watchList = watchList;
}

UI::UI()
{
	Controller newController;
	this->controller = newController;
}

void UI::OptMod()
{
	char opt = '-1';
	while (opt != 'x')
	{ 
	std::cout << "\n1.Admin mode";
	std::cout << "\n2.User mode";
	std::cout << "\nx.Exit\n";
	std::cin >> opt;
	
		if (opt == '1')
			this->adminMode();
		if (opt == '2')
			this->userMode();
	}
}

void UI::add()
{
	char newTitle[30], newLink[100], newGenre[30];
	int newYear, newLikes;
	std::cout << "\nInput title of the movie: ";
	std::cin >> newTitle;
	std::cout << "\nInput genre of the movie: ";
	std::cin >> newGenre;
	std::cout << "\nInput link of the trailer: ";
	std::cin >> newLink;
	std::cout << "\nInput year of release: ";
	std::cin >> newYear;
	std::cout << "\nInput number of likes";
	std::cin >> newLikes;
	this->controller.add(newTitle, newGenre, newLink, newYear, newLikes);

}

void UI::remove()
{
	char titleToRemove[30];
	std::cout << "\nInput movie title to remove: ";
	std::cin >> titleToRemove;
	this->controller.remove(titleToRemove);
	this->watchList.remove(titleToRemove);
	
}

void UI::update()
{
	char newTitle[30], newLink[100], newGenre[30];
	char newYear[10], newLikes[10];
	std::cout << "\nInput title of the movie: ";
	std::cin >> newTitle;
	std::cout << "\nInput new genre of the movie: ";
	std::cin >> newGenre;
	std::cout << "\nInput new link of the trailer: ";
	std::cin >> newLink;
	std::cout << "\nInput new year of release: ";
	std::cin >> newYear;
	std::cout << "\nInput new number of likes";
	std::cin >> newLikes;
	this->controller.update(newTitle, newGenre, newLink, atoi(newYear), atoi(newLikes));

}

void UI::displayOptAdmin()
{
	std::cout << "\n1.Add a new movie!";
	std::cout << "\n2.Remove an existing movie!";
	std::cout << "\n3.Modify an existing movie!";
	std::cout << "\n4.Print all movies!";
	std::cout << "\nx.Exit";
}

void UI::getAll()
{

	std::vector<Movie>newVector;
	newVector = this->controller.getVector();
	for (std::vector<Movie>::iterator it = newVector.begin(); it != newVector.end(); it++)
		it->printMovie();
}

void UI::adminMode()
{
	{
		char opt = 'e';
		while (opt != 'x')
		{
			this->displayOptAdmin();
			std::cout << "\n";
			std::cin >> opt;
			try
			{
				if (opt == '1')
					this->add();
				if (opt == '2')
					this->remove();
				if (opt == '3')
					this->update();
				if (opt == '4')
					this->getAll();
			}
			catch(MovieException e)
			{
				std::cout << "ERROR: " << e.what();
			}
		}

	}
}
void UI::enterWatchListMode()
{
	std::cout << "WATCH LIST:\n";
	this->watchList.printAll();
	std::cout << "\n\n\nType x to continue";
	char opt;
	std::cin >> opt;
}
void UI::userMode()
{
	
		
			char opt = 'e';
			while (opt != 'x')
			{
				this->displayOptUser();
				std::cout << "\n";
				std::cin >> opt;
				if (opt == '1')
					this->enterMovieMode();
				if (opt == '2')
					this->enterWatchListMode();
			}
}

void UI::movieModeOpt()
{
	std::cout << "\n1.Add movie to watchlist";
	std::cout << "\n2.Show next movie";
	std::cout << "\n3.Show HTML watchlist";
	std::cout << "\n4.Show CSV watchlist";
	std::cout << "\nx.Exit movie mode";
}

bool UI::enterMovieMode()
{
	char optMovie = '-';
	char genre[30];
	std::cout << "\nGive genre of movie (all - display all movies)";
	std::cin >> genre;
	std::vector<Movie> vectorOfGenre;
	vectorOfGenre = this->controller.getVectorGenre(genre);
	HTMLPlaylist newPlaylist(vectorOfGenre);
	CSVPlaylist newPlaylistCSV(vectorOfGenre);
	if (newPlaylist.isEmpty() == 1)
	{
		std::cout << "No movies of genre!";
		return 0;
	}
	std::cout << "SHOWING MOVIES OF GENRE: " << genre <<"\n";
	while (optMovie !='x')
	{
		
		newPlaylist.getMovie().printMovie();
		if(optMovie != '1' && optMovie != '3' && optMovie != '4')
			ShellExecute(NULL, "open", newPlaylist.getMovie().getTrailer(), NULL, NULL, SW_SHOWNORMAL);
		this->movieModeOpt();
		std::cin >> optMovie;
		if (optMovie == '1')
			this->watchList.add(newPlaylist.getMovie());
		if (optMovie == '2')
			newPlaylist.next();
		if (optMovie == '3')
		{
			newPlaylist.save();
			newPlaylist.display();
		}
		if (optMovie == '4')
		{
			newPlaylistCSV.save();
			newPlaylistCSV.display();
		}


	}
	return 0;

}

void UI::mainLoop()
{
	this->OptMod();
	//this->enterMovieMode();
	//this->enterWatchListMode();
	//this->OptMod();
}