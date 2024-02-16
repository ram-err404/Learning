// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int countSubsetSumDiff(vector<int> &arr, int &diff) {
    int sum=0;
    int n=arr.size();
    
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    int s1sum=(diff+sum)/2;
    // int dp[n+1][s1sum+1]={0};
    vector< vector<int> > dp(n+1, vector<int> (s1sum+1, 0));  // declare and initialize with 0.
    
    // Initialise
    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    for(int j=1; j<=s1sum; j++)
        dp[0][j]=0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=s1sum; j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][s1sum];
}

int main() {
    std::vector<int> arr{1,1,2,3};
    int diff=1;
    
    cout<<"The count of number of subsets of given diff: "<< countSubsetSumDiff(arr, diff)<<endl;
    return 0;
}
