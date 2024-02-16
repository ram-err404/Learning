/* Write a multi thread program to calculate sum of nth numbers passed at command line arguments.
 * Sum should must be received in pthrad_join method. */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef enum {
  SUCCESS = 0,
  FAILURE
}return_t;

typedef struct {
  int val;
  long sum;
}data_t;

void sum(void *val);

int main(int argc, char *args[])      /* ./binary <val1> <val2> <val3> <val> ... <valn>*/
{
  void      *ret;
  data_t    *ret_val = NULL;
  int       i, value;
  pthread_t tid[argc - 1];
  void      (*fp) = &sum;
  
  if (argc < 2) {
    printf("Usage: ./binary <val1> <val2> <val3> <val> ... <valn>");
    return FAILURE;
  }


  for ( i=0; i<argc-1; i++) {
    value = atoi(args[i]);
    pthread_create(&tid[i], NULL, fp, &value);
    pthread_join(tid[i], &ret);
    //ret_val = (data_t*)ret;
    printf("Thread_id: [%d], Value: [%d], Result: [%ld]\n", i, ((data_t*)ret)->val, ((data_t*)ret)->sum );
    free(ret);
  }

  /*for ( i=0; i<argc-1; i++) {
    //pthread_mutex_lock(&_mutex);
    pthread_join(tid[i], &ret);
    //ret_val = (data_t*)ret;
    printf("Thread_id: [%d], Value: [%d], Result: [%ld]\n", i, ((data_t*)ret)->val, ((data_t*)ret)->sum );
    free(ret);
    //pthread_mutex_unlock(&_mutex);
  }*/
  return SUCCESS;
}

void sum(void *v) {
  int i = 0;
  int sum=0;
  //pthread_mutex_t   _mutex = PTHREAD_MUTEX_INITIALIZER;
  
  //pthread_mutex_lock(&_mutex);
  data_t *value = (data_t*) malloc( sizeof(data_t) );
  value->val = *(int*)v;
  value->sum = 0;
  //pthread_mutex_unlock(&_mutex);
  
  for ( i=0; i<*(int*)v ; i++) {
    //pthread_mutex_lock(&_mutex);
    sum += i;
    //pthread_mutex_unlock(&_mutex);
  }
  value->sum += sum;
  pthread_exit( value );
}
