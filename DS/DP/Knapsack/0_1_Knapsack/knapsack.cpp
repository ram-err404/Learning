// Knapsack max profit.
// youtuber: Aditya Verma.  (Best explaination).


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int knapsack_memoization(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp) {
    if(n==0 || W==0)    return 0;
    if(dp[n][W] != -1)  return dp[n][W];
    
    if(wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + knapsack_memoization(wt, val, W-wt[n-1], n-1, dp), knapsack_memoization(wt, val, W, n-1, dp));
    else if(wt[n-1] > W)
        return dp[n][W] = knapsack_memoization(wt, val, W, n-1, dp);
}

int knapsack_tabulation(vector<int> &wt, vector<int> &val, int W) {
    int n=wt.size();
    vector<vector<int>> dp(n+1, vector<int> (W+1));
    
    // Step1: Initialise the dp marix based on our base condition.
    for(int i=0; i<=n; i++)
        dp[i][0]=0;
    for(int i=0; i<=W; i++)
        dp[0][i]=0;
    
    //step2: change recursive calls to iterative calls.
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else if(wt[i-1] > j) {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> wt{1,3,4,5};
    vector<int> val{1,4,5,7};
    int W=10;    // knapsack capacity.
    
    int n=wt.size();
    
    vector<vector<int>> dp(n+1, vector<int> (W+1));
    // memset the vector.
    for(int i=0; i<=n; i++)
        for(int j=0; j<=W; j++)
            dp[i][j]=-1;
    
    cout<<"Memoization: Max profit would be: "<< knapsack_memoization(wt, val, W, n, dp) << endl;
    cout<<"TopDown: Max profit would be: "<< knapsack_tabulation(wt, val, W) << endl;
    
    return 0;
}