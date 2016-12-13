#pragma once
typedef struct {
	Country** list;
	int* length;
	int* index;
}vector;

vector* initRepo();
void addCountry(vector repo, Country* newCountry);
void removeCountry(vector repo,Country* countryToDelete);
int updateCountry(vector repo, Country* updatedCountry);
Country* findCountryByName(vector repo, char* name);
vector* findCountryByContinent(vector repo, char* continent, int population);
void CopyRepo(vector repo, vector undoRepo);