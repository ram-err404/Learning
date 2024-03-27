/* Q7: Combination Sum: Find all the combination that leads to given sum. (Order of number is in non-decreasing order).*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int idx, int target, vector<int> &ARR, vector<int> &v, vector<vector<int>> &res) {
    int n = ARR.size();
    
    if (idx == n) {
        if (target == 0) {
            res.push_back(v);
        }
        return;
    }

    // picking this idx.
    if (ARR[idx] <= target) {
        if(v.size()==0 || ARR[idx] >= v[v.size()-1]) {
            v.push_back(ARR[idx]);
            solve(idx, target-ARR[idx], ARR, v, res);
            v.pop_back(); // Backtracking.
        }
    }
    // Not picking this idx
    solve(idx+1, target, ARR, v, res);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> v;              // Here we will doing the backtracking.
    sort(ARR.begin(),ARR.end());

    solve(0, B, ARR, v, res);
    return res;
}

int main() {
    vector<int> ARR{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target=5;
    
    vector<vector<int>> res = combSum(ARR, target);
    
    cout<<"Given ARR:"<<endl;
    for(int x:ARR) {
        cout<<x<<" ";
    }
    cout<<"\nAll possible comination of sum "<< target <<" are:" <<endl;
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}