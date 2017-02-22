#pragma once
#include "FilePlaylist.h"
class CSVPlaylist :
	public FilePlaylist
{
public:
	CSVPlaylist() {};
	CSVPlaylist(std::vector<Movie> newVector)
	{
		vector = newVector;
		filename = "data.txt";
	}
	~CSVPlaylist() {};
	void save();
	void display();


};

