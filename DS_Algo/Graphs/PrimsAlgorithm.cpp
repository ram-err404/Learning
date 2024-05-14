// Prim's Algorithm
// Minimum Spanning Tree.
// T(V, E)  = O(E*logE)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comparePair {
    bool operator() (pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2) {
        return p2.first < p1.first;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    pair<int ,vector<pair<int, pair<int, int>>> > spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum=0;
        vector<bool> vis(V, false);
        priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >,
            comparePair> pq;
        
        vector<pair<int, pair<int, int>>> MST;
        
        pq.push({0, {0, -1}});  // {wt, node, parent}
        // T(V, E) = E*logE + E*logE
        while(!pq.empty()) {            // O(E)
            // O(log(E))    // for priority queue.
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node])   continue;
            
            if(parent != -1) {
                MST.push_back({wt, {parent, node}});
            }
            vis[node] = true;
            sum += wt;
            
            for(auto it : adj[node]) {
                // O(E logE)    // E times and logE for priority_queue push.
                int edgeNode = it[0];
                int weight = it[1];
                
                if(!vis[edgeNode]) {
                    pq.push({weight, {edgeNode, node}});
                }
            }
        }
        return {sum, MST};
    }
};

int main() {
    int V=3;
    vector<vector<int>> adj[3] {{{1,5}, {2, 1}}, {{0, 5}, {2, 3}}, {{1, 3}, {0, 1}}};   // {node=index,{edge, weight}}  ==> 0-->1 wt:5, 0-->2 wt:1
    Solution ob;
    pair<int ,vector<pair<int, pair<int, int>>> > res = ob.spanningTree(V, adj);

    cout<<"Sum of Minimum Spanning Tree: "<< res.first << endl;
    cout<<"Minimum Spanning Tree: {Node, Edge, Weight}: "<< endl;
    for(auto it : res.second) {
        cout<<"{" << it.second.first <<", "<< it.second.second <<", "<< it.first <<"}";
    }
    return 0;
}