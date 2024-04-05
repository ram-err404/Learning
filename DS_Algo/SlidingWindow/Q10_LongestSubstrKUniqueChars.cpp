#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestSubstrKUniqueChars(string& str, int k) {
        string res;
        int mx=0;
        int i=0, j=0;
        unordered_map<char, int> mp;
        
        while(j<str.size()) {
            mp[str[j]]++;
            
            if(mp.size() == k) {
                if(mx < j-i+1) {
                    mx = j-i+1;
                    res = str.substr(i, j-i+1);
                }
            } else if(mp.size() > k) {
                // need to shift i.
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};

int main() {
    string str="aabacbebebe";
    Solution ob;
    string res = ob.longestSubstrKUniqueChars(str, 3);

    cout<<"Longest substr with K uniuqe chars: "<< res << endl;
    return 0;
}