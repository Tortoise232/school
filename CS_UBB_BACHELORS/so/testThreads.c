#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<ctype.h>
#include<string.h>
pthread_t threads[5];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int startingNum = 0;
int endingNum = 0;
int nrOfDigits;
int copyNr;
int checkVector[15];
void* threadfunc(void* p);
int main()
{
	scanf("%d",&startingNum);
	copyNr = startingNum;
	while(copyNr)
	{	
		nrOfDigits++;)
		copyNr/=10;
	}
	int i;
	for(i = 0; i < nrOfDigits; i++)
		checkVector[i] = 0;
	printf("Started making Threads\n");
	for(i = 0; i < 5; i ++)
		pthread_create(&threads[i], NULL, threadfunc, &startingNum);
	printf("Started joining threads\n");
	for(i = 0; i < 5; i++)
	{
		pthread_join(threads[i],NULL);
	}
	printf("Result: %d", endingNum);
	return 0;
}

void putdigit(int copyNr, int i)
{
	int actDigit,sum = 1, copyOfDigit = i;
	while(i)
	{
		copyNr /= 10;
		i--;
	}
	actDigit = copyNr%10;
	i = nrOfDiits - copyofDigit - 1;
	while(i)
	{
		sum*=10;
		i--;
	}
	sum*=actDigit;
	endingNum += sum;
	printf("Thread has placed the %d -th digit\n", copyOfDigit);
}

void* threadfunc(void* p)
{
	int number = *((int*)p);
	int check = 1,i;
	while(check != 0)
	{
		check = 0;
		for( i = 0; i < nrOfDigits; i++)
		if(checkVector[i] == 0)
		{
			pthread_mutex_lock(&mutex);
			check = 1;
			putDigit(number, i);
			checkVector[i] = 1;
			pthread_mutex_unlock(&mutex);
		}
	}
	return NULL;
}