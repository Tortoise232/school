#include "repo.h"
#include <vector>
#include <fstream>
#include "validators.h"
Repository::Repository(std::vector<Movie> vector)
{
	this->vector = vector;
	this->loadVector();
	
}

Repository::Repository()
{
	std::vector<Movie> newVector;
	this->vector = newVector;
	
}

void Repository::addRepo(Movie movie)
{//Both adding types
	validateMovie(movie);
	if (this->isIn(movie.getTitle()))
		throw MovieException("Movie already in list!");
	this->vector.push_back(movie);
	//return (this->vector + movie);
}

Repository::~Repository()
{
	this->saveVector();
}

void Repository::remove(char name[30])
{

	bool check = 0;
	if (this->vector.begin() == this->vector.end())
		throw MovieException("\nList is empty!\n");
	for (std::vector<Movie>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		if (strcmp(it->getTitle(), name) == 0)
		{
			this->vector.erase(it);
			check = 1;
			break;
		}
	if (check == 0)
		throw MovieException("Movie not in list!\n");

	//SEMINARY VERSION (not gonna happen bc i'm not using objects)
	//std::vector<Movie>::iterator removeIt = std::find(this->vector.begin(),this->vector.end(),-object-)


}

void Repository::update(Movie newMovie)
{
	this->remove(newMovie.getTitle());
	this->addRepo(newMovie);
}

std::vector<Movie>& Repository::getVector()
{
	
	return this->vector;
}

bool Repository::isIn(char name[30])
{//1 for found
	for (std::vector<Movie>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		if (strcmp(it->getTitle(), name) == 0)
			return 1;
	return 0;
}

std::vector<Movie> Repository::getVectorGenre(char genre[30])
{
	std::vector<Movie> vectorGenre;
	for (std::vector<Movie>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		if (strcmp(it->getGenre(), genre) == 0)
			vectorGenre.push_back(*it);
	return vectorGenre;
}	

void Repository::add5Movies()
{

	Movie m1;
	Movie m2;
	Movie m3;
	Movie m4;
	Movie m5;
	m1.setTitle("Star_wars_1");
	m1.setGenre("Sci-fi");
	m1.setLikes(40);
	m1.setTrailer("https://www.youtube.com/watch?v=KfQBdRcgizc");
	m1.setYear(1970);
	m2.setTitle("Donnie_Darko");
	m2.setGenre("Sci-fi");
	m2.setLikes(20);
	m2.setTrailer("https://www.youtube.com/watch?v=ZZyBaFYFySk");
	m2.setYear(2001);
	m3.setTitle("Star_Trek_Beyond");
	m3.setGenre("Sci-fi");
	m3.setLikes(100);
	m3.setTrailer("https://www.youtube.com/watch?v=XRVD32rnzOw");
	m3.setYear(2016);
	m4.setTitle("The_purge");
	m4.setGenre("Horror");
	m4.setLikes(13);
	m4.setTrailer("https://www.youtube.com/watch?v=K0LLaybEuzA");
	m4.setYear(2013);
	m5.setTitle("Deadpool");
	m5.setGenre("Action");
	m5.setLikes(410);
	m5.setTrailer("https://www.youtube.com/watch?v=ZIM1HydF9UA");
	m5.setYear(2015);
	this->vector.push_back(m1);
	this->vector.push_back(m2);
	this->vector.push_back(m3);
	this->vector.push_back(m4);
	this->vector.push_back(m5);
	//this->saveVector();
	//this->loadVector();
	//this->saveVector();	
}

void Repository::loadVector()
{
	char data[256];
	char aux[256] = "";
	int dataStoragePointer = 0;
	Movie newMovie;
	std::ifstream input;
	input.open("data.txt");
	while (!input.eof())
	{
		input.getline(data, 256);
		for (int counter = 0; counter < strlen(data); counter++)
		{
			if (data[counter] == ';')
			{
				strcpy(aux, "");
				strncpy(aux, data, counter);
				switch (dataStoragePointer) 
				{
					case 0: {newMovie.setTitle(aux); break;}
					case 1: {newMovie.setGenre(aux); break;}
					case 2: {newMovie.setTrailer(aux); break;}
					case 3: {newMovie.setLikes(atoi(aux)); break;}
					case 4: {newMovie.setYear(atoi(aux)); break;}
					default: {break;}
				}
				dataStoragePointer++;
				strncpy(aux, "",256);
				if (dataStoragePointer == 5)
					dataStoragePointer = 0;
				strcpy(data, data + counter + 1);
				counter = 0;
			}
			
		}
		strcpy(data, "");
		if(!this->isIn(newMovie.getTitle()))
			this->vector.push_back(newMovie);
	}
	input.close();
}

void Repository::saveVector()
{
	std::ofstream output;
	output.open("data.txt");
	for (Movie m : this->vector)
	{
		output << m.getTitle() << ";" << m.getGenre() << ";" << m.getTrailer() << ";" << m.getLikes() << ";" << m.getYear() << ";\n";
	}
	output.close();
}

void Repository::removeByIndex(int index)
{
	bool check = 0;
	if (this->vector.begin() == this->vector.end())
		throw MovieException("\nList is empty!\n");
	int othercounter = 0;
	for (std::vector<Movie>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
	{
		
		if (othercounter == index)
		{
			this->vector.erase(it);
			check = 1;
			break;
		}
		othercounter++;
	}
	if (check == 0)
		throw MovieException("Movie not in list!\n");
}

Movie Repository::findByName(std::string name)
{
	for (std::vector<Movie>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		if (name == it->getTitle())
			return *it;
}