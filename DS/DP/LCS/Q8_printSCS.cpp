#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(string &s1, string &s2, vector<vector<int>> &dp) {
  int m=s1.size();
  int n=s2.size();
  
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}

string printSCS(string &s1, string &s2, vector<vector<int>> &dp) {
  
  LCS(s1, s2, dp);
  // Now since dp table is filled we can print SCS.
  /* To print SCS, print all the occurences of both s1 & s2, but print LCS values only once.
      If any of the string is over print the other remianing string. */
  int i=s1.size(), j=s2.size();
  string res;
  
  while(i>=0 || j>=0) {
    if(s1[i-1] == s2[j-1]) {
      res.push_back(s1[i-1]);
      i--; j--;
    } else {
      if(dp[i-1][j] > dp[i][j-1]) {
        res.push_back(s1[i-1]);
        i--;
      } else {
        res.push_back(s2[j-1]);
        j--;
      }
    }
  }
  
  // Now check if any of the string is 0, then add the remaining other string to res.
  if(i==0) {
    while(j>0) {
      res.push_back(s2[j-1]);
      j--;
    }
  } else {
    while(i>0) {
      res.push_back(s1[i-1]);
      i--;
    }
  }
  
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  string s1="acbcf";
  string s2="abcdaf";
  
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
  
  cout<<"Shortest common Supersequence: "<< printSCS(s1, s2, dp) << endl;
  return 0;
}
