#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countOccurencesOfAnagram(string& s1, string& s2) {
        unordered_map<int, int> mp;
        int ans=0;
        int k=s2.size();    // window size;
        for(char x : s2)
            mp[x]++;
        
        int count=mp.size();
        int i=0, j=0;
        while(j<s1.size()) {
            mp[s1[j]]--;

            if(mp[s1[j]]==0)
                count--;
            if(j-i+1 == k) {
                if(count==0)
                    ans++;
                // shift i.
                if(mp[s1[i]]==0)
                    count++;
                mp[s1[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    string s1="aabaabaa";
    string s2="aaba";

    Solution ob;
    int res = ob.countOccurencesOfAnagram(s1, s2);

    cout<< res <<endl;
    return 0;
}