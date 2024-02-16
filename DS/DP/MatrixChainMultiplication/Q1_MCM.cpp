#include<bits/stdc++.h>
using namespace std;

int mcm_recursive(vector<int> arr, int i, int j) {
    if(i>=j)    return 0;
    int mn=INT_MAX;
    for(int k=i; k<j; k++) {
        int cost = mcm_recursive(arr, i, k) + 
                    mcm_recursive(arr, k+1, j) +
                    arr[i-1]*arr[k]*arr[j];

        if(cost<mn)
            mn=cost;
    }
    return mn;
}

vector<vector<int>> dp(5, vector<int>{-1,-1,-1,-1,-1});

int mcm_memoisation(vector<int> &arr, int i, int j) {
    if(dp[i][j] != -1)  return dp[i][j];

    if(i>=j) return 0;

    int mn=INT_MAX;
    for(int k=i; k<j; k++) {
        int cost = mcm_memoisation(arr, i, k) + mcm_memoisation(arr, k+1, j) +
                    arr[i-1]*arr[k]*arr[j];
        
        if(cost<mn)
            mn=cost;
    }
    dp[i][j]=mn;
    return mn;
}

int main() {
    vector<int> arr {40,20,30,10,30};

    cout<<"Minimum cost of Matrix chain multiplication (recursive): "<< mcm_recursive(arr, 1, arr.size()-1) <<endl;
    cout<<"Minimum cost of Matrix chain multiplication (memozise): "<< mcm_memoisation(arr, 1, arr.size()-1) <<endl;
    return 0;
} 