/* 
    Leetcode: https://leetcode.com/problems/3sum-closest/
    16. 3Sum Closest
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min=INT_MAX, sum=0, d=0, closestSum;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                sum=nums[i]+nums[l]+nums[r];
                d=abs(target-sum);
                if(d<min) {
                    min=d;
                    closestSum=sum;
                }
                if(sum<target)  l++;
                else    r--;
            }
        }
        return closestSum;
    }
};