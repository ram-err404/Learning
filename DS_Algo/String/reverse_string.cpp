/* Quest: Reverse a string. */

#include <iostream>
#include <string.h>
using namespace std;

void reverse_string_using_loop(char *str) {
  int str_size = strlen(str);
  char temp;
  for(int i=0; i<str_size/2; i++) {
    temp = str[i];
    str[i] = str[str_size-1-i];
    str[str_size-1-i] = temp;
  }
  cout<< str << endl;
}

void reverse_string_using_recurssion(char *str, int start, int end) {
  char temp;
  if(start >= end)
    return;
  temp = str[start];
  str[start] = str[end];
  str[end] = temp;
  reverse_string_using_recurssion(str, ++start, --end);  
}

int main() {
  char str[]  = "Ramji Misra";

  reverse_string_using_loop(str);
  reverse_string_using_recurssion(str, 0, strlen(str)-1);
  cout<< str << endl;
  return 0;
}
