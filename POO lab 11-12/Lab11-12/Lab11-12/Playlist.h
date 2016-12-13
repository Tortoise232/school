#pragma once
#include<vector>
#include "domain.h"
class Playlist
{
protected:
	std::vector<Movie> vector;
	int current;
public:
	void next();
	Movie getMovie();
	Playlist();
	Playlist(std::vector<Movie> vector)
	{
		this->vector = vector;
	}
	bool isEmpty();
	~Playlist();
};

