#pragma once
#include"domain.h"
#include <vector>
#include<string.h>
class Repository
{
public:
	/*Constructor for the repository structure, having as parameter a generic dynamic vector*/
	Repository(std::vector<Movie> vector);
	/*Constructor for the repository structure, having no parameters*/
	Repository();
	/*Destructor*/
	~Repository();
	/*Adds a class of type Movie to the repository class*/
	void addRepo(Movie newMovie);
	/*Removes a class of type Movie from the repository class if the movie class has as title attribute the given array of characters (name)*/
	void remove(char name[30]);
	/*Updates the information contained in a Movie class stored in the repository class, by matching the title attributes and replacing all other attributes*/
	void update(Movie newMovie);
	/*Looks for a Movie class having the title attribute identical to the given array of characters (name) and returns a boolean value according to whether the class was found or not*/
	bool isIn(char name[30]);
	/*Adds 5 predefined movies to the repository*/
	void add5Movies();
	/*Returns a vector structure containing all the elements found in the initial structure as having the attribute genre identical to the given parameter (genre)*/
	std::vector<Movie> getVectorGenre(char genre[30]);
	/*Returns the attribute of the Repository class that is represented by the generic vector structure*/
	std::vector<Movie>& getVector();
	/*Saves the repository into a file*/
	void saveVector();
	/*Loads the repository from a file*/
	void removeByIndex(int index);
	void loadVector();
private:
	/*Vector structure that holds the elements of the repository*/
	std::vector<Movie> vector;

};