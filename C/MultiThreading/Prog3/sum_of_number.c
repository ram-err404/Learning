#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>

struct data_t 
{
	long 		input;
	long long	result;
};

void* sum_runner(void*);

int main(int argc, char **vargs) 
{
	int 				i=0;
	struct data_t		*ret;
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
		pthread_join(tid[i], (void*)&ret);
		printf("Thread:%d val:%ld Sum=%lld \n", i, 
				((struct data_t*)ret)->input, 
				((struct data_t*)ret)->result);
		free(ret);
	}
	return 0;
}
void* sum_runner(void *args) 
{
	long 				i;
	long long			sum 	= 0;
	struct data_t		*val 	= (struct data_t*)args;
/*Dynamic Memory allocation for pthread_exit*/
	struct data_t 		*res	= (struct data_t*)malloc(sizeof(struct data_t));
	for (i=0; i<val->input; i++) {
		sum += i;
	}
	res->input = val->input;
	res->result = sum;
	pthread_exit(res);
}
