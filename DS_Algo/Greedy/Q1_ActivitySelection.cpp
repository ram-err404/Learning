// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1?page=1&category=Greedy&sortBy=submissions

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct activity {
    int s;
    int e;
};

bool compareInterval(struct activity m1, struct activity m2) {
    return (m1.e < m2.e);
}

class Solution
{
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<struct activity> ac(n);
        for(int i=0; i<n; i++) {
            ac[i].s = start[i];
            ac[i].e = end[i];
        }
        
        sort(ac.begin(), ac.end(), compareInterval);
        
        int act=1;
        int i=1, j=0;
        for(i=1; i<n; i++) {
            if(ac[i].s > ac[j].e) {
                act++;
                j=i;
            }
        }
        return act;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends