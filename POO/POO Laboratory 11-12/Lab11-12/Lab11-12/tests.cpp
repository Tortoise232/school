
#include "tests.h"
#include <assert.h>
#include <string>
#include "MovieExceptions.h"

void tests::testAdd()
{
	Vector<Movie> newVector;
	Movie a;
	Movie b;
	Movie c;
	assert(newVector.getSize() == 0);
	newVector.add(a);
	assert(newVector.getSize() == 1);
	newVector.add(b);
	assert(newVector.getSize() == 2);
	newVector.add(c);
	assert(newVector.getSize() == 3);
}

void tests::testRemove()
{
	Vector<Movie> newVector;
	Movie a;
	a.setTitle("John");
	Movie b;
	b.setTitle("John2");
	newVector.add(a);
	newVector.add(b);
	assert(newVector.getSize() == 2);
	newVector.remove("Jon");
	assert(newVector.getSize() == 2);
	newVector.remove("John");
	assert(newVector.getSize() == 1);
	newVector.remove("John2");
	assert(newVector.getSize() == 0);

}

void tests::testUpdate()
{
	std::vector<Movie> newVector;
	Movie a;
	Repository repo(newVector);
	a.setTitle("John");
	a.setGenre("Horror");
	try
	{repo.addRepo(a);}
	catch (MovieException)
	{}
	assert(strcmp(repo.getVectorGenre("Horror")[0].getGenre(), "Horror") == 0);
	Movie b(a);
	b.setGenre("NotHorror");
	try {repo.update(b);}
	catch (MovieException){}
	assert(strcmp(repo.getVectorGenre("NotHorror")[0].getGenre(), "NotHorror") == 0);

}

void tests::testSort()
{
	Vector<Movie> newVector;
	Movie a;
	Movie b;
	Movie c;
	Movie d;
	a.setGenre("Test");
	b.setGenre("Test");
	c.setGenre("Test");
	newVector.add(a);
	newVector.add(b);
	newVector.add(c);
	d.setGenre("NotTest");
	Vector<Movie> sorted = newVector.getGenre("Test");
	assert(sorted.getSize() == 3);
	assert(strcmp(sorted.getElements()[0].getGenre(), "Test") == 0);
	assert(strcmp(sorted.getElements()[1].getGenre(), "Test") == 0);
	assert(strcmp(sorted.getElements()[2].getGenre(), "Test") == 0);
}