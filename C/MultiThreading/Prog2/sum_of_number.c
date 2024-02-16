#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>
#include	<string.h>

struct data_t 
{
	long 		input;
	long long	result;
};
long long res;
void* sum_runner(void*);

int main(int argc, char **vargs) 
{
	int 				i=0;
	void				*ret;
	struct data_t		value[argc-1];
	pthread_t			tid[argc-1];
	pthread_attr_t 		attr;

	if(argc < 3) {
		printf("%d Usage: ./sum_of_number <value> <value> ... <value>\n", argc);
		return 0;
	}
	printf("argc: %d \n", argc);
	for(i=0; i<argc-1; i++) {
		value[i].input = atol(vargs[i+1]);
		value[i].result = 0;
		pthread_attr_init(&attr);
		pthread_create(&tid[i], &attr, sum_runner, &value[i]);
	}
	for (i=0; i<argc-1; i++) {
		pthread_join(tid[i], &ret);
		printf("Thread:%d Sum=%lld \n", i, value[i].result);
	}
	return 0;
}
void* sum_runner(void *args) 
{
	long 				i;
	long long			sum 	= 0;
	struct data_t		*val 	= (struct data_t*)args;
	printf("val: %ld \n", val->input);
	for (i=0; i<val->input; i++) {
		sum += i;
	}
	((struct data_t*)args)->result = sum;
	pthread_exit(NULL);
}
