#pragma once
#include "CSVPlaylist.h"
#include <fstream>
#include <Windows.h>


void CSVPlaylist::save()
{
	std::ofstream f(this->filename);
	for (auto m : this->vector)
		f << m.getTitle() << "," << m.getGenre() << "," << m.getTrailer() << "," << m.getLikes() << "," << m.getYear() << ",\n";
	f.close();

}

void CSVPlaylist::display()
{
	std::string aux = this->filename;
	ShellExecute(NULL, NULL, "Notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);

}

