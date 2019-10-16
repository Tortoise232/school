#pragma once
#include "domain.h"
#include <vector>
class repository
{
private:
	std::vector<Participant> users;
	std::vector<Question> questions;
public:
	std::vector<Participant>& getUsers() { return this->users; }
	std::vector<Question>& getQuestions() { return this->questions; };
	void save() ;
	void load() ;
	Question CSVtoQuestion(std::string raw);
	Participant CSVtoParticipant(std::string raw);
	Question& findQuestion(int id);
	void addParticipant(Participant p);
	void addQuestion(Question question);
	void removeQuestion(int id);
	void addScore(Participant p,int score);
	Participant& findParticipant(std::string name);

	repository();
	~repository();
};

