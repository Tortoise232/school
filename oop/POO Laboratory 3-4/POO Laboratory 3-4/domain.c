#include<stdio.h>
#include<string.h>
#include "domain.h"
/*Validates the input for creation of a Country structure
	input:
		name - name of the country
		continent - continent to which the country belongs
		population - number of millions of population the country has
	output:
		1 - country data is valid
		0 - country data is invalid*/
int validateCountryInput(char name[], char continent[], int population)
{
	if (name == "")
		return 0;
	if (continent == "")
		return 0;
	if (!strstr("North_America South_America Asia Africa Australia Antarctica Europe", continent))
		return 0;
	if (population <= 0)
		return 0;
	return 1;
}

/*Creates a country structure
	input:
		name - name of the country
		continent - continent of the country
		population - # of millions of population of the country
	output:
		newCountry - Country structure containing the data*/
Country makeCountry(char name[], char continent[], int population)
{
	Country newCountry = { "NULL","NULL",-1 };
	if (validateCountryInput(name, continent, population) != 0)
	{

		strcpy_s(newCountry.name, 30, name);
		strcpy_s(newCountry.continent, 30, continent);
		newCountry.population = population;
	}	
	return newCountry;
}

/*Reads the input for a country structure and constructs the structure
	newName - name of the new country;
	newContinent - continent of the new country;
	population - population of the new country;
	a - new country object;
	Output: invalid country, if name = NULL, continent = NULL and population = -1
			valid country, otherwise*/
Country readCountry()
{
	char newName[30];
	char newContinent[30];
	int population;
	printf("Input country name:\n");
	scanf_s("%s", newName, 30);
	printf("Input country continent:\n");
	scanf_s("%s", newContinent, 30);
	printf("Input country population (how many millions)");
	scanf_s("%d", &population);
	Country a = makeCountry(newName, newContinent, population);
	return a;
	
}

/*Obtains the starting adress of the name of a given country structure pointer
	input: aCountry - pointer to country structure
	output: pointer to starting adress of the name of the given country structure*/
char* getName(Country* aCountry)
{
	return aCountry->name;
}

/*Changes the name attribute of a country structure, replacing it with the given newName string
	input: aCountry - pointer to country structure
			newName - string to replace the name attribute of the given structure*/
void setName(Country* aCountry, char newName[])
{
	strcpy_s(*aCountry->name,30, newName);
}

/*Returns the continent of a given country structure
	input: aCountry - pointer to country structure
	output: string containing the continent attribute of the given country structure
*/
char* getContinent(Country* aCountry)
{
	return aCountry->continent;
}

/*Updates the continent attribute of a given Country structure with the given newContinent string
	input: aCountry - pointer to country structure
	output: newContinent - string to replace
*/
void setContinent(Country* aCountry, char newContinent[])
{
	strcpy_s(*aCountry->continent, 30, newContinent);
}

/*Returns the population attribute of a given Country structure
	input: aCountry - pointer to country structure
	output: pointer to integer representing the population attribute of the country structure*/
int* getPopulation(Country* aCountry)
{
	return aCountry->population;
}

/*Updates the population attribute of a country structure to the given newPopulation integer
	input: aCountry - pointer to Country structure
		   newPopulation - integer representing the new population attribute of the given structure*/
void setPopulation(Country* aCountry, int newPopulation)
{
	aCountry->population = newPopulation;
}
