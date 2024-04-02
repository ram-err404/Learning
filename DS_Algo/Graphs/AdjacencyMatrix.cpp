// Graph: adjacency matrix:

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<bool> vis(n, false);
    stack<int> st;
    st.push(0);
    cout<<"DFS: ";
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node])
            cout<< node+1 <<" ";
        vis[node] = true;
        for(int i=0; i<n; i++) {
            if(node!=i && adj[node][i]==1 && !vis[i]) {
                st.push(i);
            }
        }
    }
    cout<<"\n";
}

void bfs(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    
    cout<<"BFS: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if(!vis[node])
            cout<< node+1 <<" ";
        vis[node] = true;
        
        for(int i=0; i<n; i++) {
            if(node!=i && adj[node][i]==1 && !vis[i]) {
                q.push(i);
            }
        }
    }
    cout<<"\n";
}

int main() {
    vector<vector<int>> adjMat {{0,1,1,0,0,0},{1,0,0,1,0,1},{1,0,0,1,0,1},{0,1,1,0,1,1},{0,0,0,1,0,1},{0,1,1,1,1,0}};
    
    dfs(adjMat);
    bfs(adjMat);
    return 0;
}