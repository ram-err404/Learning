/* Compile code without optimization option */
#include <stdio.h> 
int main(void) 
{
	const int local = 10; 
	int *ptr = (int*) &local;
  int *array[5];
  int i=0, j=0; 
  
  array[3] = ptr;
  
  for(i=0; i<1; i++) {
    for(j=0; j<5; j++) {
      printf("%d ", array[i][j]);
    }
  }
	printf("Initial value of local : %d \n", local); 

	*ptr = 100; 
	printf("Modified value of local: %d \n", local);

  const int val1 = 5;
  const int *ptr1= &val1;
  int val2 = 6;
  ptr1= &val2;
  // const pointers
  // int *const ptr2 = &val1;  //error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
  int *const ptr2 = &val2;  //ok.
  //ptr2 = &val2;      // error.
  /**************************************************************/
  // references.
  int &ref1 = val2;
  int val3 = 10;
  ref1 = val3;      //no error, but references cannot be reassigned. No effect of this line to ref.
  ref1 = 8;         // Ok. val2 will changed to 8.
  printf("\nref: [%d], val3: [%d] \n", ref1, val3);
	return 0; 
} 

