// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?page=1&category=Graph&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V, false);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();
            
            for(int edge : adj[node]) {
                if(!vis[edge]) {
                    vis[edge] = true;
                    q.push(edge);
                }
            }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends