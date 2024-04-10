#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    // Brute Force approach:
    // T(N) = O(n*k*n)  ~= O(n^2 * k)
    /* int maxWindowLengthEqualNumber(vector<int>& arr, int k) {
        int mxWinLen=0;
        set<int> totalDistinctElement;
        
        for(int i=0; i<arr.size(); i++) {
            totalDistinctElement.insert(arr[i]);
        }

        if(totalDistinctElement.size() == arr.size()) {
            // all elements are distinct.
            return k+1;   // 3 max elements we can change and 1 self.
        }
        
        for(int i=0; i<arr.size()-k; i++) { // O(n)
            for(auto x : totalDistinctElement) {    // O(k)
                int changes=0;
                int j=i;
                while(j<arr.size()) {               // O(n)
                    if(changes<k && x != arr[j]) {
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
    */

    // Optimised solution: Using Sliding Window.
    // O(N*M) ~= O(N^2)   ==> M: Distinct Elements.     M ~== N
    int maxWindowLengthEqualNumber(const vector<int>& arr, int k) {
        int n = arr.size();
        set<int> distinct_elements(arr.begin(), arr.end());
        int max_length = 0;
        for (int value : distinct_elements) {
            int current_max_length = 0;
            int edits_used = 0;
            int start_index = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == value) {
                    current_max_length = i - start_index + 1; // Correctly update based on current index
                } else {
                    if (edits_used < k) {
                        edits_used++;
                    } else {
                        current_max_length = i - start_index; // Correctly calculate length before starting a new window
                        start_index = i + 1;
                        edits_used = 0;
                    }
                }
                max_length = max(max_length, current_max_length);
            }
            // Check for potential maximum length at the end:
            max_length = max(max_length, n - start_index);
        }
        return max_length;
    }
};

int main() {
    vector<int> arr {1,-1,1,-1,1,-1,1,3,2,2};
        // O/p: 7
    // vector<int> arr {1,2,3,2,3,3,3,1,1};
        // O/p: 7
    // vector<int> arr = {1,2,3,3,3,2,2,1};
    // O/p: 6
    int k=3;
    Solution ob;

    cout<<"Max window length with equal number (after 3 changes): " << ob.maxWindowLengthEqualNumber(arr, k) <<endl;
    return 0;
}