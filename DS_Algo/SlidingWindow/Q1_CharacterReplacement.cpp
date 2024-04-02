// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <iostream>
#include <unordered_map>

#define max(a, b) a>b?a:b;

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding window approach:
        int left=0, right=0;
        unordered_map<char, int> alphabets;
        int maxFreq = 0;
        int windowSize;

        for(;right < s.size(); right++) {
            alphabets[s[right]]++;
            maxFreq = max(maxFreq, alphabets[s[right]]);
            windowSize = right-left+1;
            // winSize - maxFreq <= k
            if(windowSize - maxFreq > k) {
                alphabets[s[left]]--;
                if(s[left] == s[right])
                    maxFreq--;
                left++;
                windowSize--;
            }
        }
        return windowSize;
    }
};

int main() {
    // TC: 1
    // string s="ABAB";
    // int k=2;

    // TC: 2
    string s="AABABBA";
    int k=1;
    Solution ob;

    cout<<"Length of Longest Repeating Character Replacement: " << ob.characterReplacement(s, k) << endl;
    return 0;
}