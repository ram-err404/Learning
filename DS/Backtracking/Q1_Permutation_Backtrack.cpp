#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void permute(int idx, string &inp, vector<string> &ans) {
    if(idx == inp.size()-1) {
        ans.push_back(inp);
        return;
    }
    int n=inp.size();
    unordered_set<char> st;
    
    for(int i=idx; i<n; i++) {
        if(st.find(inp[i]) == st.end()) {
            st.insert(inp[i]);
            
            swap(inp[idx], inp[i]);         // swap idx with ith index.
            permute(idx+1, inp, ans);

            swap(inp[idx], inp[i]);         // revert previous changes. Backtracking.
        }
    }
}

vector<string> findPermutation(string &s) {
    vector<string> ans;
    
    permute(0, s, ans);    // (starting index, I/P string, res)
    
    return ans;
}

int main() {
    string s="aacd";
    
    vector<string> res = findPermutation(s);
    
    cout<<s<<endl;
    for(string x:res) {
        cout<<x<<" ";
    }
    cout<<res.size()<<endl;
    return 0;
}