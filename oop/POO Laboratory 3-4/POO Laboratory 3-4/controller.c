#include "domain.h"
#include "repo.h"

/*Adds a country at the location (in the vector) indicated by the index
input: repo - vector structure, meant to hold country data
newCountry - country structure, to be added to the vector
output: pointer to vector structure
*/
void addCountryController(vector repo, Country* newCountry)
{
	addCountry(repo, newCountry);
}

/*Remove a country identical to the one given as input from the vector of structures
input: repo - vector structure, meant to hold country data
countryToDelete - country structure, to be deleted from structure
*/

void removeCountryController(vector repo, char* name)
{
	Country* countryToDelete = findCountryByName(repo, name);
	removeCountry(repo, countryToDelete);
}

/*Updates a country, by changing it's continent  with the one given
input: repo - vector structure, repository for the Country structures
		name - string representing name of the Country structure to be updated
		newContinent - string representing updated continent of the Country structure
*/
void updateCountryByContinent(vector repo, char* name, char* newContinent)
{
	Country* updatedCountry = findCountryByName(repo, name);
	if (updatedCountry == 0)
		return 0;
	strcpy_s(updatedCountry->continent, 30, newContinent);
	updateCountry(repo, updatedCountry);
}

/*Updates a country, by changing it's continent  with the one given
input: repo - vector structure, repository for the Country structures
		name - string representing name of the Country structure to be updated
		newPopulation - int representing updated population of the Country structure 
*/
void updateCountryByPopulation(vector repo, char* name, int newPopulation)
{
	
	
	Country* updatedCountry = findCountryByName(repo, name);
	if (updatedCountry == 0)
	{
		return 0;
		
	}
	updatedCountry->population = newPopulation;
	updateCountry(repo, updatedCountry);
}

/*Updates a country by changing its population acording to the migration of population
	input: repo - vector structure, repository for the Country structures
		name - string representing name of the Country structure to be updated
		newPopulation - int representing updated population of the Country structure 
*/
void updateMigration(vector repo, char* name, int newPopulation)
{


	Country* updatedCountry = findCountryByName(repo, name);
	if (updatedCountry == 0)
		return 0;
	updatedCountry->population += newPopulation;
	if (updatedCountry->population < 0)
	{
		updatedCountry->population -= newPopulation;
		printf("Invalid population!\n");
		return 0;
		
	}
	updateCountry(repo, updatedCountry);
	return 1;
}

