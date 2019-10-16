#include "controller.h"

void controller::addQuestion(int id,int score, std::string text, std::string answer)
{
	if (text.size() == 0 || answer.size() == 0)
		throw QuestionException("invalid question!");
	for(auto ct: this->getQuestions())
	{
		if (ct.getID() == id)
			throw QuestionException("Identical ID!!");
	}
	Question newQuestion(id, score, text, answer);
	this->repo.addQuestion(newQuestion);
}


void controller::removeQuestion(int id)
{
	this->repo.removeQuestion(id);
}



void controller::addPoints(int score, std::string partName)
{
	Participant& ourParticipant = this->repo.findParticipant(partName);
	this->repo.addScore(ourParticipant, score);
}

void controller::answerQuestion(std::string partName, std::string answer, int id)
{
	Participant& part = this->repo.findParticipant(partName);
	Question& q = this->repo.findQuestion(id);
	if (answer == q.getAnswer())
	{
		this->addPoints(q.getScore(), part.getName());
	}

}

controller::controller()
{

}

controller::~controller()
{
}
