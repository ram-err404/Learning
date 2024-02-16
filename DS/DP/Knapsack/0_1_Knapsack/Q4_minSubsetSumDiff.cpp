#include <iostream>
#include <vector>
// #include<bits/stdc++.h>
//using namespace std;

int minSubsetSumDiff(std::vector<int> &arr) {
  int n=arr.size();
  int sum=0;

  for(int i=0; i<n; i++)
    sum += arr[i];

  std::vector< std::vector<bool> > dp(n+1, std::vector<bool> (sum+1));

  // Initialise
  for(int i=0; i<=n; i++)
    dp[i][0]=true;
  for(int j=1; j<=sum; j++)
    dp[0][j] = false;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=sum; j++) {
      // if i'th element is included.
      if(arr[i-1] <= j) {
        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
      } else {
        // if i'th element is excluded.
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  //find Minimum now.
  int diff=INT_MAX;
  for(int j=sum/2; j>=0; j--) {
    if(dp[n][j] == true) {
      diff = sum-j*2;
      break;
    }
  }
  return diff;
}

int main() {
  // std::vector<int> arr{ 6,1,11,5 };
  std::vector<int> arr{ 6,1,11,5 };

  std::cout<<"Minimum subset sum differece: "<< minSubsetSumDiff(arr) << std::endl;
  return 0;
}
