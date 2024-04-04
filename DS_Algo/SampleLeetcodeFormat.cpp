#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> firstNegativeInWindowOfK(vector<int>& arr, int k) {

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