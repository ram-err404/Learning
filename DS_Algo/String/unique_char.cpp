#include <iostream>
#include <unordered_map>
using namespace std;

bool unique_char(char *str) {
  unordered_map<char, int>    count;
  int                         i=0;
  
  while( str[i] ) {
    count[ str[i] ]++;
    if( count[ str[i] ] > 1)
      return false;
    i++;
  }
  return true;
}

int main() {
  char  str[] = "AEIOUWRqbt";

  if( unique_char(str) )
    cout<<"Yes string has unique chars." << endl;
  else
    cout<<"No string does not have unique chars." << endl;
  return 0;
}
