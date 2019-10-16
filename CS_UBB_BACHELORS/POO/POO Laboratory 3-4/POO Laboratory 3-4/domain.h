#pragma once
typedef struct {
	char name[30];
	char continent[30];
	int population;
}Country;

int validateCountryInput(char name[], char continent[], int population);

Country makeCountry(char name[], char continent[], int population);

Country readCountry();

char* getName(Country* aCountry);

void setName(Country* aCountry, char newName[]);

char* getContinent(Country* aCountry);

void setContinent(Country* aCountry, char newContinent[]);

int* getPopulation(Country* aCountry);

void setPopulation(Country* aCountry, int newPopulation);