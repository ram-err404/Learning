#include<iostream>
#include<vector>

using namespace std;

string printLCS(string &s1, string &s2) {
  int m=s1.size();
  int n=s2.size();
  string res;
  
  vector<vector<int> > dp(m+1, vector<int>(n+1));
  // Initialise dp matrix.
  for(int i=0; i<=m; i++)   dp[i][0] = 0;
  for(int j=0; j<=n; j++)   dp[0][j] = 0;
  
  // Fill the dp matrix.
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  
  // Construct res based on this dp table.
  int i=m, j=n;
  while(i>=0 || j>=0) {
    if(s1[i-1] == s2[j-1]) {
      res.push_back(s1[i-1]);
      i--; j--;
    } else {
      if(dp[i-1][j] > dp[i][j-1]) {
        i--;
      } else {
        j--;
      }
    }
  }
  return res;
}

int main() {
  string s1="abcdgh";
  string s2="abedfh";
  
  cout << printLCS(s1, s2) << endl;
  return 0;
}
