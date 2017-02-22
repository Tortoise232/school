#pragma once
#include "Playlist.h"
#include <string>

class FilePlaylist : public Playlist
{
protected:
	std::string filename;
public:
	FilePlaylist();
	FilePlaylist(std::string newName) : filename{ newName } {}
	~FilePlaylist();
	void setFilename(std::string newName)
	{
		filename = newName;
	}
	virtual void save() = 0;
	virtual void display() = 0;
};

