#pragma once
#include"domain.h"
#include"repo.h"

void addCountryController(vector repo, Country* newCountry);
void removeCountryController(vector repo, char* name);
int updateMigration(vector repo, char* name, int newPopulation);
int updateCountryByContinent(vector repo, char* name, char* newContinent);
int updateCountryByPopulation(vector repo, char* name, int newPopulation);
