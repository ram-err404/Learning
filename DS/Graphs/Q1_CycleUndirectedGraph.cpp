// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?page=1&category=Graph&sortBy=submissions


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    vector<bool> vis;
    
    bool isCycleDfs(int cur, vector<int> adj[]) {
        stack<pair<int, int>> st;
        st.push({cur, -1});
        vis[cur] = true;
        
        while(!st.empty()) {
            int node = st.top().first;
            int parent = st.top().second;
            st.pop();
            
            for(int v : adj[node]) {
                if(!vis[v]) {
                    vis[v] = true;
                    st.push({v, node});
                } else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vis.resize(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDfs(i, adj)) {
                    return true;
                }
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends