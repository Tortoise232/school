#pragma once
#include"domain.h"
#include"dynVector.h"
#include <vector>
class Repository
{
public:
	/*Constructor for the repository structure, having as parameter a generic dynamic vector*/
	Repository(Vector<Movie> vector);
	/*Constructor for the repository structure, having no parameters*/
	Repository();
	/*Adds a class of type Movie to the repository class*/
	bool addRepo(Movie newMovie);
	/*Removes a class of type Movie from the repository class if the movie class has as title attribute the given array of characters (name)*/
	bool remove(char name[30]);
	/*Updates the information contained in a Movie class stored in the repository class, by matching the title attributes and replacing all other attributes*/
	bool update(Movie newMovie);
	/*Looks for a Movie class having the title attribute identical to the given array of characters (name) and returns a boolean value according to whether the class was found or not*/
	bool isIn(char name[30]);
	/*Adds 5 predefined movies to the repository*/
	void add5Movies();
	/*Returns a vector structure containing all the elements found in the initial structure as having the attribute genre identical to the given parameter (genre)*/
	Vector<Movie> getVectorGenre(char genre[30]);
	/*Returns the attribute of the Repository class that is represented by the generic vector structure*/
	Vector<Movie>& getVector();
private:
	/*Vector structure that holds the elements of the repository*/
	Vector<Movie> vector;
};