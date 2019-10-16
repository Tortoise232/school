#include "repository.h"
#include <fstream>
void repository::load()
{
	char data[256];
	char aux[256] = "";
	int dataStoragePointer = 0;
	Task newTask;
	std::ifstream input;
	input.open("data.txt");
	while (!input.eof())
	{
		input.getline(data, 256);
		for (int counter = 0; counter < strlen(data); counter++)
		{
			if (data[counter] == ',')
			{
				strcpy(aux, "");
				strncpy(aux, data, counter);
				switch (dataStoragePointer)
				{
				case 0: {newTask.setDesc(aux); break;}
				case 1: {newTask.setDuration(atoi(aux)); break;}
				case 2: {newTask.setPriority(atoi(aux)); break;}
				default: {break;}
				}
				dataStoragePointer++;
				strncpy(aux, "", 256);
				if (dataStoragePointer == 2)
					dataStoragePointer = 0;
				strcpy(data, data + counter + 1);
				counter = 0;
			}

		}
		strcpy(data, "");
		this->vector.push_back(newTask);
	}
	input.close();
}

void repository::sortByDuration()
{
	Task aux;
	for (std::vector<Task>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		for (std::vector<Task>::iterator it2 = it+1; it2 != this->vector.end(); it2++)
			if (it->getDuration() > it2->getDuration())
			{
				aux = *it;
				*it = *it2;
				*it2 = aux;
			}

}

int repository::totalDur(int priority)
{
	int sum = 0;
	for (std::vector<Task>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		if (it->getPriority() == priority)
			sum += it->getDuration();
	return sum;
}

repository::repository()
{
	this->load();
}


repository::~repository()
{
}
