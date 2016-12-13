#include "repo.h"
#include "dynVector.h"
#include <vector>

Repository::Repository(Vector<Movie> vector)
{
	this->vector = vector;
}

Repository::Repository()
{
	this->vector = Vector<Movie>();
}

bool Repository::addRepo(Movie movie)
{//Both adding types
	return (movie + this->vector);
	//return (this->vector + movie);
}

bool Repository::remove(char name[30])
{
	return (this->vector - name);
}

bool Repository::update(Movie newMovie)
{
	if (this->vector.remove(newMovie.getTitle()))
		return 1;
	if (this->addRepo(newMovie))
		return 1;	
	return 0;
}

Vector<Movie>& Repository::getVector()
{
	
	return this->vector;
}

bool Repository::isIn(char name[30])
{
	return this->vector.isIn(name);
}

Vector<Movie> Repository::getVectorGenre(char genre[30])
{
	Vector<Movie> vectorGenre(this->vector.getGenre(genre));
	return vectorGenre;
}	

void Repository::add5Movies()
{

	Movie m1;
	Movie m2;
	Movie m3;
	Movie m4;
	Movie m5;
	m1.setTitle("Star wars 1");
	m1.setGenre("Sci-fi");
	m1.setLikes(40);
	m1.setTrailer("https://www.youtube.com/watch?v=KfQBdRcgizc");
	m1.setYear(1970);
	m2.setTitle("Donnie Darko");
	m2.setGenre("Sci-fi");
	m2.setLikes(20);
	m2.setTrailer("https://www.youtube.com/watch?v=ZZyBaFYFySk");
	m2.setYear(2001);
	m3.setTitle("Star Trek Beyond");
	m3.setGenre("Sci-fi");
	m3.setLikes(100);
	m3.setTrailer("https://www.youtube.com/watch?v=XRVD32rnzOw");
	m3.setYear(2016);
	m4.setTitle("The purge");
	m4.setGenre("Horror");
	m4.setLikes(13);
	m4.setTrailer("https://www.youtube.com/watch?v=K0LLaybEuzA");
	m4.setYear(2013);
	m5.setTitle("Deadpool");
	m5.setGenre("Action");
	m5.setLikes(410);
	m5.setTrailer("https://www.youtube.com/watch?v=ZIM1HydF9UA");
	m5.setYear(2015);
	this->vector.add(m1);
	this->vector.add(m2);
	this->vector.add(m3);
	this->vector.add(m4);
	this->vector.add(m5);
}