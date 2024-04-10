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

int minDelToMakePalindrome(string &s1) {
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  
  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
  
  return s1.size() - LCS(s1, s2, dp);
}

int main() {
  string s1="agbcba";
  
  cout<<"Minimum number of deletion to make Palindrome: "<< minDelToMakePalindrome(s1) << endl;
  return 0;
}
