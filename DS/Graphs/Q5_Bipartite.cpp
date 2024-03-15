// https://www.geeksforgeeks.org/problems/bipartite-graph/1?page=1&category=Graph&sortBy=submissions

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfsColor(int start, vector<int>adj[], queue<int> &q, vector<int> &vis) {
        q.push(start);     // 0, 1 are my 2 colors.
	    vis[start] = 0;

	    while(!q.empty()) {
	        int u = q.front();
	        q.pop();
	        
	        for(int v : adj[u]) {
	            if(vis[v] == -1) {
	                q.push(v);
	                vis[v] = !vis[u]&1;
	            } else if(vis[v] == vis[u]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    queue<int> q;
	    vector<int> vis(V, -1);
	    
	    for(int i=0; i<V; i++) {
	        if(vis[i] == -1 && bfsColor(i, adj, q, vis)==false) {
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends