#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    // Brute Force approach:
    // T(N) = O(n*k*n)  ~= O(n^2 * k)
    // Think for an optimised version.
    int maxWindowLengthEqualNumber(vector<int>& arr) {
        int mxWinLen=0;
        set<int> totalDistinctElement;
        
        for(int i=0; i<arr.size(); i++) {
            totalDistinctElement.insert(arr[i]);
        }

        if(totalDistinctElement.size() == arr.size()) {
            // all elements are distinct.
            return 4;   // 3 max elements we can change and 1 self.
        }
        
        for(int i=0; i<arr.size()-3; i++) { // O(n)
            for(auto x : totalDistinctElement) {    // O(k)
                int changes=0;
                int j=i;
                while(j<arr.size()) {               // O(n)
                    if(changes<3 && x != arr[j]) {
                        changes++;
                    } else if(x != arr[j]) {
                        break;
                    }
                    j++;
                }
                mxWinLen = max(mxWinLen, j-i);
            }
        }
        return mxWinLen;
    }
};

int main() {
    // vector<int> arr {1,-1,1,-1,1,-1,1,3,2,2};
    vector<int> arr {1,2,3,2,3,3,3,1,1};
    Solution ob;

    cout<<"Max window length with equal number (after 3 changes): " << ob.maxWindowLengthEqualNumber(arr) <<endl;
    return 0;
}