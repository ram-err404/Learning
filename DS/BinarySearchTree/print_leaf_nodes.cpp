#include "binary_search_tree.h"
#include <string>

template <typename T>
void print_leaf_node(const Node<T> *ptr) {
  if(!ptr)
    return ;
  if(ptr && ptr->left==nullptr && ptr->right==nullptr)
    std::cout<< ptr->get_data() <<", ";
  print_leaf_node(ptr->left);
  print_leaf_node(ptr->right);
}

int main() {
  BinarySearchTree<std::string>   bt;
  bt.insert("ramji");
  bt.insert("misra");
  bt.insert("shivaji misra");
  bt.insert("shiva");
  bt.insert("Shivaji");
  bt.insert("Bhanu");
  bt.print_tree();

  std::cout<<"Printing leaf nodes:" << std::endl;
  print_leaf_node(bt.get_root());
  std::cout <<"\n";
  bt.remove("ramji");
  bt.print_tree();
  print_leaf_node(bt.get_root());
  std::cout <<"\n";
  return 0;
}
