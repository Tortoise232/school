#include "Playlist.h"

void Playlist::next()
{
	if (this->current != this->vector.size() - 1)
		this->current++;
	else
		this->current = 0;
}

Movie Playlist::getMovie()
{
	return this->vector[current];
}

Playlist::Playlist()
{

}

bool Playlist::isEmpty()
{
	if (vector.size() == 0)
		return 1;
	return 0;
}

Playlist::~Playlist()
{
}
