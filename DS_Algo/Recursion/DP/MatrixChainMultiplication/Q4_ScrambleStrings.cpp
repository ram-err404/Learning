/* Leetcode question: 87    Scramble String
    https://leetcode.com/problems/scramble-string/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> mp;
public:
    bool solve(string s1, string s2) {
        if(s1.compare(s2) == 0)     return true;
        if(s1.size() <= 1)  return false;
        
        string key=s1+" "+s2;
        if(mp.find(key) != mp.end())    return mp[key];
        
        bool ans=false;
        int n=s1.size();
        for(int i=1; i<=n-1; i++) {
            bool cond1=( solve(s1.substr(0,i), s2.substr(n-i,i)) && solve(s1.substr(i,n-i), s2.substr(0, n-i)) );
            bool cond2=( solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i,n-i), s2.substr(i,n-i)) );
            if(cond1 || cond2) {
                ans=true;
                break;
            }
        }
        return mp[key]=ans;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size()==0 && s2.size()==0)  return true;
        if(s1.size() != s2.size())    return false;
        
        return solve(s1,s2);
    }
};

int main() {
    string s1="great";
    string s2="rgeat";

    Solution ob;

    cout<<"String s1 and s2 are scramble: " << ob.isScramble(s1, s2) <<endl;

    return 0;
}