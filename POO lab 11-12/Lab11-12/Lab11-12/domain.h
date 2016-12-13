#pragma once
#include<string.h>
#include<stdlib.h>
#include<iostream>

/*Stores the title, genre, URL-trailer, year of release and number of likes of a movie*/
class Movie
{
private:
	char title[30];
	char genre[30];
	char trailer[150];
	int yearOfRelease;
	int likes = 0;

public:
	/*Returns the pointer to an array of characters representing the title of the movie structure*/
	char* Movie::getTitle();
	/*Returns the pointer to an array of characters representing the genre of the movie structure*/
	char* Movie::getGenre();
	/*Returns the pointer to an array of characters representing the URL-trailer of the movie structure*/
	char* Movie::getTrailer();
	/*Returns the integer representing the year of the release of the movie structures*/
	int Movie::getYear();
	/*Returns the integer representing the number of likes of the movie structure*/
	int Movie::getLikes();
	/*Assigns the given array of characters as the title of the movie structure*/
	void Movie::setTitle(char newTitle[]);
	/*Assigns the given array of characters as the genre of the movie structure*/
	void Movie::setGenre(char newGenre[]);
	/*Assigns the given array of characters as the URL-trailer of the movie structure*/
	void Movie::setTrailer(char newTrailer[]);
	/*Assigns the given integer as the year of the release of the movie structure*/
	void Movie::setYear(int newYear);
	/*Assigns the given integer as the number of likes of the movie structure*/
	void Movie::setLikes(int newLikes);
	/*Increments the number of likes of the movie structure as one*/
	void Movie::increaseLikes();
	/*Opens the web-page associated to the trailer attribute of the movie structure*/
	void Movie::showTrailer();
	/*Prints the information associated to the movie structure on screen(ExampleTitle of genre ExampleGenre released in ExampleYear with ExampleLikes likes;*/
	void Movie::printMovie()
	{
		std::cout << "\n" << this->getTitle();
		std::cout << " from year " << this->getYear() << " with " << this->getLikes() << " likes;";
	}

	std::string Movie::toString()
	{
		std::string str = "";
		str += this->getTitle();
		str += " ";
		str += this->getGenre();
		char a[10];
		itoa(this->getYear(), a, 10);
		str += " ";
		str += a;
		return str;
	}

	/*Constructor of the movie structure; no parameters*/
	Movie::Movie();
	/*Constructor of the movie structure with parameters representing the attributes*/
	Movie::Movie(char Title[], char Genre[], char Trailer[1], int Year, int Likes);
	/*Destructor of the movie structure*/
	~Movie();
	//Movie(const Movie& source);

};



