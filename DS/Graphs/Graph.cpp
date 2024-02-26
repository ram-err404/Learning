/* Graph implementation: */

#include <iostream>
#include "Graph.h"

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

  G.printGraph();
  std::cout<<"Find 4 from start_vertex 0 (using BFS): " << G.bfs(0, 4) << std::endl;
  std::cout<<"Find 0 from start_vertex 4 (using DFS): "<< G.dfs(4, 0) << std::endl;

  std::cout<<"Find 5 from start_vertex 0 (using BFS): "<< G.bfs(0, 5) << std::endl;
  std::cout<<"Find 1 from start_vertex 4 (using DFS): "<< G.dfs(4, 1) << std::endl;
  return 0;
}
