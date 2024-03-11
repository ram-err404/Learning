/* Q1: Print all the permutation of the string. (Using Backtracking).
 *
 * T(n) = WorkDone * Number of Nodes
 *  Number of Nodes = (n!)/(n-k)!               ==> n factorial.
 *  WorkDone at each node = O(n) * O(min(n,m))  ==> 1 for loop and O(min(n,m) for s.compare)  ~= O(n^2).
 *
 *  T(n) = O(n^2) * O(n!/(n-k)!) 
 *  	 = O((n^2 * n!)/(n-k)!)
 * 
 * */

#include <iostream>
using namespace std;

void mxNum(int start, string &s, int k, string &mx) {
    int n=s.size();
    if(k==0 || start==n-1) {
        return;
    }
    
    // find the maximum digit in the given string.
    
    char mxChar = s[start];
    for(int i=start+1; i<n; i++) {
        mxChar = max(mxChar, s[i]);
    }
    // char mxChar = *max_element(s.begin() + start +1, s.end());
    
    for(int i=start+1; i<n; i++) {
        if(s[start] < s[i] && s[i] == mxChar) {
            swap(s[start], s[i]);
            
            if(s.compare(mx) > 0) {
                mx = s;
            }
            mxNum(start+1, s, k-1, mx);
            swap(s[start], s[i]);
        }
    }
    /* Horizontal Driftting Case: Let's none of the above choices are valid. Now we have to do the same with start+1 position, 
        but we shouldn't decrease k.
    */
    mxNum(start+1, s, k, mx);    // Horizontal Drifting.
}

string findMaximumNum(string str, int k)
{
   // code here.
   string mx=str;
   mxNum(0, str, k, mx);
   return mx;
}

int main() {
    /* string s = "1234567";
    int k=4; */
    
    string s = "4551711527";
    int k = 3;                  // Correct O/p: 7755511124  --> This is the case of Horizontal driftting.
    
    cout<<"maximum number from "<< s <<" after "<< k <<" swaps: "<< findMaximumNum(s, k) <<endl;
    return 0;
}
