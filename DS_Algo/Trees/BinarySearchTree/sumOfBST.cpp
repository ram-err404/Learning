#include "binary_search_tree.h"

template <typename T>
T sumOfBT(Node<T>  *ptr) {
  if (ptr) {
    return ( ptr->get_data() + 
        sumOfBT(ptr->left) +
        sumOfBT(ptr->right) );
  }
  else
    return 0;
}

int main() {
  BinarySearchTree<double>   bt;
  bt.insert(10.50);
  bt.insert(20.20);
  bt.insert(30.14);
  bt.insert(50.94);
  bt.insert(40.32);
  bt.insert(4.50);
  bt.print_tree();
  
  std::cout << sumOfBT(bt.get_root()) << std::endl;
  double x = 30.14;
  Node<double> *res_ptr = bt.search(x, bt.get_root());
  if(res_ptr)
    std::cout <<"Value found: " << res_ptr->get_data() << std::endl;
  else
    std::cout << x <<"Not found in the BST." << std::endl;
  return 0;
}
