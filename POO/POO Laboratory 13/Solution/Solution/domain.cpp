#include"domain.h"
#include <windows.h>
#include <Shellapi.h>
//Title Genre Trailer Year Likes
char* Movie::getTitle(){ return this->title; }
char* Movie::getGenre() { return this->genre; }
char* Movie::getTrailer() { return this->trailer; }
int Movie::getYear() { return this->yearOfRelease; }
int Movie::getLikes() { return this->likes; }
void Movie::setTitle(char newTitle[]) { strcpy_s(this->title, 30, newTitle); }
void Movie::setGenre(char newGenre[]) { strcpy_s(this->genre, 30, newGenre); }
void Movie::setTrailer(char newTrailer[]) { strcpy_s(this->trailer, 150, newTrailer); }
void Movie::setYear(int newYear) { this->yearOfRelease = newYear; }
void Movie::setLikes(int newLikes) { this->likes = newLikes; }
void Movie::increaseLikes() { this->likes += 1; }
void Movie::showTrailer()
{
	ShellExecuteA(NULL, NULL, "Chrome.exe", this->getTrailer(), NULL, SW_SHOWNORMAL);
}
Movie::Movie()
{
	this->setTitle("");
	this->setGenre("");
	this->setTrailer("");
	this->setYear(0);
	this->setLikes(0);
}

Movie::Movie(char Title[], char Genre[], char Trailer[], int Year, int Likes)
{
	this->setTitle(Title);
	this->setGenre(Genre);
	this->setTrailer(Trailer);
	this->setYear(Year);
	this->setLikes(Likes);
}
Movie::~Movie()
{
	
}

