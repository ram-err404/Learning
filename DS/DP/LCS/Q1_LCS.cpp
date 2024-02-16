// Longest Common Subsequence.


#include<bits/stdc++.h>
using namespace std;

int LCS_recursion(string &X, string &Y, int n, int m) {
    if(n==0 || m==0) 
        return 0;
    
    if(X[n-1] == Y[m-1])
        return 1 + LCS_recursion(X,Y,n-1,m-1);
    else
        return max(LCS_recursion(X,Y,n,m-1), LCS_recursion(X,Y,n-1,m));
}

int LCS_tabulation(string &X, string &Y) {
    int n=X.size();
    int m=Y.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1));

    for(int i=0; i<=n; i++)
        dp[i][0]=0;
    for(int j=0; j<=m; j++)
        dp[0][j]=0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main() {
    string X="abcdgh";
    string Y="abedfhr";

    cout<<"LCS recursion: "<< LCS_recursion(X, Y, X.size(), Y.size()) <<endl;
    cout<<"LCS Tabulation: "<< LCS_tabulation(X, Y) <<endl;
    return 0;
}