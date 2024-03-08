#include <iostream>
#include <vector>
#include <set>

using namespace std;

void permute(string inp, string op, vector<string> &ans) {
    if(inp.size() == 0) {
        ans.push_back(op);
        return;
    }
    int n=inp.size();
    set<char> st;
    st.clear();

    for(int i=0; i<n; i++) {
        if(st.find(inp[i]) == st.end()) {
            string newInp = inp.substr(0, i) + inp.substr(i+1, n-1-i);  // removing ith char.
            string newOp = op + inp[i];                                 // added ith char.
            st.insert(inp[i]);
            permute(newInp, newOp, ans);
        }
    }
}

vector<string> findPermutation(string &s) {
    vector<string> ans;
    
    permute(s, "", ans);    // (i/p, o/p, res)
    
    return ans;
}

int main() {
    string s="aacd";
    
    vector<string> res = findPermutation(s);
    
    for(string x:res) {
        cout<<x<<" ";
    }
    cout<<res.size()<<endl;
    return 0;
}
