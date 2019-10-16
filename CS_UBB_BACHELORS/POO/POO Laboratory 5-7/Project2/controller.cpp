#pragma once
#include "controller.h"
Controller::Controller(Repository repo)
{
	this->repo = repo;
}

Controller::Controller()
{
	Vector<Movie> newVector;
	Repository newRepo(newVector);
	newRepo.add5Movies();
	this->repo = newRepo;
}

bool Controller::add(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes)
{//1 for error

	Movie newMovie(newTitle, newGenre, newTrailer, newYear, newLikes);
	return this->repo.addRepo(newMovie);

}

bool Controller::remove(char newTitle[30])
{//1 for error
	return this->repo.remove(newTitle);
}

bool Controller::update(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes)
{//1 for error
		Movie newMovie(newTitle, newGenre, newTrailer, newYear, newLikes);
		return this->repo.update(newMovie);
}

bool Controller::isIn(char name[30])
{
	return this->repo.isIn(name);
}

Vector<Movie>& Controller::getVector()
{ 
	return this->repo.getVector();
}

Vector<Movie> Controller::getVectorGenre(char genre[30])
{
	return this->repo.getVectorGenre(genre);
}