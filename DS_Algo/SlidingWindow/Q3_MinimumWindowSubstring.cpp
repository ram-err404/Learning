// https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        if(n==0 || m<n)   return "";

        unordered_map<char, int> window;
        unordered_map<char, int> countT;

        int have=0;
        for(char c : t) {
            countT[c]++;
        }
        int need=countT.size();

        int left=0, right=0;
        pair<int, int> resIdx {-1, -1};
        int mn=INT_MAX;
        while(right<m) {
            char c = s[right];
            window[c]++;

            if(countT.find(c) != countT.end() && window[c] == countT[c])
                have++;
            while(have==need) {
                // update the result
                if(right-left+1 < mn) {
                    resIdx = {left, right};
                    mn = (right-left+1);
                }
                // pop the element from left of our window.
                window[s[left]]--;
                if(countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }
        if(resIdx.first >=0 && resIdx.second>=0)
            return s.substr(resIdx.first, resIdx.second-resIdx.first+1);
        else 
            return "";
    }
};

int main() {
    // TC: 1
    string s="ADOBECODEBANC";
    string t="ABC";
    // TC: 2
    // string s="a";
    // string t="aa";
    Solution ob;

    string res = ob.minWindow(s, t);
    if(res.size()) {
        cout<<"Minimum Window Substring: " << res << endl;
    } else {
        cout<<"Empty string" <<endl;
    }
    return 0;
}