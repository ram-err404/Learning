// Q4: shortest superset.
// superset is a set that contains both set s1 and set s2.

#include <iostream>
#include <vector>

using namespace std;

int LCS(string &s1, string &s2) {
  int m=s1.size();
  int n=s2.size();

  // Declare a dp matrix and init it with 0.
  // base cond is if(m==0 || n==0) return 0;
  vector<vector<int> > dp(m+1, vector<int>(n+1, 0) );

  // Fill dp now.
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

int shortestSuperset(string &s1, string &s2) {
  /*
  shortestSuperset = s1.size() + s2.size() - LCS(s1, s2);
  */
  return (s1.size() + s2.size() - LCS(s1, s2));
}

int main() {
  string s1="geek";
  string s2="eke";

  cout<<"Length of shortest superset: "<< shortestSuperset(s1, s2);
  return 0;
}
