// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1?page=1&category=Greedy&sortBy=submissions

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> res;
        vector<int> coins {1,2,5,10,20,50,100,200,500,2000};
        int i=coins.size()-1;
        
        while(i>=0 && N>0) {
            if(coins[i] <= N) {
                N -= coins[i];
                res.push_back(coins[i]);
            } else {
                i--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends