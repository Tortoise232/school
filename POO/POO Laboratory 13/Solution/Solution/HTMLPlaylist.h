#pragma once
#include "FilePlaylist.h"
class HTMLPlaylist :
	public FilePlaylist

{
public:
	HTMLPlaylist() { filename = "HTML.htmL"; };
	HTMLPlaylist(std::vector<Movie> newVector)
	{
		vector = newVector;
		filename = "data.html";
	}
	~HTMLPlaylist() {};
	void save() ;
	void display() ;
};

