// Q6: Longest Palindromic Subsequence.
/*
s1="agbcba"		==> o/p --> "abcba"	==> Length = 5.

Explaination:
--> Since we have to find Longest Palindromic subsequece, we may have to find LCS. But to find
LCS we must need atleast 2 strings. So is other string hidden in input string???

--> Yes, another string is hidden in input string. What is reverse the input string.
--> Now after reversing input string, i.e. s2="abcbga".
--> Now try finding LCS of both the strings.
		LCS(s1, s2)	==> "abcba".

--> Now if you notice, this is the longest Palindromic subsequence.

--> So Longest Palindrommic Subsequence = LSC(s1, reverse(s1.begin(), s1.end()));
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(string &s1, string &s2, vector<vector<int> > &dp) {
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

string printLCS(string &s1, string &s2, vector<vector<int> > &dp) {
  string res;
	// Construct res based on this dp table.
  int i=s1.size(), j=s2.size();
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
  string s1 = "agbcba";
  string s2 = s1;
  reverse(s2.begin(), s2.end()); 
  
  vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1, 0));  // Initialised with 0.
  
  cout<<"Longest Palindromic subsequence: "<< printLCS(s1, s2, dp) << endl;
}
