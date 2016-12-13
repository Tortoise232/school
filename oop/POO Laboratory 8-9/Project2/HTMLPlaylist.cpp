#pragma once
#include "HTMLPlaylist.h"
#include <fstream>
#include <Windows.h>

void HTMLPlaylist::save()
{
	std::ofstream f(this->filename);
	f << "<!DOCTYPE html>";
	f << "<html> <head> <title> Movie List </title> </head> <body>";
	f << "<table border =\"1\">";
	f << "<tr> <td> Title </td> <td> Genre </td> <td> Year </td> <td> Likes  </td> <td> Link </td>";
	f << "</tr>";
	for (auto m : this->vector)
		f << "<tr>"  << "<td>" << m.getTitle() << "</td><td>" << m.getGenre() << "</td><td>" << m.getYear() << "</td><td>" << m.getLikes() << "</td><td>" << "<a href = \"" << m.getYear() << "\">Link</a></td>";
	f << "</tr>";
	f.close();
}

void HTMLPlaylist::display()
{
	std::string aux = this->filename;
	ShellExecute(NULL, NULL, "Chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}