#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define TOTAL_CHARACTERS  256
/* Method 1: */
#if 0
bool  anagram(char *str1, char *str2) {
  int count[TOTAL_CHARACTERS] = {0};
  int i=0;
  while( str1[i] && str2[i] ) {
    count[ str1[i] ]++;
    count[ str2[i] ]--;
    i++;
  }
  if( str1[i] || str2[i] )
    return false; // length of strings are not same.
  for(i=0; i<TOTAL_CHARACTERS; i++)
    if( count[i] != 0 )
      return false;
  return true;
}
#endif

bool  anagram_using_map(char *str1, char *str2) {
  unordered_map<char, int>   count;
  int                       i=0;
  while( str1[i] && str2[i] ) {
    count[ str1[i] ]++;
    count[ str2[i] ]--;
    i++;
  }
  if( str1[i] || str2[i] )
    return false; // length is not same.

  for( auto itr:count )
    if(itr.second != 0)
      return false;
  return true;
}

int main() {
  char    str1[] = "TRIANGLE";
  char    str2[] = "INTEGRAL";

  if( anagram_using_map(str1, str2) )
    cout<< str1 <<" and " << str2 <<" are anagram strings." << endl;
  else 
    cout<<"Not Anagram." << endl;
  return 0;
}
