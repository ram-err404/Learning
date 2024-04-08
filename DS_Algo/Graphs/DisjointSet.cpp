#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DSU(int N) {
        // creating N+1, to handle 1 based indexing of Graph.
        rank.resize(N+1, 0);
        parent.resize(N+1);

        for(int i=0; i<=N; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(u == parent[u])  return u;
        // path compression.
        return parent[u] = findParent(parent[u]);
    }
    void unionRank(int u, int v) {
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);

        if(ult_pu == ult_pv)    return;

        int ult_pu_rank = rank[ult_pu];
        int ult_pv_rank = rank[ult_pv];

        if(ult_pu_rank == ult_pv_rank) {
            parent[ult_pv] = ult_pu;
            rank[ult_pu]++;
        } else if(ult_pu_rank > ult_pv_rank) {
            parent[ult_pv] = ult_pu;
        } else {
            parent[ult_pu] = ult_pv;
        }
    }
};

int main() {
    DSU dsu(7);
    // start connecting nodes.
    dsu.unionRank(1, 2);
    dsu.unionRank(2, 3);
    dsu.unionRank(4, 5);
    dsu.unionRank(6, 7);
    // check if two nodes are connected or not??
    if(dsu.findParent(3) == dsu.findParent(4)) {
        cout<<"Same" <<endl;
    } else {
        cout<<"Not Same" <<endl;
    }
    dsu.unionRank(5, 6);
    dsu.unionRank(3, 7);
    if(dsu.findParent(3) == dsu.findParent(4)) {
        cout<<"Same" <<endl;
    } else {
        cout<<"Not Same" <<endl;
    }
    return 0;
}