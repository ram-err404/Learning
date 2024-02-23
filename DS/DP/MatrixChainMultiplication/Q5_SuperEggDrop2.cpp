// Q6: Super Egg Drop:

#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

// Recursive Solution:
int solve(int e, int f) {
  // Base Conditions:
  if(f==0 || f==1)  return f;
  if(e==1)  return f;
  
  int ans=INT_MAX;
  
  for(int k=1; k<=f; k++) {
    /* We will have 2 Conditions here:
      1.) When egg breaks:
            We have to further find if it breaks for or not for lower floors only with 1 less egg.
              (i.e)   solve(e-1, k-1);
      
      2.) When egg don't breaks:
            We have to further find if it breaks or not for upper floors only (i.e. for n-k floors).
              (i.e.)  solve(e, n-k);
            
      --> For the worst case we have the find the max(breaking, non-breaking) situation.
      
      --> Then finally, to find the minimum number of ways, we have find the min of all the temp ans.
      */
    int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
    
    ans = min(ans, temp);
  }
  return ans;
}

// Memoizased Solution: (Read recursive code for detailed explaination)
int solve(int e, int f, unordered_map<string, int> &dp) {
  stringstream key;
  key << e <<" "<< f;
  
  if(dp.find(key.str()) != dp.end())  return dp[key.str()];
  // Base Conditions:
  if(f==0 || f==1)  return f;
  if(e==1)  return f;
  
  int ans=INT_MAX;
  
  for(int k=1; k<=f; k++) {
    int temp = 1 + max(solve(e-1, k-1, dp), solve(e, f-k, dp));
    ans = min(ans, temp);
  }
  return dp[key.str()] = ans;
}

// Optimised Solution:
/*
We can even optimise the Memoizased solution, by using the binary search algo for selecting k.
*/
int superEggDrop(int e, int f, unordered_map<string, int> &dp) {
  stringstream key;
  key << e <<" "<< f;
  
  if(dp.find(key.str()) != dp.end())  return dp[key.str()];
  // Base Conditions:
  if(f==0 || f==1)  return f;
  if(e==1)  return f;
  
  int ans=INT_MAX;
  int l=1, h=f;
  while(l<h) {
    int mid = l+(h-l)/2;

    int brk = superEggDrop(e-1, mid-1, dp);
    int noBrk = superEggDrop(e, f-mid, dp);

    int temp = 1 + max(brk, noBrk);
    ans = min(ans, temp);
    
    // Now move l and h.
    if(brk > noBrk) {
      h = mid;
    } else {
      l=mid+1;
    }
  }
  return dp[key.str()] = ans;
}

int main() {
  int egg=3, flooor=5;  // o/p: 3

	unordered_map<string, int> dp;
  dp.clear();
  
  cout<<"Min number of ways to get the threshold floor for non-breaking egg (Recursive): " << solve(egg, flooor) << endl;
  cout<<"Min number of ways to get the threshold floor for non-breaking egg (Memoizase): " << solve(egg, flooor, dp) << endl;
  cout<<"Min number of ways to get the threshold floor for non-breaking egg (Optimised): " << superEggDrop(egg, flooor, dp) << endl;
  return 0;
}
