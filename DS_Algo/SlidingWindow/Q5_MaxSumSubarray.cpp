#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumSubAarayOfSizeK(vector<int>& arr, int k) {
        int mx=INT_MIN;
        int i=0, j=0;
        int n=arr.size();
        int sum=0;

        while(j<n) {
            sum += arr[j];
            if(j-i+1 == k) {
                mx = max(mx, sum);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};

int main() {
    vector<int> arr {2,5,1,8,2,9,1};
    Solution ob;

    cout<<"Max sum of sub array of size K: " << ob.maxSumSubAarayOfSizeK(arr, 3) <<endl;
    return 0;
}