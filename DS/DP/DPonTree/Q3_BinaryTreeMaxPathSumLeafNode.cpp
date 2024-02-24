/*
Q3: Calculate maximum path sum from leaf node to leaf node. (Node values may be negative)
*/

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

struct node {
  struct node *left;
  struct node *right;
  int val;

  node(int x=0) {
    val = x;
    left = right = nullptr;
  }
};

struct node *root = nullptr;

void create_tree() {
  root = new node(10);
  root->left = new node(3);
  root->right = new node(12);
  
  root->left->left = new node(2);
  root->left->right = new node(20);
  
  root->left->right->left = new node(-5);
  root->left->right->right = new node(-6);
  
  root->right->left = new node(5);
  root->right->right = new node(6);
  
  root->right->left->left = new node(-4);
  
	root->right->right->left = new node(9);
	root->right->right->right = new node(10);

	root->right->right->left->left = new node(1);
	root->right->right->left->right = new node(3);
	
	root->right->right->right->left = new node(2);

	root->right->right->right->left->left = new node(-3);
	root->right->right->right->left->right = new node(4);

}

int solve(node *root, int &res) {
	if(root == nullptr)	return 0;

	int l=solve(root->left, res);
	int r=solve(root->right, res);

  int temp = max(l, r) + root->val;
  int ans = max(temp, l + r + root->val);
  res = max(res, ans);

  return temp;
}

int maxPathSumAnyToAnyNode(node *root) {
	int res = INT_MIN;

	solve(root, res);

	return res;
}

int main() {
  create_tree();
  
  cout<<"Max path sum from any node to any node in binary tree: "<< maxPathSumAnyToAnyNode(root) <<endl;
  return 0;
}
