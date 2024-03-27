#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int>  duplicate(const char *str) {
  unordered_map<char, int>  count, dup;
  int                       i=0;
  while( str[i] ) {
    count[str[i]]++;
    if( count[str[i]] > 1 )
      dup[str[i]] = count[str[i]];
    i++;
  }
  return dup;
}

int main() {
  char  str[] = "qwertyuioplkj qwerty";
  char  flag  = 0;

  unordered_map<char, int> dup = duplicate(str);
  for(auto itr: dup) {
    cout<< itr.first <<" : " << itr.second <<" times" << endl;
    flag=1;
  }
  if(!flag)
    cout<<"No duplicate characters are present." << endl;
  return 0;
}
