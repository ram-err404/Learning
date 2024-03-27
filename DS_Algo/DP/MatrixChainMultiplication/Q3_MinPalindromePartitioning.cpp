// Minimum palindrome partitioning

// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isPalindrome(string &str, int i, int j) {
  while(i<j) {
    if(str[i] != str[j])
      return false;
    i++; j--;
  }
  return true;
}

int minPalindromePartition(string &str, int i, int j, vector<vector<int>> &dp) {
  if(i>=j) return 0;
  if(dp[i][j] != -1)  return dp[i][j];
  if(isPalindrome(str, i, j))     return 0;

  int mn=INT_MAX;
  for(int k=i; k<j; k++) {
    int cost = 1 + minPalindromePartition(str, i, k, dp) + minPalindromePartition(str, k+1, j, dp);
    if(cost<mn)
      mn=cost;
  }
  return dp[i][j]=mn;
}

int main() {
  //string s1="abcnitindef";  // ==> O/p is doubtful. It should be 3 but getting 6 here.
  //string s1="anitiz";     // ==> O/p is doubtful. It should be 2 but getting 3 here.
  string s1="anitinz";    // ==> Here output is coming correct as 2.

  int n=s1.size();

  vector<vector<int>>     dp(n, vector<int>(n, -1));

  cout<<"Minimum number of partition for of all palindromic strings: "<< minPalindromePartition(s1, 0, n-1, dp);
  return 0;
}
