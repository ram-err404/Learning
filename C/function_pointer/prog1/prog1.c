#include	<stdio.h>
#include	<string.h>

int myFunct(int , int);

int myFun1(int, int (*)(int, int) );

int main()
{
	int (*fp)(int, int) = myFunct;
	int ret_val = 0;

	ret_val = fp(5, 7);

	printf("%d %p \n", ret_val, fp);
  
  myFun1(20, fp);

	return 0;
}

int myFunct(int a, int b)
{
	printf("Inside myFunct\n");
	return a + b;
}

int myFun1(int a,
    int (*fp)(int, int) ) 
{
  printf("%d %p %d \n", a, fp, fp(3,6));
  return 0;
}
