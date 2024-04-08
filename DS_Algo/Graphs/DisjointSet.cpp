#include <iostream>
#include <vector>
#include "disjointset.h"
using namespace std;

int main() {
    DisjointSet dsu(7);
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