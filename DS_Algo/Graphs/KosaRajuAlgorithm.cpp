#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node]=true;
        for(int v:adj[node]) {
            if(!vis[v]) {
                dfs1(v, adj, vis, st);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>& graph, vector<bool>& vis,
                vector<int>& temp) {
        vis[node]=true;
        temp.push_back(node);
        for(int v:graph[node]) {
            if(!vis[v]) {
                dfs2(v, graph, vis, temp);
            }
        }
    }
    void printStronglyConnectedComponents(vector<vector<int>>& res) {
        cout<<"=== Strongly Connected Components ==="<<endl;
        for(auto nodes:res) {
            for(int v : nodes) {
                cout<< v <<" ";
            }
            cout<< endl;
        }
        cout<<"========================="<<endl;
    }
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }
        
        vector<vector<int>> graph(V);
        // Now reverse the edges.
        for(int u=0; u<V; u++) {
            for(int v:adj[u]) {
                graph[v].push_back(u);
            }
        } // graph is reversed now.
        
        // Now do a dfs walk and find the number of Strongle connected components.
        for(int i=0; i<V; i++) {
            vis[i]=false;
        }
        
        int count=0;
        vector<vector<int>> res;
        
        while(!st.empty()) {
            int node=st.top();
            st.pop();
            
            if(!vis[node]) {
                vector<int> temp;
                dfs2(node, graph, vis, temp);
                res.push_back(temp);
                count++;
            }
        }
        // print the strongly connected components
        printStronglyConnectedComponents(res);
        return count;
    }
};

int main()
{
/*
5 5
1 0
0 2
2 1
0 3
3 4
*/
    int V=5, E=5;
    // cin >> V >> E;
    vector<pair<int, int>> edges {{1,0}, {0,2}, {2,1}, {0,3}, {3,4}}; 
    vector<vector<int>> graph(V);

    for(int i=0; i<E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        // cin >> u >> v;
        graph[u].push_back(v);
    }
    Solution ob;
    int count = ob.kosaraju(V, graph);
    cout <<"Number of Strongly Connected Components: " << count << endl;
    return 0;
}
