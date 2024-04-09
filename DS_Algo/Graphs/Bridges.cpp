// https://leetcode.com/problems/critical-connections-in-a-network/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int timer;
    void dfs(int node, int parent, vector<int> adj[], vector<bool>& vis, int tin[], int low[], 
            vector<vector<int>>& bridges) {
        
        timer++;
        vis[node] = true;
        tin[node] = timer;
        low[node] = timer;
        
        for(auto it : adj[node]) {
            if(it == parent)    continue;
            
            if(!vis[it]) {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // check for bridge.
                if(tin[node] < low[it]) { 
                    // current node "it" cannot be reached without parent node "node".
                    // So this is a bridge.
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        int tin[n+1];
        int low[n+1];
        vector<int> adj[n+1];
        vector<bool> vis(n+1, false);
        timer=0;

        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        } // Graph is ready.
        
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};

int main() {
    // TC: 1
    int n=13;
    vector<vector<int>> connections {{0,1},{0,2},{1,2},{2,3},{3,4},{4,1},{4,5},{5,6},{6,7},{6,9},{7,8},{8,9},{8,10},{10,11},{10,12},{11,12}};

    // TC:2
    // vector<vector<int>> connections {{0,1},{0,2},{1,2},{1,3}};
    // int n=4;

    Solution ob;
    vector<vector<int>> bridges = ob.criticalConnections(n, connections);
    cout<<"All the bridges are: [ ";
    for(auto it : bridges) {
        cout<<"{"<< it[0] <<","<< it[1] <<"} ";
    }
    cout<<"]"<< endl;
    return 0;
}