#pragma once
#include<exception>
#include<string.h>
class MovieException : public std::exception
{
private:
	char msg[100];

public:
	MovieException(char msg[])
	{
		strcpy(this->msg, msg);
	}
	virtual char* what()
	{
		return this->msg;
	}
};

