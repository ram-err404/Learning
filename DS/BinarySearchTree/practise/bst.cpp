#include <iostream>
using namespace std;

typedef struct node{
  int     data;
  node    *left, *right;
} node_t;

node_t*   create(int x) {
  node_t  *ptr = new node_t;
  ptr->data = x;
  ptr->left = nullptr;
  ptr->right = nullptr;
  return ptr;
}

node_t*   insert(int x, node_t *root) {
  if(!root)
    root = create(x);
  else if (x < root->data)
    root->left = insert(x, root->left);
  else
    root->right = insert(x, root->right);
  
  return root;
}

void      print_tree(node_t *root) {
  if(root) {
    cout << root->data <<", ";
    print_tree(root->left);
    print_tree(root->right);
  } 
}

node_t*   search(int x, node_t  *root) {
  if(!root)   return root;  //this is null.
  else if(x < root->data)
    return search(x, root->left);
  else if (x > root->data)
    return search(x, root->right);
  else
    return root;  // value is found.
}

node_t*   inorder_successor(node_t  *root) {
  if(root && root->left)
    return inorder_successor(root->left);
  return root;
}

node_t*   remove(int x, node_t  *root) {
  if (!root)  return root;  // this will be null.
  else if (x < root->data)
    root->left = remove(x, root->left);
  else if (x > root->data)
    root->right = remove(x, root->right);
  else {  // Node to be deleted has been found
    // Case 1: Node to be deleted has only 1 child or no child.
    if (!root->left) {
      node_t  *temp = root->right;  // this maybe null also for 0 child.
      delete root;
      return temp;
    } else if (!root->right) {
      node_t  *temp = root->left; // I came here means, left definately exist.
      delete root;
      return temp;
    } else {
      // case 2: Node to be deleted has 2 child. Find inorder_successor.
      node_t  *temp = inorder_successor(root->right);
      root->data = temp->data;
      root->right = remove(temp->data, root->right);  // delete inorder_successor.
    }
  }
  return root;  // data not found.
}

int main() {
  node_t  *root = nullptr;
  root = insert(30, root);
  insert(10, root);
  insert(20, root);
  insert(50, root);
  insert(40, root);
  insert(60, root);
  insert(20, root);
  insert(50, root);
  insert(40, root);
  insert(60, root);

  print_tree(root);
  node_t  *temp = search(40, root);
  if(temp)  cout <<"\n" << temp->data << " found" << endl;
  else      cout << "\nValue not found" << endl;

  temp = search(100, root);
  if(temp)  cout << temp->data << "found" << endl;
  else      cout << "Value not found" << endl;
  
  remove(50, root); 
  print_tree(root);
  cout<<"\n"; 
  remove(30, root); 
  print_tree(root);
  cout<<"\n"; 
  remove(50, root); 
  print_tree(root);
  cout<<"\n"; 
  
  return 0;
}
