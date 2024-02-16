// Minimum palindrome partitioning

#include<bits/stdc++.h>
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
    string str="anitiz";
    int n=str.size();
    
    vector<vector<int>>     dp(n, vector<int>(n));
    for (auto &i : dp)
    {
        fill(i.begin(), i.end(), -1); 
    }
    // fill(dp.begin(), dp.end(), -1);     // equivalent of memset for vectors.
    // memset(&dp[0], -1, sizeof(dp[0]) * dp.size());

    cout<<"Minimum number of partition for of all palindromic strings: "<< minPalindromePartition(str, 0, n-1, dp);
    return 0;
}