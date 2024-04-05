#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestSubstrNoRepeatingChar(string& str) {
        string res;
        int mx=0;
        int i=0, j=0;
        unordered_set<char> st;
        
        while(j < str.size()) {
            while(st.find(str[j]) != st.end()) {
                // need to remove from ith index till find str[i]!=str[j]
                st.erase(str[i]);
                i++;
            }
            st.insert(str[j]);
            
            if(mx < j-i+1) {
                mx = j-i+1;
                res = str.substr(i, j-i+1);
            }
            j++;
        }
        return res;
    }
};

int main() {
    string str="abcadbcefces";

    Solution ob;
    string res = ob.longestSubstrNoRepeatingChar(str);

    cout<<"Longest Substring with no repeating chars: "<< res << endl;
    return 0;
}