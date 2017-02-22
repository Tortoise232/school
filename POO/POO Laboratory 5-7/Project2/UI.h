#pragma once
#include "controller.h"
class UI
{
	private:
		Controller controller;
		Vector<Movie> watchList;
	public:
		/*Constructor for the class with one parameter representing the private controller attribute class*/
		UI(Controller controller);
		
		/*Constructor for the class with no parameters*/
		UI();

		/*Adds a new movie to the repository; asks for title, genre, link, year of release and likes*/
		void add();
		
		/*Removes a movie from the repository by asking for a movie title and removing it (if it is in the database)*/
		void remove();

		/*Updates a movie from the repository by asking for the movie title and the rest of the attributes 
			and replacing the ones in the repository (if the respective movie is found)*/
		void update();

		/*Prints all the Movie structures in the repository on the screen*/
		void getAll();

		/*Menu for displaying the options in user mode*/
		void displayOptUser();

		/*Loop that handles entering a mode (administrator/user) and exiting the program*/
		void mainLoop();

		/*Handles the operations in the admin mode submenu*/
		void adminMode();

		/*Handles the operations in the user mode submenu*/
		void userMode();
		
		/*Prints and handles the submenu responsable with entering administrator or user mode*/
		void OptMod();

		/*Handles the operations in the user mode -> movie mode options*/
		void movieModeOpt();

		/*Menu for display the options in administrator mode*/
		void displayOptAdmin();

		/*Handles movie mode*/
		bool enterMovieMode();

		/*Displays all movies in the watchlist*/
		void enterWatchListMode();

};