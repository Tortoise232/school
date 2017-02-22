#pragma once
bool validateMovie(char newTitle[30], char newGenre[30], char newTrailer[100], int newYear, int newLikes)
{
	
	return 0;
}

bool validateTitleInVector(char Title[30], Controller controller)
{//if the element is found in the vector return 1(false)
	return controller.isIn(Title);
}