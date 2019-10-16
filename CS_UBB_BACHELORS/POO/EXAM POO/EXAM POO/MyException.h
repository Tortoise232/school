#pragma once
#include<exception>
#include<string.h>
class QuestionException : public std::exception
{
private:
	char msg[100];

public:
	QuestionException(char msg[])
	{
		strcpy(this->msg, msg);
	}
	virtual char* what()
	{
		return this->msg;
	}
};

