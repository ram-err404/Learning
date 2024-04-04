#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxInSubarrayOfSizeK(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        int i=0, j=0;
        
        while(j<arr.size()) {
            while(!dq.empty() && arr[j] > dq.back())
                dq.pop_back();
            dq.push_back(arr[j]);

            if(j-i+1 == k) {
                res.push_back(dq.front());

                if(!dq.empty() && arr[i] == dq.front())
                    dq.pop_front();
                i++;
            }
            j++;
        }
        return res;
    }
};

int main() {
    vector<int> arr {1,3,2,5,8,2,7,9,10};

    Solution ob;
    vector<int> res = ob.maxInSubarrayOfSizeK(arr, 3);

    for(int x:res)
        cout<< x <<" ";
    cout<< endl;
    return 0;
}