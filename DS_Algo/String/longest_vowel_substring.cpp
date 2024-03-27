#include <iostream>
#include <string>
#include <fstream>

#define FILE_NAME   "vowel_substring.txt"

bool  is_vowel(char c) {
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

std::string   vowel_substring(std::string &str, int k) {
  int start=0, count=0, max_vowel=0;
  int l=0, r=0;
  while(str[r]) {
    if(is_vowel(str[r])) {
      count++;
    }
    if((r-l) >= k) {
      if(is_vowel(str[l]))
        count--;
      l++;
    }
    if(count > max_vowel) {
      max_vowel = count;
      if(0 != l)
        start=l+1;
    }
    r++;
  }
  if(max_vowel)
    return str.substr(start, k);
  return "";
}

int main() {
  std::ifstream  fin;
  fin.open(FILE_NAME, std::ios::in);
  int i=0;
  while(!fin.eof()) {
    std::string   input;
    fin >> input;
    if("" != input) {
      // int k = (rand()%input.size());
      int k[] = {6, 4, 3, 5};
      std::cout << "input string: " << input <<", k: " << k[i] <<":" << std::endl;
      std::cout << "output: " << vowel_substring(input, k[i]) << "\n" << std::endl;
      i++;
    }
  }
  fin.close();
  return 0;
}
