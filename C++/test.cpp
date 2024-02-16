#include <iostream>
#include <string.h>
struct Fraction
{
  int numer;
  int denom;
  operator double() const { return numer * 1.0 / denom; }
};

int main()
{
  Fraction f;
  f.numer = 1;
  f.denom = 3;

  int *int_ptr = new int(10);
  int *int_ptr1 = (int*) malloc(sizeof(int));
  *int_ptr1 = 20;
  
  printf("%d %d :", *int_ptr, *int_ptr1);

  delete int_ptr1;
  free(int_ptr);
  // char *str;
  // strcpy(str, "Hello world");	/*Segmentation fault.*/
  
  std::cout << f << std::endl;
}
