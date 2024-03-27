// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?page=1&category=Graph&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int cur, vector<int> adj[], vector<bool> &vis, vector<int> &res) {
        if(!vis[cur]) {
            vis[cur] = true;
            res.push_back(cur);
            
            for(int edge : adj[cur]) {
                dfs(edge, adj, vis, res);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            dfs(0, adj, vis, res);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends