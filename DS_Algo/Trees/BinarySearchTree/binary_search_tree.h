#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <iostream>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

/********************* Node class ***************************************/
/* Defining Node class for Binary tree. */
template <typename T>
class Node {
  T data;

public:
  Node<T>   *left, *right;
  T         get_data() const;
  void      set_data(T);
};
/* Functions of Node class. */
template <typename T>
T   Node<T> :: get_data() const {
  return data;
}
template <typename T>
void  Node<T> :: set_data(T x) {
  data  = x;
}
/************************* END of Node Class ****************************/



/************************* Binary Tree class ****************************/
template <typename T>
class BinarySearchTree {
  Node<T> *root;
  
  /* making create fn private so that we should not call it directly with object.
   * It should only be called when we need to insert any element to BT. */
  Node<T>*    create(T);
  /* No need to call these variant of functions directly, so making them private. */
  void        insert(Node<T>*, Node<T>*);
  void        print_tree(Node<T>*) const;
  Node<T>*    inorder_successor(Node<T>*) const;  // will be required in deletion.
  Node<T>*    remove(Node<T>*, T);        // this is the private variant of remove
  int         count_nodes(Node<T>*);
  int         height(Node<T>*);
public:
  /* Constructor. */
  BinarySearchTree();
  Node<T>*    get_root() const;
  void        print_tree() const;
  void        insert(T x);
  int         remove(T x);    //returns 1->FOUND, 0->NOT FOUND
  Node<T>*    search(T x, Node<T> *root) const;
  int         count_nodes();
  int         height();
};

/* Functions of Binary Tree. */

/* Constructor. */
template <typename T>
BinarySearchTree<T> :: BinarySearchTree() {
  root = nullptr;
}

/* Get root node of the binary tree. */
template <typename T>
Node<T>* BinarySearchTree<T> :: get_root() const {
  return root;
}

/************* Creating a Node for BST. ************************************/
/* create node object to insert to the binary tree. */
template <typename T>
Node<T>* BinarySearchTree<T> :: create(T x) {
  Node<T>  *ptr = new Node<T>();
  ptr->set_data(x);
  ptr->left   = nullptr;
  ptr->right  = nullptr;
  return ptr;
}

/************* Insert in a BST. ************************************/
/* Private: Recursive way to insert element to the binary tree. */
template <typename T>
void BinarySearchTree<T> :: insert(Node<T> *ptr, Node<T> *leaf) {
  if ( ptr->get_data() < leaf->get_data() ) {
    if(leaf->left)
      insert(ptr, leaf->left);
    else
      leaf->left = ptr;
  } else {
    if (leaf->right)
      insert(ptr, leaf->right);
    else
      leaf->right = ptr;  
  }
}

/* Insert node to the Binary Tree. */
template <typename T>
void  BinarySearchTree<T> :: insert(T x) {
  Node<T>  *ptr = create(x);
  /* Check for empty tree. */
  if (!root)
    root = ptr;
  else
    insert(ptr, root);
}

/************* Printing a BST. ************************************/
/* private: Print tree */
template <typename T>
void BinarySearchTree<T> :: print_tree(Node<T> *root) const {
  if(root) {
    std::cout << root->get_data() <<", ";
    print_tree(root->left);
    print_tree(root->right);
  }
}

template <typename T>
void BinarySearchTree<T> :: print_tree() const {
  print_tree(root);
  std::cout << "\n";
}

/************* Searching in a BST. ************************************/
template <typename T>
Node<T>*  BinarySearchTree<T> :: search(T x, Node<T> *root) const {
  /* If root is null or value is present at root. */
  if (!root || x == root->get_data()) 
    return root;

  // Key is less than root's key.
  if (x < root->get_data())
    return search(x, root->left);

  // Key is greater than root's key.
  return search(x, root->right);  
}

/************* Deletion in a BST. ************************************/
/* This will return inorder succerssor node of the tree. */
template <typename T>
Node<T>*  BinarySearchTree<T> :: inorder_successor(Node<T> *node) const {
  if (node && node->left)
    return inorder_successor(node->left);
  return node;
}

template <typename T>
Node<T>*  BinarySearchTree<T> :: remove(Node<T> *root, T key) {
  // base case 
  if (root == nullptr) return root; 

  // If the key to be deleted is smaller than the root's key, 
  // then it lies in left subtree 
  if (key < root->get_data()) 
    root->left = remove(root->left, key); 

  // If the key to be deleted is greater than the root's key, 
  // then it lies in right subtree 
  else if (key > root->get_data()) 
    root->right = remove(root->right, key); 

  // if key is same as root's key, then This is the node 
  // to be deleted 
  else {
    // node with only one child or no child 
    if (root->left == nullptr) { 
      Node<T> *temp = root->right; 
      delete root;
      return temp; 
    } else if (root->right == nullptr) { 
      Node<T>   *temp = root->left; 
      delete root; 
      return temp; 
    }

    // node with two children: Get the inorder successor (smallest 
    // in the right subtree) 
    Node<T> *temp = inorder_successor(root->right); 

    // Copy the inorder successor's content to this node 
    // root->data = temp->data;
    root->set_data(temp->get_data());

    // Delete the inorder successor 
    root->right = remove(root->right, temp->get_data()); 
  } 
  return root; 
}

template <typename T>
int BinarySearchTree<T> :: remove(T x) {
  if(!search(x, root))
    return 0;

  if (!root)
    return 0;
  
  root = remove(root, x);   // This is the private variant of remove.
  return 1;
}

/******* Count Nodes of the binary tree. ***********/
template <typename T>
int BinarySearchTree<T> :: count_nodes(Node<T>  *root) {
  if(!root) 
    return 0;
  return (1 + count_nodes(root->left) + count_nodes(root->right));
}

template <typename T>
int BinarySearchTree<T> :: count_nodes() {
  if(!root) 
    return 0;
  return (1 + count_nodes(root->left) + count_nodes(root->right));
}

template <typename T>
int BinarySearchTree<T> :: height(Node<T> *root) {
  if(!root) // considering root height as 0.
    return -1;
  return (1 + MAX(height(root->left), height(root->right)) );
}

template <typename T>
int BinarySearchTree<T> :: height() {
  return height(root);
} 
/************************* Binary Tree class ends ***********************/

#endif
