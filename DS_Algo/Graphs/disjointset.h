#ifndef __DISJOINTSET_H__
#define __DISJOINTSET_H__

#include <vector>
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

#endif