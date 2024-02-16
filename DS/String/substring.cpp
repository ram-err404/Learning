#include <iostream>
#include <vector>

std::vector<int> substr_present(char *str, char *substr) {
  int i=0, j=0;
  std::vector<int>   res;

  while(str[i]) {
    if(str[i] == substr[j])
      j++;
    else
      j=0;
    i++;
    if(substr[j] == '\0')
      res.push_back(i-j);
  }
  return res;
}

int main() {
  char  str[]     = "AABAACAADAABAABA";
  char  substr[]  = "AABA";

  std::vector<int> res = substr_present(str, substr);
  for(auto itr:res)
    std::cout<<"String found at index: " << itr << std::endl;

  return 0;
}
