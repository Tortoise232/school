#include "domain.h"
#include "repo.h"


vector* initRepo()
{
	vector* data;
	data = (vector*)malloc(sizeof(vector));
	data->list = (Country**)malloc(100 * sizeof(Country*));
	data->length = (int*)malloc(sizeof(int));
	data->index = (int*)malloc(sizeof(int));
	*(data->index) = 0;
	*(data->length) = 0;
	return data;
}

/*Adds a country at the location (in the vector) indicated by the index
input: repo - vector structure, meant to hold country data
		newCountry - country structure, to be added to the vector
output: pointer to vector structure
*/
void addCountry(vector repo, Country* newCountry)
{	
	repo.list[*repo.index] = newCountry;
	*(repo.index) = *(repo.index)+1;
	*(repo.length) += 1;
	//return &repo;
}

/*Remove a country identical to the one given as input from the vector of structures
input: repo - vector structure, meant to hold country data
		countryToDelete - country structure, to be deleted from structure
*/
void removeCountry(vector repo, Country* countryToDelete)
{	
	Country* auxCountry;
	int deleteIndex;
	for (int counter = 0; counter < *repo.length; counter++)
	{
		auxCountry = repo.list[counter];
		if (countryToDelete == auxCountry)
			deleteIndex = counter;
	}
	for (int counter = deleteIndex + 1; counter < *repo.length; counter++)
		repo.list[counter - 1] = repo.list[counter];
	repo.list[*repo.length] = 0; //null pointer
	--*repo.length;
	--*repo.index;

}

/*Updates a country, by changing it's continent and population with the one of the country structure received as parameter
	input: repo - vector structure, repository for the Country structures
			updatedCountry - Country structure, representing the updated version of the country which is to be updated
	output: 0 - if function did not find a country 
			1 - if function found a country to update*/
int updateCountry(vector repo, Country* updatedCountry)
{
	Country* auxCountry;
	for (int counter = 0; counter < *repo.length; counter++)
	{
		auxCountry = repo.list[counter];
		if (strcmp(updatedCountry->name, auxCountry->name) == 0)
		{
			strcpy_s(auxCountry->continent, 30, updatedCountry->continent);
			auxCountry->population = updatedCountry->population;
			return 1;
		}
	}
	return 0;
}

/*Identifies a country in the vector repository by name, returning a pointer to the vector structure if said name is found
	input: repo - vector structure, repository for the Country structures
			name - string represnting name of Country structure being searched
	output: pointer to found structure
*/
Country* findCountryByName(vector repo, char* name)
{

	Country* auxCountry = (Country*)malloc(sizeof(Country));
	for (int counter = 0; counter < *repo.length; counter++)
	{
		auxCountry = repo.list[counter];
		if (strcmp(auxCountry->name, name) == 0)
			return auxCountry;
	}
	return 0;
}

/*Finds all countries that have as continent attribute the given parameter (continent) 
	and have a population count above a given parameter (population) and sorts
	them ascending in regards to their population, returns a vector structure pointing to the sorted 
	input: repo - vector structure that holds all the country objects
			continent - string representing the continent each country must have
			population - int representing the minimum population each country must have
*/
vector* findCountryByContinent(vector repo, char* continent, int population)
{
	vector* vectorCountries;
	vectorCountries = (vector*)malloc(sizeof(vector));
	vectorCountries->length = (int*)malloc(sizeof(int));
	*vectorCountries->length = 0;
	vectorCountries->list = (Country**)malloc(100 * sizeof(Country*));
	Country* auxCountry = (Country*)malloc(sizeof(Country));
	for (int counter = 0; counter < *repo.length; counter++)
	{
		auxCountry = repo.list[counter];
		if (strcmp(auxCountry->continent, continent) == 0 && auxCountry->population >= population )
		{
			//vectorCountries->list[*vectorCountries->length] = (Country*)malloc(sizeof(Country*));
			vectorCountries->list[*vectorCountries->length] = auxCountry;
			(*vectorCountries->length)++;
		}
	}

	for (int counter1 = 0; counter1 < *vectorCountries->length; counter1++)
		for (int counter2 = counter1; counter2 < *vectorCountries->length; counter2++)
			if (vectorCountries->list[counter1]->population > vectorCountries->list[counter2]->population)
			{
				auxCountry = vectorCountries->list[counter1];
				vectorCountries->list[counter1] = vectorCountries->list[counter2];
				vectorCountries->list[counter2] = auxCountry;
			}
	
	return vectorCountries;
}


void CopyRepo(vector repo, vector undoRepo)
{
	for (int counter = 0; counter < *repo.length; counter++)
	{
		undoRepo.list[counter] = (Country*)malloc(sizeof(Country));
		strcpy_s(undoRepo.list[counter]->name, 30, repo.list[counter]->name);
		strcpy_s(undoRepo.list[counter]->continent, 30, repo.list[counter]->continent);
		undoRepo.list[counter]->population = repo.list[counter]->population;
		*undoRepo.length = *repo.length;
		*undoRepo.index = *repo.index;
	}
}