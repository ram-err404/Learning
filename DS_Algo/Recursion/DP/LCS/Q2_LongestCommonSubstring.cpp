#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

int longestCommonSubstringRecursion(string &s1, string &s2, int m, int n, int res) {
  if(m==0 || n==0)  return res;

  if(s1[m-1] == s2[n-1]) {
    // Increase res by 1
    return longestCommonSubstringRecursion(s1, s2, m-1, n-1, res+1);
  } else {
    // When it is not matching, reset the res=0 in function call.
    return max(res, max(longestCommonSubstringRecursion(s1, s2, m, n-1, 0), 
                          longestCommonSubstringRecursion(s1, s2, m-1, n, 0) ));
  }
}

int longestCommonSubstring(string &s1, string &s2) {
    int m=s1.size(), n=s2.size();
    int dp[m+1][n+1];
    int max_length=0;

    for(int i=0; i<=m; i++)
        dp[i][0]=0;
    for(int j=0; j<=n; j++)
        dp[0][j]=0;
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > max_length)
                    max_length = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return max_length;
}

int main() {
    // string a="abcde";
    // string b="abfce";
    string a="LABFQDBYZAB";
    string b="LACFDBXYZABCDEF";

    cout<<"Length of Longest Commong Substring: "<< longestCommonSubstring(a, b) <<endl;
    cout<<"Length of Longest Commong Substring Using Recursion: "<< longestCommonSubstringRecursion(a, b, a.size(), b.size(), 0) <<endl;
    return 0;
}
