#include"domain.h"
#include"repo.h"
#include"controller.h"
#include<stdio.h>

/*Function prints all the options of the Application*/
void printOptions()
{
	printf("1.Add a country\n");
	printf("2.Remove a country\n");
	printf("3.Update a country\n");
	printf("4.Print all countries with a given name\n");
	printf("5.Update a country (migration)\n");
	printf("6.Sort all countries with a given Continent & a minimum population\n");
	printf("7.Undo\n");
	printf("8.Redo\n");
	printf("0.Exit\n");
}
/*Function asks for country input and adds a Country structure to the repository vector
	input: repo - vector for holding pointers to Country structures*/
void addCountryUI(vector repo)
{	
	Country* newCountry = (Country*)malloc(sizeof(Country));
	*newCountry = readCountry();
	if (strcmp(newCountry->name,"NULL") != 0)
	{
		if (findCountryByName(repo, newCountry->name))
		{
			printf("\nThis Country is already in the memory!\n");
			return 0; 
		}
		addCountryController(repo, newCountry);
	}
	

	
	
}

/*Function asks for string input, name of a Country structure to be removed from the vector repository
	input: repo - vector for holding pointers to Country structures
	output: int representing the succes of failuire of the removal (0 - failed)
*/
int removeCountryUI(vector repo)
{
	char name[30];
	if (*(repo.length) == 0)
	{
		printf("No elements to delete!\n");
		return 0;
	}
	printf("Input name of the country to be deleted: ");
	scanf_s("%s", name, 30);
	if (!findCountryByName(repo, name))
	{
		printf("No Country found with that name!\n");
		return 0;
	}
	removeCountryController(repo, name);
	return 1;
}

/*Function that asks for input and updates the continent/population of a Country structure
	input: repo - vector for holding pointers to Country structure*/
void updateCountryUI(vector repo)
{	
	char name[30];
	char continent[30];
	int population;
	printf("Input name of country: \n");
	scanf_s("%s", name, 30);
	printf("1.Replace continent\n");
	printf("2.Replace population\n");
	scanf_s("%d", &population);
	if (population == 1)
	{
		printf("Input new continent: \n");
		scanf_s("%s", continent, 30);
		if (!strstr("North_America South_America Asia Africa Australia Antarctica Europe", continent))
		{
			printf("Continent is not valid!");
			return 0;
		}
		if (updateCountryByContinent(repo, name, continent) == 0)
		{
			printf("Country does not exist!\n");
			return 0;
		}


	}
	if (population == 2)
	{	
		printf("Input new population: \n");
		scanf_s("%d", &population);
		if (population < 0)
		{
			printf("Invalid population!\n");
			return 0;
		}
		if (updateCountryByPopulation(repo, name, population) == 0)
		{
			return 0;
		}
	}
}

/*Function prints all Country structures in the vector repository
	input: repo - vector repository holding pointers to the Country structures 
*/
void printByName(vector repo)
{
	char name[30];
	printf("Insert name:");
	scanf_s("%s", name, 30);
	if(strcmp(name,"all") == 0)
		for (int counter = 0; counter < *repo.length; counter++)
			printf("%s %s %d\n", repo.list[counter]->name, repo.list[counter]->continent, repo.list[counter]->population);
	for (int counter = 0; counter < *repo.length; counter++)
		if (strstr(repo.list[counter]->name, name) != NULL && repo.list[counter]->population >= 0)
			printf("%s %s %d\n", repo.list[counter]->name, repo.list[counter]->continent, repo.list[counter]->population);		
	
}

/*Takes input and returns an ascending list of Countries that belong to an inputed continent and have a population of beyond a given number
*/
void printByPopulation(vector repo)
{
	vector* vectorOfCountries;
	char continent[30];
	int population;
	printf("Insert continent: ");
	scanf_s("%s", &continent, 30);
	printf("Insert minimum population: ");
	scanf_s("%d", &population);
	vectorOfCountries = findCountryByContinent(repo, continent, population);
	for (int counter = 0; counter < *vectorOfCountries->length; counter++)
		printf("%s %s %d\n", vectorOfCountries->list[counter]->name, vectorOfCountries->list[counter]->continent, vectorOfCountries->list[counter]->population);
}


/*Modifies 2 country structures, by increasing one of their population by an amount and decreasing the other one by the same amount
	input: repo - vector repository that holds pointers to all the Country structures*/
void migration(vector repo)
{
	char name1[30];
	char name2[30];
	int population;
	
	printf("\nInsert name of the country from where the migration starts: ");
	scanf_s("%s", name1, 30);
	
	printf("\nInsert name of the country where migration ends: ");
	scanf_s("%s", name2, 30);
	printf("\nInput number of migrating population: ");
	scanf_s("%d", &population);
	if (updateMigration(repo, name1, -population) == 0)
	{
		printf("Migration is not possible!\n");
		return 0;
	}

	updateMigration(repo, name2, population);

}

/*
Copies repository from repo vector structure to the undoRepo vector structure
input: repo - vector structure
		undoRepo - vector structure to hold data from repo
*/


/*Executes main loop and interprets options*/
int main()
{	
	int i = 1;
	vector* redoRepo = initRepo();
	vector* repo = initRepo();
	vector* undoRepo = initRepo();
	int redoSwitch = 0;
	char option = ' ';
	while (i > 0)
	{	
		
		printOptions();
		scanf_s("%s", &option, 2);
		if (option == '1')
		{
			CopyRepo(*repo, *undoRepo);
			addCountryUI(*repo);
			redoSwitch = 0;
		}
			
			
		if (option == '2')
		{
			CopyRepo(*repo, *undoRepo);
			removeCountryUI(*repo);
			redoSwitch = 0;
			
		}
			
		if (option == '3')
		{
			CopyRepo(*repo, *undoRepo);
			updateCountryUI(*repo);
			redoSwitch = 0;
		}
		if (option == '4')
			printByName(*repo);
		if (option == '5')
		{
			CopyRepo(*repo, *undoRepo);
			migration(*repo);
			redoSwitch = 0;
		}
		if (option == '6')
			printByPopulation(*repo);

		if (option == '7')
		{
			redoSwitch = 1;
			redoRepo = repo;
			repo = undoRepo;
			*repo->length = *undoRepo->length;

			undoRepo = initRepo();
		}

		if (option == '8' && redoSwitch == 1)
		{
			repo = redoRepo;
			redoSwitch = 0;
		}
		
		if (option == '0')
			return 0;
		printf("\n");

		//system("cls");
		//printf("%s \n", repo->list[0]->continent);
	}
}
