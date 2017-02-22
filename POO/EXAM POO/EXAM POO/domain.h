#pragma once
#include <string>
#include <stdlib.h>
#include "MyException.h"
class Question
{
private:
	int id;
	std::string text;
	std::string answer;
	int score;
public:
	int getID() { return this->id; }
	void setID(int id) { this->id = id; }
	std::string getText() { return this->text; }
	void setText(std::string text) { this->text = text; }
	std::string getAnswer() { return this->answer; }
	void setAnswer(std::string answer) { this->answer = answer; }
	int getScore() { return this->score; }
	void setScore(int score) { this->score = score; }
	std::string toString()
	{
		char aux[10];
		std::string output;
		itoa(this->id, aux, 10);
		output += aux;
		output += ",";
		output += text;
		output += ",";
		output += answer;
		output += ",";
		itoa(this->score, aux, 10);
		output += aux;
		return output;
	}
	std::string toStringPart()
	{
		char aux[10];
		std::string output;
		itoa(this->score, aux, 10);
		output += aux;
		output += ",";
		output += text;
		output += ",";
		itoa(this->id, aux, 10);
		output += aux;
		return output;
	}
	Question() {};
	Question(int id, int score, std::string text, std::string answer) : score(score), id(id), text(text), answer(answer) {};
	~Question() {};
};


class Participant
{
private:
	int score;
	std::string name;
public:
	int getScore() { return this->score; }
	void setScore(int newScore) { this->score = newScore; }
	std::string getName() { return this->name; }
	void setName(std::string name) { this->name = name; }
	std::string toString()
	{
		char aux[10];
		itoa(score, aux, 10);
		std::string output;
		output += aux;
		output += ",";
		output += name;
		return output;
	}
	Participant() {};
	Participant(int score, std::string name) : score(score), name(name) {};
	~Participant() {};
	bool operator==(Participant other)
	{
		if (this->name == other.name)
			if (this->score == other.score)
				return true;
		return false;
	}
};
