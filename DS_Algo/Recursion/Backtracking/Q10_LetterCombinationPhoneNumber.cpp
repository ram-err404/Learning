// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, string> keypad {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    void solve(int start, const int n, string& digits, string& ans, vector<string>& res) {
        if(start==n) {
            res.push_back(ans);
            return;
        }
        if(start>=n)    return;
        
        string digitToAlpha=keypad[digits[start]-'0'];
        for(int i=0; i<digitToAlpha.size(); i++) {
            ans.push_back(digitToAlpha[i]);
            solve(start+1, n, digits, ans, res);
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> res;
        if(n==0)    return res;
        string ans;

        solve(0, n, digits, ans, res);
        return res;
    }
};

int main() {
    string digits="2395";
    Solution ob;

    vector<string> res = ob.letterCombinations(digits);
    cout<<"[";
    for(string s:res) {
        cout << s <<",";
    }
    cout<<"] Size:" << res.size() << endl;
    return 0;
}