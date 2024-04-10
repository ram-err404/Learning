// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int maxPriceRodCutting(vector<int> &price, vector<int> &len, int &N) {
    int M=price.size();     // just for understanding, although price size and N will be same.
    vector<vector<int>> dp(M+1, vector<int> (N+1));

    for(int i=0; i<=M; i++) 
        dp[i][0] = 0;
    for(int j=1; j<=N; j++)
        dp[0][j] = 0;
    
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            if(len[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]],  dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[M][N];
}

int main() {
    vector<int> len{1,2,3,4,5,6,7,8};
    vector<int> price {1,5,8,9,10,17,17,20};
    int N=8;  //Size of the rod.

    cout<<"Max profit by cutting rod: "<< maxPriceRodCutting(price, len, N) <<endl;

    return 0;
}
