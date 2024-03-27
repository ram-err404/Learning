#include "binary_search_tree.h"

int main() {
  BinarySearchTree<int>   bt;
  std::cout <<"Number of nodes in BST: " << bt.count_nodes() << std::endl;
  bt.insert(50);
  bt.insert(30);
  bt.insert(70);
  bt.insert(20);
  bt.insert(40);
  bt.insert(60);
  bt.insert(80);
  std::cout <<"Original Tree: ";    bt.print_tree();
  std::cout <<"Number of nodes in BST: " << bt.count_nodes() << std::endl;
  
  std::cout <<"\nDeleting 20: " << (bt.remove(20) ? "Deleted" : "Not found")<< std::endl;
  std::cout <<"Tree: ";             bt.print_tree();
  std::cout << "Deleting 30: " << (bt.remove(30) ? "Deleted" : "Not found")<< std::endl;
  std::cout <<"Tree: ";             bt.print_tree();
  std::cout << "Deleting 50: " << (bt.remove(50) ? "Deleted" : "Not found")<< std::endl;
  std::cout <<"Tree: ";             bt.print_tree();
  std::cout << "Deleting 11: " << (bt.remove(11) ? "Deleted" : "Not found")<< std::endl;
  std::cout <<"Tree: ";             bt.print_tree();
  
  std::cout <<"\nNumber of nodes in BST: " << bt.count_nodes() << std::endl;
  std::cout <<"\nHeight of BST: " << bt.height() << std::endl;
  return 0;
}
