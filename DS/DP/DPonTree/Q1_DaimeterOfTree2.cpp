// Dp on Tree:

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

struct node {
  struct node *left;
  struct node *right;
  int data;

  node() {
    data = 0;
    left = right = nullptr;
  }
};

struct node *root = nullptr;

void create_tree() {
  root = new node();
  root->left = new node();
  root->right = new node();
  
  root->left->left = new node();
  root->left->right = new node();
  
  root->left->left->left = new node();
  
  root->left->right->left = new node();
  root->left->right->right = new node();
  
  root->left->right->left->left = new node();
  
  root->left->right->right->left = new node();
  root->left->right->right->right = new node();
  
  root->left->right->right->right->left = new node();
  root->left->right->right->right->right = new node();
  
  root->left->right->right->right->right->right = new node();
}

int diameterOfTree(node *root, int &res) {
  // Base Condition
  if(root == nullptr) return 0;
  
  // Hypothesis
  int l = diameterOfTree(root->left, res);
  int r = diameterOfTree(root->right, res);
  
  // Induction
  /* calculate the height of the temp node. We may need to pass temp's height to above node. */
  int temp = 1 + max(l, r);
  
  /* temp could also be the answer. Like the max height could go from temp only. */
  int ans = max(temp, 1+l+r); // need to check if temp is greater than the sum of l,r,1 (i.e. current node).
  
  res = max(ans, res);
  
  return temp;
}

int main() {
  create_tree();
  
  int res=INT_MIN;
  
  diameterOfTree(root, res);
  
  cout<<"Diameter of the tree: "<< res <<endl;
  return 0;
}
