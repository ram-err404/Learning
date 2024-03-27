/* GFG: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1?page=1&category=Greedy&sortBy=submissions

1 5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15
*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool DecendingProfit(Job j1, Job j2) {
    return (j1.profit > j2.profit);
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, DecendingProfit);
        // Find the max deadline.
        int maxDeadline=0;
        for(int i=0; i<n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<bool> deadLine(maxDeadline, false);
        int count=0, profit=0;
        for(int i=0; i<n; i++) {
            int j = arr[i].dead-1;
            while(j>=0 && deadLine[j] == true) j--;
            if(j>=0) {
                count++;
                profit += arr[i].profit;
                deadLine[j] = true;
            }
        }
        return {count, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends