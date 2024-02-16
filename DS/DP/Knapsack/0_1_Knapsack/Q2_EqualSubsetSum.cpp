#include<bits/stdc++.h>
using namespace std;

bool equalSumSubsetPresent(vector<int> &arr) {
    int n=arr.size();
    int sum=0;
    
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    if(sum%2 != 0)  return false;
    
    sum=sum/2;
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1));
    
    // Initialise
    for(int i=0; i<=n; i++)
        dp[i][0]=true;
    for(int i=1; i<=sum; i++)
        dp[0][i]=false;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) 
                dp[i][j] = dp[i][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    // vector<int> arr{2,3,7,8,10};
    vector<int> arr{1,5,11,5};
    
    cout<<"Equal Sum Subset present: "<<equalSumSubsetPresent(arr)<<endl;
    return 0;
}