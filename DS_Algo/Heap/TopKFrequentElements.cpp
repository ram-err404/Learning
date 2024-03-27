// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    struct Compare{
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            if(p1.second == p2.second)
                return p1.first > p2.second;
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        
        for(int x:nums)     mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;     // This will sort the pq based on mentioned order.

        for(auto it:mp) {
            pq.push({it.first, it.second});
        }

        for(int i=1; i<=k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main () {
    vector<int> nums{1,2,4,4,4,4,4,2,2,11,1,3,3,1,0,-1,-2,-2,-2,-2,1};
    int k=4;
    Solution ob;
    vector<int> res = ob.topKFrequent(nums, k);

    for(int x:res)
        cout<< x <<" ";
    cout<<"\n";
    return 0;
}