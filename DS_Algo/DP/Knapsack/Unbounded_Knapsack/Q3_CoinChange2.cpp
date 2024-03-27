#include<bits/stdc++.h>
using namespace std;

int minNumberOfCoins(const vector<int> &coins, const int &sum) {
    int n=coins.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1));

    // Here we will initialise first 2 rows and 1st col.
    for(int j=0; j<=sum; j++) {
        dp[0][j]=INT_MAX-1;
        if(j%coins[0]==0) {
            dp[1][j] = j/coins[0];
        } else {
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=1; i<=n; i++) 
        dp[i][0]=0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(coins[i-1] <= j) {
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> coins{1,2,5,10};
    int sum=17;

    cout<<"Minimum number of coins used: "<< minNumberOfCoins(coins, sum) << endl;
    return 0;
}
