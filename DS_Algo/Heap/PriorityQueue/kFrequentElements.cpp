// https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
struct CompareFreq {
    bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int, int> freq;
        for(int x:nums)
            freq[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareFreq> mostFreq(freq.begin(), freq.end());
        vector<int> res;

        for(int i=1; i<=k; i++) {
            res.push_back(mostFreq.top().first);
            mostFreq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends