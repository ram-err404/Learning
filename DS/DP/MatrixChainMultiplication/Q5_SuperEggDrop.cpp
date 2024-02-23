// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Getting TLE int Leetcode.
/*
class Solution {
public:
  int solve(int k, int n, vector<vector<int>> &dp) {
    if(k==1)  return n;
    if(n==0 || n==1)  return n;
    
    if(dp[k][n] != -1)  return dp[k][n];
    int mn=INT_MAX;
    
    for(int i=1; i<=n; i++) {
      int temp = 1 + max(solve(k-1, i-1, dp), solve(k, n-i, dp));
      mn = min(mn, temp);
    }
    return dp[k][n]=mn;
  }
  
  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k+1, vector<int>(n+1));
    for(int i=0; i<=k; i++) {
      for(int j=0; j<=n; j++)
        dp[i][j] = -1;
    }
    
    return solve(k, n, dp);
  }
};
*/

class Solution {
public:
  int solve(int k,int n,vector<vector<int>>& dp){
    //check if is it last floor or first floor then return current floor number
    if(n==1 || n==0) return n;

    //check if is it our last egg then return current floor number
    if(k==1) return n;

    //check if wrost egg drop already present inside the dp then return that dp value
    if(dp[k][n]!=-1) return dp[k][n]; 

    //declare mn variable basically we are going to store current minimum no. of moves in current floor
    int mn=INT_MAX;

    //Here we are going to use binary search because linear approach will give you TLE
    int l=1,h=n;
    while(l<h){
      int mid=l+(h-l)/2;
      //recursively call function again if egg got break at the current floor 
      int brk=solve(k-1,mid-1,dp);

      //recursively call function again if egg is not break at current floor
      int noBrk=solve(k,n-mid,dp);

      //declare temp variable and store one plus max eigther of break egg or not break egg at current floor
      int temp=1+max(brk,noBrk);

      //if break moves is greater than no break moves value then our high value will be mid floor or current floor 
      if(brk>noBrk){
        h=mid;
      }
      else{
        //else low became mid or current floor plus one
        l=mid+1;
      }
      // At every floor check for min of temp or mn
      mn=min(temp,mn);
    }
    //return worst or min of current floor as well as store inside the dp for future check
    return dp[k][n]=mn;
  }
  int superEggDrop(int k, int n) {
    //declare 2d dp for memoization
    vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
    //return solve function
    return solve(k,n,dp);
  }
};

int main() {
  // int k=4, n=1000;
  int k=3, n=5;
  Solution ob;
  cout<< ob.superEggDrop(k, n)<<endl;
  return 0;
}
