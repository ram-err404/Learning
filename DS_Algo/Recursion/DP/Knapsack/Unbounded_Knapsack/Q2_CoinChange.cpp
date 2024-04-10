/*
Find Number of ways we can have to get target sum with given set of coins.
*/

#include<bits/stdc++.h>
using namespace std;

int NumberOfWays(vector<int> &coin, int &target) {
    int n=coin.size();

    vector<vector<int>> dp(n+1, vector<int>(target+1));

    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    for(int j=1; j<=target; j++)
        dp[0][j]=0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=target; j++) {
            if(coin[i-1]<=j) {
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> coin{1,2,5,10};
    int target=15;

    cout<<"Total number of ways to get sum as "<< target << " from given set of coins: "<< NumberOfWays(coin, target) <<endl;
    return 0;
}