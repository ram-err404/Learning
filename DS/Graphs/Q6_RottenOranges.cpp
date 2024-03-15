// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1?page=1&category=Graph&sortBy=submissions

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
private:
    bool isValid(int x, int y, vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            return true;
        return false;
    }
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis = grid;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int R[4] = {-1, 0, 1, 0};   // U, R, D, L
        int C[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            mx = max(mx, t);
            
            for(int i=0; i<4; i++) {
                int newX = x + R[i];
                int newY = y + C[i];
                
                if(isValid(newX, newY, vis)) {
                    q.push({{newX, newY}, t+1});
                    vis[newX][newY] = 2;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == 1)
                    return -1;
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends