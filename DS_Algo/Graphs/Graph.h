/* Graph Library: */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

struct Edge {
  int start_ver, end_ver, cost;

  Edge(int s, int e, int c) {
    start_ver=s;
    end_ver=e;
    cost=c;
  }
};

class Graph {
  public:
    int N;
    std::vector<std::list<Edge*>> adj;

    Graph(int V) {
      N=V;
      adj.resize(N);
    }

    void addEdge(int, Edge*);
    void printGraph();

    bool bfs(int, int);
    bool dfs(int, int);
};

void Graph::addEdge(int vertex, Edge *e) {
  adj[vertex].push_back(e);
}

void Graph::printGraph() {
  for(int i=0; i<N; i++) {
    std::cout<<"Vertex "<< i <<": Edges: (star_ver, end_ver, cost): ";
    for(Edge *e:adj[i]) {
      std::cout<<"("<< e->start_ver <<", "<< e->end_ver <<", "<< e->cost <<") \t";
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";
}

bool Graph::bfs(int start_ver, int target) {
  std::vector<bool>  visited(N, false);
  std::queue<int> q;

  q.push(start_ver);
  visited[start_ver] = true;

  while(!q.empty()) {
    int vertex = q.front();
    q.pop();

    if(target == vertex)  return true;
    for(Edge *e:adj[vertex]) {
      if(!visited[e->end_ver]) {
        visited[e->end_ver] = true;
        q.push(e->end_ver);
      }
    }
  }
  return false;
}

bool Graph::dfs(int start_ver, int target) {
  std::vector<int> visited(N, false);
  std::stack<int> s;

  s.push(start_ver);
  visited[start_ver] = true;

  while(!s.empty()) {
    int vertex = s.top();
    s.pop();

    if(target == vertex)  return true;
    for(Edge *e:adj[vertex]) {
      if(!visited[e->end_ver]) {
        visited[e->end_ver] = true;
        s.push(e->end_ver);
      }
    }
  }
  return false;
}

#endif
