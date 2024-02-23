// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mcm_recursive(vector<int> arr, int i, int j) {
  if(i>=j)    return 0;
  int mn=INT_MAX;
/*
  --> To select k, --> we need to divide the array till j, and solve every part to get ans.
  arr[0 , 1, 2, 3, 4]
          i=1,  --> if we start k from i, will it form valid matices?? i.e. k=i=1; --> Initially
  --> we will solve: (i --> k) && (k+1 --> j)
  (i-->k)  ==> Ai = arr[i-1] X arr[i] ==> i=1, A1 = arr[0] X arr[1]
               Ak = arr[k-1] X arr[k] ==> k=1, A1 = arr[0] X arr[1]  ==> valid.
  
  (k+1-->j) ==> A[k+1] = arr[k+1-1] X arr[k+1]  ==> k=(j-1)=3, A4 = arr[3] X arr[4] ==>valid
                                              ==> k=j=4, A5 = arr[4] X arr[5]   ==> invalid
  ==> k should start from i and should go to j-1.
*/
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
/*
  Explaination: All the matrices made from above arr are of dimensions:
  --> i strats from 1 index, so matrices are formed like: A1 = arr[i-1] X arr[i].
  A1 = []40X20
  A2 = []20X30
  A3 = []30X10
  A4 = []10X30
  
  So we have to multiply all the matrices and find the Minimum cost (i.e. # of Multiplication).
  
  ans = A1 * A2 * A3 * A4   ==> in such a order that cost should be minimum.
  
  (A1) * (A2 * A3 * A4)  or 
  (A1 * A2) * (A3 * A4)  or 
  (A1 * A2 * A3) * (A4) ==> min cost.
*/

  cout<<"Minimum cost of Matrix chain multiplication (recursive): "<< mcm_recursive(arr, 1, arr.size()-1) <<endl;
  cout<<"Minimum cost of Matrix chain multiplication (memozise): "<< mcm_memoisation(arr, 1, arr.size()-1) <<endl;
  return 0;
} 
