// Print Longest Common Subsequence.

// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/* Note: This logic isn't correct. Please check Q3_PrintLCSubsequence2.cpp 
  This won't give proper result for string s1="agbcba" & s2="abcbga"
  i.e. If s2 is reverse of s2.

  It should print the longest palindromic subsequence.
*/
string longestCommonSubsequence(string &str1, string &str2) {
    int m=str1.size();
    int n=str2.size();
    stringstream result;

    //int dp[m+1][n+1]={0};   // no special initialisation otherthan zero is required.
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) {
                result << str1[i-1];
            }
        }
    }
    return result.str();
}

// Efficient way:
string printLcsEfficient(string &str1, string &str2) {
    // create hashmaps and insert the string2 elements to them.
    // then check str1[i] present in hashmap2.
    
    // if yes insert the element in stringstream obj.
    // Finally return the string stream obj.
    return "";
}

int main() {
    string s1="abcdgh";
    string s2="abedfhr";

    cout<<"Longest Common Subsequence "<< longestCommonSubsequence(s1, s2) <<endl;
    return 0;
}
