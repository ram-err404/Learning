/* KMP Algorithm: */
#include <iostream>
#include <vector>

using namespace std;

void calculateLPS(string &pat, vector<int> &lps) {
  int n=pat.size();
  int len=0, i=1;

  while(i<n) {
    if(pat[i] == pat[len]) {
      lps[i] = ++len;
      i++;
    } else {
      if(len==0)  i++;
      else  len=lps[len-1];
    }
  }
}

int kmpSearch(string &s1, string &pat) {
	int m=s1.size();
  int n=pat.size();
  int i=0, j=0;

  //Longest proper Prefix Suffix array:
  vector<int> lps(n, 0);

  calculateLPS(pat, lps);

  while(i<m) {
    if(s1[i] == pat[j]) {
      i++; j++;
    } else {
      if(j==0)  i++;
      else  j=lps[j-1];
    }
    if(j==n)  return (i-j); // starting index of match.
  }
  return -1;  // No match found
}

int main() {
  string s1="onionionspls";
  string pat="onions";

  int index=-1;

  if((index=kmpSearch(s1, pat)) == -1) {
    cout<<"Pattern not found"<<endl;
  } else {
    cout<<"Pattern found at index: "<<index<<endl;
  }
  return 0;
}
