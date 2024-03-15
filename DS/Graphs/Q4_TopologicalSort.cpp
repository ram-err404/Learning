// https://www.geeksforgeeks.org/problems/topological-sort/1?page=1&category=Graph&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    queue<int> q;
    vector<int> topo;
    vector<int> inDegree;
    
    void bfs(int i, vector<int> adj[]) {
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            topo.push_back(t);
            
            // Node is in your topo sort, so please remove it from inDegree.
            for(int u : adj[t]) {
                inDegree[u]--;
                if(inDegree[u] == 0) {
                    q.push(u);
                }
            }
        }
    }
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    inDegree.resize(V, 0);
	    for(int i=0; i<V; i++) {
	        for(int v : adj[i]) {
	            inDegree[v]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++) {
	        // push all the nodes to queue, whose in-degree is 0.
	        if(inDegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    for(int i=0; i<V; i++) {
	        bfs(i, adj);
	    }
	    
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends