#pragma once
#include <exception>
class MovieException : public std::exception
{
private:
	char message[256];
public:
	MovieException(char message[256]);
	virtual char* what();
};