#pragma once
#include"repo.h"
#include"dynVector.h"
class Controller
{
	protected:
		Repository repo;
	public:
		/*Constructor for the controller structure, using the given parameter for the repository attribute*/
		Controller(Repository repo);

		/*Constructor for the controller structure*/
		Controller();

		/*Creates and add a movie class to the repository attribute
			input:
				newTitle - title of the new movie(array of characters)
				newGenre - genre of the new movie (array of characters)
				newTrailer - link*/
		bool add(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes);

		/*Removes a movie class from the repository, if the movie class has the title attribute identical with the one specified by the parameter
			input:
				newTitle - array of characters representing the title attribute to be found and removed*/
		bool remove(char newTitle[30]);

		/*Updates a movie class if the movie class has the title attribute identical with the one specified by 
			the parameter newTitle by replacing all other attributes with the given parameters*/
		bool update(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes);

		/*Looks for a movie class in the repository if the movie class has the title attribute identical with the one specified by 
			the parameter name and returns 1 if the element is found and 0 if it is not*/
		bool isIn(char name[30]);

		/*Returns a vector class that holds all movie structures with the given genre attribute
			input:
				genre - array of characters representing the genre attribute
			output:
				vector of Movie objects with the given genre attribute*/
		Vector<Movie> getVectorGenre(char genre[30]);

		/*Returns a refference to the vector class*/
		Vector<Movie>& getVector();

};

