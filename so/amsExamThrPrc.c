#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<ctype.h>
#include<string.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

FILE *shell;
pthread_t threads[11];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int numberOfThreads, i;
char directory[256];
char letter;
int printed = 0;
void* letterThread(void* p);
void* threadfunc(void* p);

int main()
{
	printf("Give number: \n");
	scanf("%d", &numberOfThreads);
	printf("Give the directory: \n");
	scanf("%s", directory);
	pthread_create(&threads[0], NULL, letterThread, directory);
	printf("CREATING THREADS\n");
	for(i=0;i < numberOfThreads; i++)
		pthread_create(&threads[i+1],NULL,threadfunc,NULL);
	printf("JOINING THREADS\n");
	for(i=0;i< numberOfThreads; i++)
		pthread_join(threads[i],NULL);
	return 0;
}

void* letterThread(void* p)
{
	while(1)
	{
		printf("Changing Letter\n");
		srand(time(NULL));
		int someInt = rand()%24;
		letter = someInt + 'a';
		printf("Global letter is now %c\n", letter);
		printed = 0;
		sleep(2);
	}
	return NULL;
}

void* threadfunc(void* p)
{
	char command[200] = {0};
	char aux[1] = {0};
	aux[0] = letter;
	while(printed == 1)
		sleep(1);
	pthread_mutex_lock(&mutex);
	printed = 1;
	strcat(command, "ls ");
	strcat(command, directory);
	strcat(command," | grep ^");
	strcat(command, &letter);
	printf("%s\n", command);
	shell = popen(command, "r");
	pthread_mutex_unlock(&mutex);
	return NULL;
}




	}