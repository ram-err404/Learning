// Krushkal's Algorithm is find Minimum Spanning Tree using Disjoint Sets.
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int N) {
        rank.resize(N+1, 0);
        parent.resize(N+1);
        
        for(int i=0; i<=N; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        if(node == parent[node])    return node;
        // Path Compression
        return parent[node] = findParent(parent[node]);
    }
    
    void unionRank(int u, int v) {
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);
        
        if(ult_pu == ult_pv)    return;     // {u, v} are already connected.
        
        if(rank[ult_pu] < rank[ult_pv]) {
            parent[ult_pu] = ult_pv;
        } else if(rank[ult_pu] == rank[ult_pv]) {
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        } else {
            parent[ult_pv] = ult_pu;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    pair<int, vector<pair<int, pair<int, int>>>> spanningTree(int V, vector<vector<int>> adj[])
    {
        // Krushkal's Algorithm:
        /*  First we will created all the edges vector so that we can sort them on the basis of their weights.
            And then we will start connecting the nodes using Disjoint Set.
        */
        vector<pair<int, pair<int, int>>>   edges;  // {wt, {u, v}}
        for(int i=0; i<V; i++) {
            int u = i;
            for(auto it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
            }
        } // edges are created.
        
        sort(edges.begin(), edges.end());
        
        DisjointSet dsu(V);
        int mstWt = 0;
        vector<pair<int, pair<int, int>>> MST;
        
        for(auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dsu.findParent(u) != dsu.findParent(v)) {
                mstWt += wt;
                MST.push_back({wt, {u, v}});
                dsu.unionRank(u, v);
            }
        }
        return {mstWt, MST};
    }
};

int main() {
    int V=3;
    vector<vector<int>> adj[3] {{{1,5}, {2, 1}}, {{0, 5}, {2, 3}}, {{1, 3}, {0, 1}}};
    Solution ob;
    pair<int, vector<pair<int, pair<int, int>>>> res = ob.spanningTree(V, adj);

    cout<<"Sum of Minimum Spanning Tree: "<< res.first << endl;
    cout<<"Minimum Spanning Tree: {Node, Edge, Weight}: "<< endl;
    for(auto it : res.second) {
        cout<<"{" << it.second.first <<", "<< it.second.second <<", "<< it.first << "}";
    }
    return 0;
}