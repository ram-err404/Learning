#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(string &s1, string &s2) {
  int m=s1.size();
  int n=s2.size();

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

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

bool sequencePatternMatching(string &s1, string &s2) {
  if(s1.size() == LCS(s1, s2))
    return true;
  else 
    return false;
}

int main() {
  string s1="axy";
  string s2="adxcpy";
 
  cout<<"Is sequence pattern matching: "<< sequencePatternMatching(s1, s2) << endl;
  return 0;
}
