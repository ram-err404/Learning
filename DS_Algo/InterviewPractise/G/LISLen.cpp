/*
Write a function which, given an array of integers of size (N ~ 10^5),
returns the length of the longest subsequence where every next value is 1 bigger than the previous one. 
Subsequences might not be consecutive, but must be in the same order as the given array.
  
Sample Case
1 1 3 2 4 3 2 5 4 5 7

Output: 5       ==> [1,2,3,4,5]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int n;
    
    int solve(int index, int prevIndex, vector<int>& arr, vector<vector<int>>& dp) {
        if(index==n) {
            return 0;
        }
        if(dp[index][prevIndex+1]!=-1) {
            return dp[index][prevIndex+1];
        }
        
        int notTakeLen = solve(index+1, prevIndex, arr, dp);
        int takeLen=0;
        if(prevIndex==-1 || arr[index]-arr[prevIndex]==1) {
            takeLen = 1 + solve(index+1, index, arr, dp);
        }
        return dp[index][prevIndex+1] = max(takeLen, notTakeLen);
    }
    
public:
    int LISLen(vector<int>& arr) {
        n=arr.size();
        int prevIndex=-1;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solve(0, prevIndex, arr, dp);
    }
};

int main() {
    vector<int> arr {1,1,3,2,4,3,2,5,4,5,7};
    Solution ob;
    
    cout << ob.LISLen(arr) << endl;
    return 0;
}