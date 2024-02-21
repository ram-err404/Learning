// Q5: Minimum number of insertion and deletion to convert string s1 to s2.
/*
s1="heap"   --> s2="pea"

Explaination:
--> We could see both s1 and s2 have "ea" as common (LCS). So we first convert s1 to LCS,
i.e. delete "h and p" from s1. Which means:
Total deletion = s1.size() - LCS(s1, s2).

--> Now we could see our string s1 would be "ea", i.e. LCS. So to make it s2, we have to insert
"p". Which means:
Total insertion = s2.size() - LCS(s1, s2);
*/

#include <iostream>
#include <vector>

using namespace std;

int LCS(string &s1, string &s2) {
  int m=s1.size();
  int n=s2.size();
  
  vector<vector<int> > dp(m+1, vector<int>(n+1, 0));  // Initialised with 0.
  
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

int main() {
  string s1 = "heap";
  string s2 = "pea";
  
  cout<<"Total deletion: " << s1.size() - LCS(s1, s2) << endl;
  cout<<"Total insertion: " << s2.size() - LCS(s1, s2) <<endl; 
}
