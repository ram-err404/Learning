#include <stdio.h>

void f1() {
    printf("Hi There, I'm f1\n");
}

void f2() {
    printf("Hi There, I'm f2\n");
}

int main() {
  // f defines as an array of size 5, of pointers to functions that return 
  // pointers to functions that return void.
  void (*(*f[5]) () ) ();

  f[0] = (void*) &f1;
  f[1] = (void*) &f2;

  f[0]();
  f[1]();
  return 0;
}
