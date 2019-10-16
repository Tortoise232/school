#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main()
{
	int x=0,y=0;
	char a;
	while(1)
	{
		srand(time(NULL) + y);
		x = rand()%60+0;
		//sleep(0)
		srand(time(NULL) + x);
		y = rand()%40+0;
		//sleep(1);
		srand(time(NULL) +2);
		a = rand()%100+ 50;
		gotoxy(x,y);
		printf("HA");
		//sleep(1);
	}
}

			
