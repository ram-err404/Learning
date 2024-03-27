// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1?page=1&category=Greedy&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Meeting {
    int start;
    int end;
};

bool IncreasingEndTime(Meeting m1, Meeting m2) {
    return (m1.end < m2.end);
}

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<Meeting> meetings(n);
        
        for(int i=0; i<n; i++) {
            meetings[i].start = start[i];
            meetings[i].end = end[i];
        }
        sort(meetings.begin(), meetings.end(), IncreasingEndTime);
        
        int count = 1;
        for(int i=1, j=0; i<n; i++) {
            if(meetings[i].start > meetings[j].end) {
                count++;
                j=i;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends