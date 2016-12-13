// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

void readValues(unsigned vector[])
/*
 reads values from keyboard until the value 0 is an input
 input: 
	vector - vector where the numbers are stored
 output:
	None	
*/
{	
	int vectorCounter = 0;
	scanf("%d", vector[vectorCounter]);
	while (vector[vectorCounter] != 0)
	{
		vectorCounter = vectorCounter + 1;
		scanf("%d", vector[vectorCounter]);
	}

}

int nrOfDigits(unsigned vector[])
{
/*
	identifies the number of 0 digits in the product of a sequence of positive numbers
    input:
		vector - list of positive numbers
	output:
		counterOfDigits - number of 0 digits in the product of the sequence

	product - product of all the positive numbers in the list
	vectorCounter - counter for iteration of the vector
*/	
	int product = 1;
	int counterOfDigits = 0;
	int vectorCounter = 0;
	scanf("%d", vector[vectorCounter]);
	while (vector[vectorCounter] != 0)
	{
		product = vectorCounter * product;
		vectorCounter = vectorCounter + 1;
		scanf("%d", vector[vectorCounter]);
	}

	while (product != 0)
	{	
		if ((product % 10) == 0)
			counterOfDigits = counterOfDigits + 1;
		product = product / 10;
		
	}
	return counterOfDigits;
}

bool prime(unsigned number)
{/*checks to see if number is prime
	input: number
	output: returns the truth value of the statement "number is prime"*/
	int counter = 2;
	for (counter; counter <= number / 2; counter++)
	{
		if ((number % counter) == 0)
		{
			return 0;
		}
	}
	return 1;
} 

void findSequence(int vector[], int result[])
{

}

int main()
{
    return 0;
}

