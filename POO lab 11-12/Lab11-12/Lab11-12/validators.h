#pragma once
#include "domain.h"
#include "MovieExceptions.h"
void validateMovie(Movie elem)
{
	if (strcmp(elem.getTitle(), "") == 0)
		throw MovieException("\nEmpty title!\n");
	if (elem.getYear() < 1850)
		throw MovieException("\nInvalid year!\n");
	if (elem.getLikes() < 0)
		throw MovieException("\nNegative number of likes!\n");
	if (strcmp(elem.getTrailer(), "") == 0)
		throw MovieException("\nEmpty link!\n");
	if (strcmp(elem.getGenre(), "") == 0)
		throw MovieException("\nEmpty genre!\n");
}

