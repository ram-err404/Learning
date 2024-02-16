#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *myRun1();
void *myRun2();

int main() {
	pthread_t tid1, tid2;
	
	pthread_create(&tid1, NULL, myRun1, NULL);
	pthread_create(&tid2, NULL, myRun2, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}

void *myRun1() {
	int i=0;
	for (i=0; i<10; i++)
	{	
		printf("Thread 1\n");
		usleep(1000000);
	}
	pthread_exit(0);
}

void *myRun2() {
	int i=0;
	for (i=0; i<10; i++)
	{
			printf("Thread 2\n");
			usleep(1000000);
	}
	pthread_exit(0);
}
