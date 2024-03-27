// BFS and DFS traversal in directed graph

// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Edge {
    int start_ver, end_ver, cost;
    
    Edge(int s, int e, int c) {
        start_ver=s;    end_ver=e;  cost=c;
    }
};

class Graph {
    int N;  // No. of vertices.
    // Adjacency List
    vector<list<Edge*>> adj;
public:
    
    Graph(int V);
    void addEdge(int vertex, Edge *edge);
    void print_graph();
    
    void BFS_traversal(int start_vertex);
    void DFS_traversal(int start_vertex);
};

Graph::Graph(int V) {
    this->N=V;
    adj.resize(V);
}

void Graph::addEdge(int vertex, Edge *edge) {
    adj[vertex].push_back(edge);    // Add an edge to the given vertex.
}

void Graph::print_graph() {
    for(int i=0; i<this->N; i++) {
        cout<<"\nvertex "<<i<<": ";
        for(Edge *edge:adj[i])
            cout<<"("<<edge->start_ver<<", "<<edge->end_ver<<", "<<edge->cost<<"), ";
    }
}

void Graph::BFS_traversal(int start_vertex) {
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(this->N,false);
    
    queue<int> q;
    q.push(start_vertex);
    // Mark the current node as visited and enqueue it
    visited[start_vertex] = true;
    
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        
        for(Edge *x:adj[v]) {
            if(!visited[x->end_ver]) {
                visited[x->end_ver]=true;
                q.push(x->end_ver);
            }
        }
    }
}

void Graph::DFS_traversal(int start_vertex) {
    vector<int> visited{this->N, false};
    
    stack<int> s;
    
    s.push(start_vertex);
    visited[start_vertex]=true;
    
    while(!s.empty()) {
        int top=s.top();
        s.pop();
        
        cout<<top<<" ";
        
        for(Edge *x:adj[top]) {
            if(!visited[x->end_ver]) {
                visited[x->end_ver]=true;
                s.push(x->end_ver);
            }
        }
    }
}

int main() {
    Graph G(6);
    
    G.addEdge(0, new Edge(0,1,5));
    G.addEdge(0, new Edge(0,2,4));
    G.addEdge(0, new Edge(0,3,3));
    G.addEdge(1, new Edge(1,2,6));
    G.addEdge(2, new Edge(2,5,5));
    G.addEdge(2, new Edge(2,3,3));
    G.addEdge(3, new Edge(3,1,5));
    G.addEdge(3, new Edge(3,2,6));
    G.addEdge(4, new Edge(4,1,7));
    G.addEdge(4, new Edge(4,5,8));
    G.addEdge(4, new Edge(4,2,9));
    G.addEdge(4, new Edge(4,3,1));
    G.addEdge(5, new Edge(5,1,2));
    G.addEdge(5, new Edge(5,2,3));
    G.addEdge(5, new Edge(5,3,4));
    
    G.print_graph();
    cout<<"\nBFS_traversal from start_vertex 0 \n";
    G.BFS_traversal(0);
    
    cout<<"\nDFS_traversal from start_vertex 4 \n";
    G.BFS_traversal(4);
    
    return 0;
}
