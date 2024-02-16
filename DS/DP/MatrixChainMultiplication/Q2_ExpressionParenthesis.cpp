#include<bits/stdc++.h>
using namespace std;

bool exprParenthesisRecursive(string &expr, int i, int j, bool isTrue) {
    if(i>j) return 0;
    
}

int main() {
    string expr = "T|F&T^F";
    int n=expr.size();

    // int dp[n][n] = {-1};
    cout<<"Max number of ways to add parenthesis to make the expression true: "<< exprParenthesisRecursive(expr, 0, n-1, true) <<endl;
    return 0;
}