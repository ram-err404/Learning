// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define min(a, b, c)    (c<(a<b?a:b)?c:(a<b?a:b))

int makeStringEqual(string &s1, string &s2) {
    int m=s1.size();
    int n=s2.size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    for(int i=0; i<=m; i++)
        dp[i][0]=i;
    for(int j=0; j<=n; j++)
        dp[0][j]=j;
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j]= 1 + min( dp[i][j-1], dp[i-1][j], dp[i-1][j-1] );
        }
    }
    return dp[m][n];
}

int main() {
    string str1="AABCDE";
    string str2="ABCDF";
    
    cout<<"Minimum moves to make string equal: "<< makeStringEqual(str1, str2);
    return 0;
}
