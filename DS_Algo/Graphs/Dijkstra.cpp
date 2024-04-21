#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> distance(V, 2e5);

        distance[S] = 0;
        st.insert({0, S});
        
        while(st.size()) {
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto v:adj[node]) {
                if(dis+v[1] < distance[v[0]]) {
                    if(distance[v[0]] != 2e5) {
                        st.erase({distance[v[0]], v[0]});
                    }
                    distance[v[0]]=dis+v[1];
                    st.insert({distance[v[0]], v[0]});
                }
            }
        }
        return distance;
    }
};

int main() {
    vector<vector<int>> edges {{0,1,1}, {0,2,6}, {1,2,3}};
    int V=3, S=0;
    vector<vector<int>> adj[V];
    Solution ob;
    // edges: {{0,1,1}, {0,2,6}, {1,2,3}}
    for(auto e:edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    vector<int> dis = ob.dijkstra(V, adj, S);

    for(int x:dis)
        cout<< x <<" ";
    cout<< endl;

    return 0;
}