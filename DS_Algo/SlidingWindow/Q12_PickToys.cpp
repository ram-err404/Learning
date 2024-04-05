// Same as "LongestSubstrwithKUniqueChars"

// Q: John has to pick toys sequentially only from a rack of toys. He can pick any number of similar toys but he can only pick total K distinct toys.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int pickToys(string& toys, int k) {
        int mx=0;
        int i=0, j=0;
        int count=0;
        unordered_map<char, int> mp;

        while(j < toys.size()) {
            mp[toys[j]]++;
            count = mp.size();

            if(count == k) {
                mx = max(mx, j-i+1);
            } else if (count > k) {
                mp[toys[i]]--;
                if(mp[toys[i]] == 0)
                    mp.erase(toys[i]);
                i++;
            }
            j++;
        }
        return mx;
    }
};

int main() {
    string toys="abaccab";

    Solution ob;
    int res = ob.pickToys(toys, 2);

    cout<<"Total number of toys that he can pick: "<< res << endl;

    return 0;
}