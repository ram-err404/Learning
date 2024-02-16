#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>
#include	<string.h>

#define		NUM_LOOPS	500000

pthread_mutex_t 	_mutex = PTHREAD_MUTEX_INITIALIZER;
long long	sum=0; 
void* counting_function(void *args);

int main()
{
	pthread_t 	tid1;
	int 		_offset1 = 1;
	pthread_t 	tid2;
	int 		_offset2 = -1;
	
	pthread_create(&tid1, NULL, counting_function, &_offset1);
	pthread_create(&tid2, NULL, counting_function, &_offset2);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("Sum: %lld \n", sum);
	return 0;
}

void* counting_function(void *args)
{
	int offset = *(int*) args;
	int i=0;
	for (i=0; i<NUM_LOOPS; i++) {
	/*Critical Section Start*/
	/*Since sum is a global variable its value may get changed by any Thread.
	 * This will bring race condition.
	 * To avoid race condition we need to take mutex lock. */
		pthread_mutex_lock(&_mutex);
		
		sum += offset;
		
		pthread_mutex_unlock(&_mutex);
	/*Critical Section End*/
	}
	pthread_exit(NULL);
}
