#include<iostream>
#include<string>
using namespace std;

string longestPalindromeSubstr(string &str) {
  int n=str.size();

  int mx=2, start=0;
  bool dp[n+1][n+1]={0};

  for(int i=0; i<=n; i++) 
    dp[i][i]=true;
  
  for(int i=0; i<n-1; i++) {
    if(str[i] == str[i+1]) {
      dp[i][i+1] = true;
      start=i;
      mx=2;
    }
  }

  for(int i=3; i<=n; i++) {
    for(int j=0; j<=n-i; j++) {
      int k=i+j-1;

      if(dp[j+1][k-1] && str[j]==str[k]) {
        dp[j][k] = true;

        if(i>mx) {
          mx=i;
          start=j;
        }
      }
    }
  }

  return str.substr(start, mx);
}

int main() {
  string str="bababad";

  cout<<"Longest substring: "<< longestPalindromeSubstr(str) <<endl;
  return 0;
}