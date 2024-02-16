// Print Longest Common Subsequence.

#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string &str1, string &str2) {
    int m=str1.size();
    int n=str2.size();
    stringstream result;

    int dp[m+1][n+1]={0};   // no special initialisation otherthan zero is required.

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
    string str1="abcdgh";
    string str2="abedfhr";

    cout<<"Longest Common Subsequence "<< longestCommonSubsequence(str1, str2) <<endl;
    return 0;
}