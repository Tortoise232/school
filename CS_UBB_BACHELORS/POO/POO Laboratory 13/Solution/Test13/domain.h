#pragma once
#include<string>


class Task
{
private:
	std::string description;
	int duration;
	int priority;
public:
	Task();
	~Task();
	void setDesc(std::string newDesc) { this->description = newDesc; }
	void setDuration(int newDuration) { this->duration = newDuration; }
	void setPriority(int newPri) { this->priority = newPri;}
	std::string getDesc() { return this->description; }
	int getDuration() { return this->duration; }
	int getPriority() { return this->priority; }
	std::string toString() {
		std::string aux;
		aux += this->description;
		aux += ",";
		char saux[10];
		itoa(this->duration, saux, 10);
		aux += saux;
		itoa(this->priority, saux, 10);
		aux += ",";
		aux += saux;
		return aux;}

};

