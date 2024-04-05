#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarrayOfSumK(vector<int>& arr, int targetSum) {
        int mx=0;
        int i=0, j=0;
        int sum=0;

        while(j<arr.size()) {
            sum += arr[j];
            if(sum > targetSum && i<j) {
                sum -= arr[i];
                i++;
            } 
            if(sum == targetSum) {
                mx = max(mx, j-i+1);
            }
            j++;
        }
        return mx;
    }
};

int main() {
    vector<int> arr {1,3,2,5,8,1,1,1,1,1,3,2};

    Solution ob;
    int res = ob.longestSubarrayOfSumK(arr, 8);

    cout<<"Longest window for sum=8 is: "<< res <<endl;

    return 0;
}