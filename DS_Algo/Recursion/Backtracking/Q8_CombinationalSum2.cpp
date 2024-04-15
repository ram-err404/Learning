// https://leetcode.com/problems/combination-sum-ii/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void solve(int idx, int target, vector<int>& candidates, 
                vector<int>& ans, vector<vector<int>>& res) {
      if(target==0) {
        res.push_back(ans);
        return;
      }
      int n=candidates.size();
      for(int i=idx; i<n; i++) {
        if(i>idx && candidates[i] == candidates[i-1])  continue;
        
        if(target-candidates[i] >= 0) {
          // I can include this.
          ans.push_back(candidates[i]);
          solve(i+1, target-candidates[i], candidates, ans, res);
          ans.pop_back();
        } else {
          // I cannot include this.
          break;
        }
      }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> ans;
      sort(candidates.begin(), candidates.end());

      solve(0, target, candidates, ans, res);
      return res;
    }
};

void printRes(vector<vector<int>>& res) {
    cout<<"[";
    for(auto vec : res) {
        cout<<"[";
        for(int x:vec)
            cout<< x <<",";
        cout<<"]";
    }
    cout<<"]"<< endl;
}

int main() {
    vector<int> candidates {10,1,2,7,6,1,5};
    int target=8;
    /* Output: [ [1,1,6], [1,2,5], [1,7], [2,6] ] */

    Solution ob;
    vector<vector<int>> res = ob.combinationSum2(candidates, target);
    printRes(res);
    return 0;
}