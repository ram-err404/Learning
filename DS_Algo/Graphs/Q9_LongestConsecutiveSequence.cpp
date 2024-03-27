// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define max(a, b) a>b?a:b

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int n=nums.size();
        int startIdx=0;
        int mxCount=INT_MIN, count=0;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        while(startIdx < n) {
            count=0;
            if(st.find(nums[startIdx]-1) == st.end()) {
                int startVal = nums[startIdx];
                count++;

                while(st.find(++startVal) != st.end()) {
                    count++;
                }
            }
            mxCount = max(mxCount, count);
            startIdx++;
        }
        return mxCount;
    }
};

int main() {
    vector<int> nums {100,4,200,1,3,2};
    Solution ob;

    cout<<"Length of the Longest Consecutive Sequence: "<<ob.longestConsecutive(nums)<<endl;
    return 0;
}