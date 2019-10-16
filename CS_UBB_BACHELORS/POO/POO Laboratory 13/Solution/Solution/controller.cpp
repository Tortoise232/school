#pragma once
#include "controller.h"
Controller::Controller(Repository repo)
{
	this->repo = repo;
	Repository wlr;
	this->watchListRepo = wlr;
	this->repo.add5Movies();
}

Controller::Controller()
{
	std::vector<Movie> newVector;
	Repository newRepo(newVector);
	this->repo = newRepo;
	
}

void Controller::add(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes)
{

	Movie newMovie(newTitle, newGenre, newTrailer, newYear, newLikes);
	this->repo.addRepo(newMovie);
}

void Controller::remove(char newTitle[30])
{
	this->repo.remove(newTitle);
}

void Controller::update(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes)
{
		Movie newMovie(newTitle, newGenre, newTrailer, newYear, newLikes);
		this->repo.update(newMovie);
}

bool Controller::isIn(char name[30])
{
	return this->repo.isIn(name);
}

std::vector<Movie>& Controller::getVector()
{ 
	return this->repo.getVector();
}

std::vector<Movie> Controller::getVectorGenre(std::string genre)
{
	char genreStr[30];
	strcpy(genreStr, genre.c_str());
	return this->repo.getVectorGenre(genreStr);
}

void Controller::removeByIndex(int index)
{
	this->repo.removeByIndex(index);
}


void Controller::addWatchList(Movie someMovie)
{
	this->watchListRepo.addRepo(someMovie);
}


std::vector<Movie>& Controller::getWatchList()
{
	return this->watchListRepo.getVector();
}

Movie Controller::findByName(std::string name)
{
	return this->repo.findByName(name);
}