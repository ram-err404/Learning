/* Q5: Word Break: return all the possible combinations of words formed from given string that matches the given dict.

	T(n) = WorkDone * Number of Nodes
	WorkDone = O(n^2)
	Number of Nodes = O(n^n)	==> generally, but most choices are voided. so removed and it changes to 2^n.
					= (2^n)		==> 1 branch till prefix, and other's till all remaining substring.
					
	T(n) = O(n^2 * 2^n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void solve(string s, string word, int n, unordered_set<string> &st, vector<string> &res) {
    
    for(int i=1; i<=n; i++) {				// O(n)
        string prefix = word.substr(0, i);	// O(n)
        
        if(st.find(prefix) != st.end()) { // prefix is present. Now match the remaining part.
            if(i==n) {
                s += prefix;
                res.push_back(s);
                return;
            }
            // recursively call the solve for remaining substr of word.
            solve(s + prefix +" ", word.substr(i, n-i), n-i, st, res);   // backtracking will be handled with fn call.
        }
    }
}
    
vector<string> wordBreak(int N, vector<string>& dict, string word)
{
    // code here
    vector<string> res;
    
    // for speedy lookup.
    unordered_set<string> st;
    for(string w:dict) {
        st.insert(w);
    }
    
    solve("", word, word.size(), st, res);
    return res;
}

int main() {
    string word="ilikeicecreamandmango";
    vector<string> dict{"i", "like", "sam", "sung", "samsung", "mobile", "ice",\
                        "and", "cream", "icecream", "man", "go", "mango"};
    
    vector<string> res = wordBreak(word.size(), dict, word);
    
    for(string s:res) {
        cout<<s<<endl;
    }
    
    return 0;
}