// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?page=1&category=Greedy&sortBy=submissions


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool compareItem(Item i1, Item i2) {
    double x = static_cast<double>(i1.value)/i1.weight;
    double y = static_cast<double>(i2.value)/i2.weight;

    return x > y;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, compareItem);
        double ans=0.0;
        
        for(int i=0; i<n && W>0; i++) {
            if(arr[i].weight <= W) {
                ans += arr[i].value;
                W -= arr[i].weight;
            } else {
                ans += (static_cast<double>(arr[i].value)/arr[i].weight)*W;
                W = 0;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends