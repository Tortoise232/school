#pragma once
#include "repository.h"
#include <exception> //replace with mine
class controller
{
private:
	repository repo;
public:
	repository& getRepo() { return this->repo; }
	std::vector<Question> getQuestions() { return this->repo.getQuestions(); }
	std::vector<Participant> getUsers() { return this->repo.getUsers(); }
	/*Function adds a question by creating the object Question using the given parameters
	input: int id - id of the question
	int score - score awarded if the answer is found
	string text - the actual text of the question
	string answer - the correct answer to the question
	output: question object, representing the question with the given information
	precondition: valid input (nonempty text and nonempty answer)
	postconditions*/
	void addQuestion(int id,int score, std::string text, std::string answer);
	/*Function removes a question by its id, given that the ID is unique
	input: int id - id of the question
	output: -
	prec: id is acually valid and cannot be a dublicate!
	postc: the question with the given id is not in the repository anymore*/
	void removeQuestion(int id);
	Question CSVtoQuestion(std::string raw) {return this->repo.CSVtoQuestion(raw);}
	Participant CSVtoParticipant(std::string raw) { return this->repo.CSVtoParticipant(raw); }
	void save() { this->repo.save(); }
	/*Function finds the participant with the given name and awards him with the points indicated by the given parameter
	input: int score - points awarded
	string partName - name of the participant who answered corectly and should receive the points
	output: -
	prec: the score is a positive number
	the partName is a valid participant!
	postc: the participant with the given name is awarded the score amount of points*/

	void addPoints(int score, std::string partName);
	void answerQuestion(std::string partName, std::string answer, int id);
	controller();
	~controller();
};

