#include "repository.h"
#include <fstream>
void repository::addQuestion(Question question)
{
	this->questions.push_back(question);
}

void repository::addParticipant(Participant p)
{
	this->users.push_back(p);
}

Question& repository::findQuestion(int id)
{
	std::vector<Question>::iterator it;
	for (it = this->questions.begin(); it != this->questions.end(); it++)
	{
		if (it->getID() == id)
			return *it;
	}

}

/*Function removes a question by its id, given that the ID is unique
input: int id - id of the question
output: -
prec: id is acually valid and cannot be a dublicate!
postc: the question with the given id is not in the repository anymore*/
void repository::removeQuestion(int id)
{
	std::vector<Question>::iterator it;
	for (it = this->questions.begin(); it != this->questions.end(); it++)
	{
		if (it->getID() == id)
		{
			this->questions.erase(it);
			return;
		}
		
	}
	throw QuestionException("Question not found?!");

}

Participant& repository::findParticipant(std::string name)
{
	std::vector<Participant>::iterator it;
	for (it = this->users.begin(); it != this->users.end(); it++)
	{
		if (it->getName() == name)
			return *it;
	}

}

void repository::addScore(Participant p, int score)
{
	auto it = std::find(this->users.begin(), this->users.end(), p);
	it->setScore(it->getScore() + score);
}
//score and name
Participant repository::CSVtoParticipant(std::string raw)
{
	std::size_t aux = raw.find(",");
	int score = atoi(raw.substr(0, aux).c_str());
	std::string name = raw.substr(aux + 1, raw.size());
	Participant newPart(score, name);
	return newPart;
	
}
// id text answer score
Question repository::CSVtoQuestion(std::string raw)
{
	std::size_t aux = raw.find(",");
	int id = atoi(raw.substr(0, aux).c_str());
	raw = raw.substr(aux + 1, raw.size());
	aux = raw.find(",");
	std::string text = raw.substr(0, aux);
	raw = raw.substr(aux + 1, raw.size());
	aux = raw.find(",");
	std::string answer = raw.substr(0, aux);
	int score = atoi(raw.substr(aux + 1, raw.size()).c_str());
	Question newQ(id, score, text, answer);
	return newQ;

}

void repository::load()
{
	std::ifstream inPart;
	std::string raw;
	inPart.open("participant.txt");
	while (!inPart.eof())
	{
		getline(inPart, raw);
		if (raw.size() > 2)
			this->addParticipant(CSVtoParticipant(raw));
	}
	inPart.close();
	std::ifstream inQuestions;
	inQuestions.open("question.txt");
	while (!inQuestions.eof())
	{
		getline(inQuestions, raw);
		if (raw.size() > 3)
			this->addQuestion(CSVtoQuestion(raw));
	}
	inQuestions.close();
}

void repository::save()
{
	std::ofstream outQ;
	outQ.open("question.txt");
	for (auto ct : this->getQuestions())
	{
		outQ << ct.toString().c_str() << "\n";
	}
	outQ.close();
}


repository::repository()
{
	this->load();
}


repository::~repository()
{
}
