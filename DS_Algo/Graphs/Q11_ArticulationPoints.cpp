// https://www.geeksforgeeks.org/problems/articulation-point-1/1

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=1;
    
    void dfs(int node, int parent, vector<int> adj[], vector<bool>& vis,
            vector<int>& tin, vector<int>& low, vector<int>& mark) {
        timer++;
        vis[node] = true;
        tin[node] = timer;
        low[node] = timer;
        int child=0;
        
        for(auto it : adj[node]) {
            if(it == parent)    continue;
            
            if(!vis[it]) {
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent!=-1) {
                    // node {it} cannot be reached without node {node}. So {node} is my articulation point.
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        vector<int> tin(V+1);
        vector<int> low(V+1);
        vector<int> mark(V+1);
        
        // traverse through every compos.
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        vector<int> res;
        for(int i=0; i<=V; i++) {
            if(mark[i] == 1)
                res.push_back(i);
        }
        if(res.size()==0)   return {-1};
        return res;
    }
};


//{ Driver Code Starts.

int main(){
	int n=13;
    vector<vector<int>> connections {{0,1},{0,2},{1,2},{2,3},{3,4},{4,1},{4,5},{5,6},{6,7},{6,9},{7,8},{8,9},{8,10},{10,11},{10,12},{11,12}};

    Solution ob;
    vector<int> adj[n+1];
    
    for(auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int> res = ob.articulationPoints(n, adj);

    cout<<"Articulations Points: ";
    for(auto x : res)
        cout<< x <<" ";
    cout<< endl;
	return 0;
}
// } Driver Code Ends