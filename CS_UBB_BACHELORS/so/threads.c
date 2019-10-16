#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

int _current;
int limit=0;
pthread_mutex_t mutx=PTHREAD_MUTEX_INITIALIZER;

void* function_f(void* arg){
    int id=*(int*)arg;
    int r;
    while(limit<25){
	if(_current==id){
	    r=id;		
	    srand(time(NULL));
	    while(r==_current){
			r=rand()%10;
	    }
	    pthread_mutex_lock(&mutx);
	    _current=r;
	    limit++;
	    printf("thread no %d increment to %d\n",id,limit);
	    pthread_mutex_unlock(&mutx);
	}	
    }
    pthread_exit(NULL);
}

int main() {
	int id[10],i,rc;
	srand(time(NULL));
	_current=rand()%10;
	pthread_t threads[10];
	for(i=0;i<10;i++){
		id[i]=i;
		rc=pthread_create(&(threads[i]),NULL,function_f,&id[i]);
		if(rc) {
			printf("error creating thread no %d",i);
			exit(1);
		}
	}
	for(i=0;i<10;i++){
		rc=pthread_join(threads[i],NULL);
		if(rc) {
			printf("error at join for the thread no %d",i);
			exit(1);
		}
	}
		

	return 0;
}