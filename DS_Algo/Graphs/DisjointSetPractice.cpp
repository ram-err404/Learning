
class DSU {
private:
    vector<int> rank, parent;
public:
    DSU(int N) {
        rank.resize(N+1, 0);
        parent.resize(N+1, 0);

        for(int i=0; i<=N; i++) {
            parent[i] = i;
        }
    }

    // union, findParent
    int findParent(int u) {
         if( parent[u] == u) return u;

         return parent[u] = findParent(parent[u]);
    }

    void doUnion(int u, int v) {
        int ult_u = findParent(u);
        int ult_v  = findParent(v);

        if(ult_u == ult_v)  return; // they are already connected.

        if(rank[ult_u] == rank[ult_v]) {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        } else if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        } else {
            parent[ult_v] = ult_u;
        }
    }
}

