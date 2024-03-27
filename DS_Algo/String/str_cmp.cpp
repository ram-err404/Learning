#include <iostream>
using namespace std;

int str_cmp(char *str1, char *str2) {
  int i=0;
  while(str1[i] && str2[i]) {
    if(str1[i] != str2[i])
      return str1[i] - str2[i];
    i++;
  }
  if(str1[i] || str2[i])
    return -1;  // strings are of variable length
  return 0;     // strings are matching
}

int main() {
  char    str1[]  = "RAMJI MISRA1";
  char    str2[]  = "RAMJI MISRA9";
  int     ret_val = 0;
  if((ret_val = str_cmp(str1, str2)))
    cout<<"Strings are not matching. ret_val:" << ret_val << endl;
    // std::cout<<"Strings are not matching. ret_val:" << ret_val << std::endl;
  else
    cout<<"Strings are matching. ret_val:" << ret_val << endl;
    // std::cout<<"Strings are matching. ret_val:" << ret_val << std::endl;
  return 0;
}
