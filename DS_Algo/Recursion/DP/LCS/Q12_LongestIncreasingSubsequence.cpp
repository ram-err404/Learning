// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    void removeDuplicates(vector<int>& arr) {
        unordered_set<int> st;
        for(int x:arr)
            st.insert(x);
        
        arr.assign(st.begin(), st.end());
    }
    
    int LCS(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(arr1[i-1] == arr2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortedNums = nums;
        
        sort(sortedNums.begin(), sortedNums.end());
        removeDuplicates(sortedNums);
        
        return LCS(nums, sortedNums);
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {7,7,7,7,7,7};
    Solution ob;
    
    cout<<"Length of LIS: "<< ob.lengthOfLIS(nums) <<endl;
    return 0;
}