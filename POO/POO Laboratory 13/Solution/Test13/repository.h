#pragma once
#include <vector>
#include "domain.h"
class repository
{
private:
	std::vector<Task> vector;
public:
	void load();
	std::vector<Task>& getVector() { return this->vector; }
	void sortByDuration();
	int totalDur(int priority);
	repository();
	~repository();
};

