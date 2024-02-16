#include <iostream>
using namespace std;

class Node{
public:
  int   data;
  Node  *left;
  Node  *right;
  Node(int val) {
    data=val;
    left=right=nullptr;
  }
};

void print_tree(Node  *root) { // InOrder
  if(root) {
    cout << root->data <<" ";
    print_tree(root->left);
    print_tree(root->right);
  }
}

Node* search(Node *root, int data) {
  if(!root)     return nullptr;
  if(data == root->data)
    return root;
  if(data < root->data)
    return search(root->left, data);
  return search(root->right, data);
}

Node* insert(Node *root, int data) {
  if(!root)
    root=new Node(data);
  else if(data<root->data)
    root->left=insert(root->left, data);
  else
    root->right=insert(root->right, data);
  return root;
}

Node*   inorder_successor(Node *root) {
  if(!root)
    return nullptr;
  else if(root->left)
    return inorder_successor(root->left);
  return root;
}

Node* remove(Node *root, int data) {
  if(!root)
    return nullptr;;
  if(data<root->data)
    root->left=remove(root->left, data);
  else if(data>root->data)
    root->right=remove(root->right, data);
  else{ // Node to be deleted found.
    // Case 1: Node to be deleted has 0 or 1 child.
    if(!root->left) {
      Node  *temp=root->right;
      delete root;
      return temp;
    }else if(!root->right) {
      Node  *temp=root->left;
      delete root;
      return temp;
    }
    // case 2: Node has 2 child. Find the inorder successor and delete.
    Node *temp=inorder_successor(root->right);
    root->data=temp->data;
    root->right=remove(root->right, temp->data);  // delete inorder_successor.
  }
  return root;
}

int main() {
  Node  *root = nullptr;
  root = insert(root, 30);
  insert(root, 10);
  insert(root, 20);
  insert(root, 50);
  insert(root, 40);
  insert(root, 60);
  insert(root, 20);
  insert(root, 50);
  insert(root, 40);
  insert(root, 60);

  print_tree(root);
  Node  *temp = search(root, 40);
  if(temp)  cout <<"\n" << temp->data << " found" << endl;
  else      cout << "\n40 not found" << endl;

  temp = search(root, 100);
  if(temp)  cout << temp->data << "found" << endl;
  else      cout << "100 not found" << endl;
  
  cout<<"Deleting 50: ";
  remove(root, 50); 
  print_tree(root);
  cout<<"\n"; 
  cout<<"Deleting 30: ";
  remove(root, 30); 
  print_tree(root);
  cout<<"\n"; 
  cout<<"Deleting 50: ";
  remove(root, 50);
  print_tree(root);
  cout<<"\n"; 

  return 0;
}
