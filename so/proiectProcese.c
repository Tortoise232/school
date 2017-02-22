#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
FILE *shell;
int pipe01[1];
int pipe12[1];
char actualString[200];
int main (int argc, char *argv[])
{
	pipe(pipe01);
	pipe(pipe12);
	int counter = 0;
	char nrOfVowels[4];
	strcpy(nrOfVowels,"");
	char a[200];
	char b[200];
	for( counter = 1; counter < argc; counter++)
	{
		strcpy(a, argv[counter]);
		if( fork() == 0)
		{
			if(fork() == 0)
			{	
				strcpy(b,"");
				strcat(b,"echo ");
				strcat(b,a);
				strcat(b, " | sed 's/[^aeiouAEIOU//g' | awk '{print length ($0)}'");
				shell = popen(b,"r");
				fscan(shell,"%s",nrOfVowels);
				close(pipe12[0]);
				printf("Child received %s and writes: ", a);
				write(pipe12[1], nrOfVowels, 4);
				write(pipe12[1], actualString, 200);
				close(pipe12[1]);
				exit(0);
			}
			else
			{
				wait(NULL);
				close(pipe12[1]);
				read(pipe12[0], nrOfVowels, 4);
				read(pipe12[0], actualString, 200);
				close(pipe01[0]);
				write(pipe01[1], nrOfVowels, 4);
				write(pipe01[1], actualString, 200);
				close(pipe01[1]);
			}
			close(pipe01[1]);
			read(pipe01[0], nrOfVowels, 4);
			read(pipe01[0], actualString, 200);
			close(pipe01[0]);
			printf("%s %s\n", nrOfVowels, actualString);
			exit(0);
			}
		}

return 0;
}
			