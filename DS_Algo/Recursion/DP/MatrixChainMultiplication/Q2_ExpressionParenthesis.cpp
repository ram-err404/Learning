
//#include<bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int exprParenthesisRecursive(string &expr, int i, int j, bool isTrue) {
  if(i>j) return false;
  if(i==j) {
    if(isTrue)  return expr[i]=='T';
    else        return expr[i]=='F';
  }

  int ans=0;
  for(int k=i+1; k<j; k++) {
    // In the internal problem we might have to calculate both true and false scenarios.
    bool LT = exprParenthesisRecursive(expr, i, k-1, true);
    bool LF = exprParenthesisRecursive(expr, i, k-1, false);
    bool RT = exprParenthesisRecursive(expr, k+1, j, true);
    bool RF = exprParenthesisRecursive(expr, k+1, j, false);

    // Need to calculate the final answer...
    // Now calculate the ans based on the operator present.
    if(expr[k] == '&') {
      if(isTrue == true) {
        ans = ans + LT*RT;
      } else {
        ans = ans + LF*RT + LF*RF + LT*RF;
      }
    } else if(expr[k] == '|') {
      if(isTrue==true) {
        ans = ans + LT*RT + LT*RF + LF*RT;
      } else {
        ans = ans + LF*RF;
      }
    } else if(expr[k] == '^') {
      if(isTrue==true) {
        ans = ans + LT*RF + LF*RT;
      } else {
        ans = ans + LT*RT + LF*RF;
      }
    }
  }
  return ans;
}

/* Memoizase solution: 
  --> For memoization, we need to either create 3D matrix for changing variables (i.e. i, j, isTrue) or we could
      create an unordered_map with key as combination of "i j isTrue" and store ans in it.
*/

int exprParenthesis(string &expr, int i, int j, bool isTrue, unordered_map<string, int> &dp) {
  // create key for storing ans.
  stringstream key;
  key << i <<" "<< j <<" "<<isTrue;
  if(dp.find(key.str()) != dp.end())  return dp[key.str()];

  if(i>j) return false;
  if(i==j) {
    if(isTrue)  return expr[i]=='T';
    else        return expr[i]=='F';
  }

  int ans=0;
  for(int k=i+1; k<j; k++) {
    // In the internal problem we might have to calculate both true and false scenarios.
    bool LT = exprParenthesis(expr, i, k-1, true, dp);
    bool LF = exprParenthesis(expr, i, k-1, false, dp);
    bool RT = exprParenthesis(expr, k+1, j, true, dp);
    bool RF = exprParenthesis(expr, k+1, j, false, dp);

    // Need to calculate the final answer...
    // Now calculate the ans based on the operator present.
    if(expr[k] == '&') {
      if(isTrue == true) {
        ans = ans + LT*RT;
      } else {
        ans = ans + LF*RT + LF*RF + LT*RF;
      }
    } else if(expr[k] == '|') {
      if(isTrue==true) {
        ans = ans + LT*RT + LT*RF + LF*RT;
      } else {
        ans = ans + LF*RF;
      }
    } else if(expr[k] == '^') {
      if(isTrue==true) {
        ans = ans + LT*RF + LF*RT;
      } else {
        ans = ans + LT*RT + LF*RF;
      }
    }
  }
  return dp[key.str()] = ans;
}

int main() {
  string expr = "T|F&T^F";
  int n=expr.size();
  
  unordered_map<string, int> dp;
  dp.clear();

  cout<<"Number of ways to add parenthesis to make the expression true (Recursive): "<< exprParenthesisRecursive(expr, 0, n-1, true) <<endl;
  cout<<"Number of ways to add parenthesis to make the expression true (Memoizase): "<< exprParenthesis(expr, 0, n-1, true, dp) <<endl;
  return 0;
}
