#include "binary_search_tree.h"
#include <map>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
void getVerticalOrder(Node<T> *root, 
                        int hd, 
                        map<int, vector<T>> &m) {
  if(root) {
    m[hd].push_back(root->get_data());
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
  }
  return;
}

template <typename T>
map<int, vector<char>>  createVerticalOrderMap(Node<T>* root) {
  map<int, vector<char>>  verticalOrderMap; // key--> hd, value--> vector of elements at that hd.
  int   hd = 0;   // initially horizontal distance for root is 0, for left, hd-1 and right, hd+1.

  getVerticalOrder(root, hd, verticalOrderMap);

  return verticalOrderMap;
}

// print in the vertical order.
template <typename T>
void print_vertical_order(const map<int, vector<T>> &m) {
  // Traverse the map and print nodes at every horigontal 
  // distance (hd)
  // map< int,vector<char> > :: iterator it; 
  for (auto it=m.begin(); it!=m.end(); it++) { 
    for (size_t i=0; i<it->second.size(); ++i) 
      cout << it->second[i] << " "; 
    cout << endl; 
  }
  cout<<"\n";
}

// printing the top view of the tree.
template <typename T>
void topView(const map<int, vector<T>> &m) {
  for(auto itr=m.begin(); itr!=m.end(); ++itr)
    cout << itr->second[0] <<" ";
  cout<<"\n";
}

int main() {
  BinarySearchTree<char>  bst;
  bst.insert('F');
  bst.insert('D');
  bst.insert('I');
  bst.insert('B');
  bst.insert('E');
  bst.insert('A');
  bst.insert('C');
  bst.insert('H');
  bst.insert('G');
  bst.insert('K');
  bst.insert('J');
  bst.insert('L');
  bst.insert('M');
  bst.print_tree();
  
  cout<<"\nVerticalOrder Traversal: " << endl;
  map<int, vector<char>> verticalOrderTraversalMap = createVerticalOrderMap(bst.get_root());
  // printing the vertical order.
  print_vertical_order(verticalOrderTraversalMap);

  cout<<"TopView of the Tree: " << endl;
  topView(verticalOrderTraversalMap);
}
