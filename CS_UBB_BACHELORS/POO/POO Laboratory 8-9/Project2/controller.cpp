#pragma once
#include "controller.h"
Controller::Controller(Repository repo)
{
	this->repo = repo;
}

Controller::Controller()
{
	std::vector<Movie> newVector;
	Repository newRepo(newVector);
	//newRepo.add5Movies();
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

std::vector<Movie> Controller::getVectorGenre(char genre[30])
{
	return this->repo.getVectorGenre(genre);
}