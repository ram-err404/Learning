// Scramble strings:

#include <iostream>
#include <unordered_map>

using namespace std;

bool solve(string s1, string s2) {
  // Base condition
  if(s1.compare(s2) == 0)   return true;
  if(s1.size() <= 1 || s2.size() <= 1)  return false;   // Leaf Node. No swapping allowed.
  
  int n=s1.size();
  bool ans=false;

  for(int k=1; k<=n-1; k++) { // k should start from 1, bcoz leaf node shouldn't be empty.
    // swapping condition
    bool cond1 = solve(s1.substr(0, k), s2.substr(n-k, k)) && solve(s1.substr(k, n-k), s2.substr(0, n-k));
    // non swapping condition
    bool cond2 = solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k, n-k), s2.substr(k, n-k));
  
    if(cond1 || cond2) {
      ans = true;
      break;
    }
  }
  return ans;
}

bool solve(string s1, string s2, unordered_map<string, bool> &dp) {
  string key=s1+" "+s2;
  
  if(dp.find(key) != dp.end())  return dp[key];
  if(s1.compare(s2) == 0)   return true;
  if(s1.size() <= 1 || s2.size() <= 1)  return false;
  
  int ans=false;
  int n=s1.size();
  
  for(int k=1; k<=n-1; k++) {
    // swapping case:
    bool cond1 = solve(s1.substr(0, k), s2.substr(n-k, k), dp) && solve(s1.substr(k ,n-k), s2.substr(0, n-k), dp);
    // non-swapping case:
    bool cond2 = solve(s1.substr(0, k), s2.substr(0, k), dp) && solve(s1.substr(k, n-k), s2.substr(k, n-k), dp);
    
    if(cond1 || cond2) {
      ans=true;
      break;
    }
  }
  return dp[key]=ans;
}

int main() {
  //string s1="great";
  //string s2="rgeat";  //==> Scramble String: True
  string s1="abcde";
  string s2="caebd";    //==> Scramble String: False

  if(s1.size()==0 && s2.size()==0)  cout<<"It is Scramble String" <<endl;
  if(s1.size() != s2.size())  cout<<"Not a Scramble String" <<endl;

  unordered_map<string, bool> dp;
  dp.clear();

  cout<<"'"<< s1 <<"' and '"<< s2 << "' strings are Scramble (Recursive) (True/False): "<< solve(s1, s2) <<endl;
	cout<<"'"<< s1 <<"' and '"<< s2 << "' strings are Scramble (Memoizase) (True/False): "<< solve(s1, s2, dp) <<endl;

  return 0;
}
