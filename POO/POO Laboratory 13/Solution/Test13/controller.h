#pragma once
#include "repository.h"
class controller
{
private:
	repository repo;
public:
	void sortByDuration() { this->repo.sortByDuration(); }
	std::vector<Task>& getVector(){ return this->repo.getVector(); }
	int totalDur(int pri) { return this->repo.totalDur(pri); }
	controller(repository repo);
	~controller();
};

