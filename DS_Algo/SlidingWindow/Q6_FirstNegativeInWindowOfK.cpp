#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> firstNegativeInWindowOfK(vector<int>& arr, int k) {
        vector<int> res;
        queue<int> q;
        int i=0, j=0;
        int n=arr.size();

        while(j<n) {
            if(arr[j] < 0) {
                q.push(arr[j]);
            }
            if(j-i+1 == k) {
                if(!q.empty()) {
                    res.push_back(q.front());
                } else {
                    res.push_back(0);
                }
                if(arr[i] == q.front()) {
                    q.pop();
                }
                i++;
            }
            j++;
        }
        return res;
    }
};

int main() {
    vector<int> arr {12,-1,-7,8,-16,30,18,28};

    Solution ob;
    vector<int> res = ob.firstNegativeInWindowOfK(arr, 3);

    for(int x:res)
        cout<< x <<" ";
    cout<< endl;
    return 0;
}