// https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void subset(int idx, vector<int>& nums, vector<int>& ans, vector<vector<int>>& res) {
        int n=nums.size();
        res.push_back(ans);

        for(int i=idx; i<n; i++) {
            if(i!=idx && nums[i-1]==nums[i])    continue;

            ans.push_back(nums[i]);
            subset(i+1, nums, ans, res);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(nums.begin(), nums.end());

        subset(0, nums, ans, res);
        return res;
    }
};

void printSubsets(vector<vector<int>>& subsets) {
    cout<<"[";
    for(auto vec : subsets) {
        cout<<"[";
        for(int x:vec)
            cout<< x <<",";
        cout<<"]";
    }
    cout<<"]"<< endl;
}

int main() {
    // vector<int> nums {1,2,3,2,3,4,7};
    vector<int> nums {1,2,2};
    Solution ob;

    vector<vector<int>> subsets = ob.subsetsWithDup(nums);
    printSubsets(subsets);
    return 0;
}