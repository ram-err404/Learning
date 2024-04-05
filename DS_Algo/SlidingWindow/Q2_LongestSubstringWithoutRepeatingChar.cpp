// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    /* int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1)    return n;
        
        int count=0;
        int mx=INT_MIN;
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                int idx = mp[s[i]];
                for(auto it=mp.cbegin(), next=it; !mp.empty() && it != mp.cend(); it = next) {
                    ++next;
                    if(it->second <= idx) {
                        mp.erase(it);
                        count--;
                    }
                }
            }
            mp[s[i]] = i;
            count++;
            mx = max(mx, count);
        }
        return mx;
    } */

    int lengthOfLongestSubstring(string s) {
        // Sliding window approach:
        int n=s.size();
        unordered_set<char> st;
        int left=0, right=0;
        int mx=0;
        
        for(char c : s) {
            while(st.find(c) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            mx = max(mx, right-left+1);
            right++;
        }
        return mx;
    }
};

int main() {
    // string s="dvdf";
    string s="vdudfe";
    Solution ob;
    cout<<"Length of longest substring without repeating chars: "<< ob.lengthOfLongestSubstring(s) <<endl;
    return 0;
}