// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return nullptr;
        int curVal = root->val;
        if(p->val < curVal && q->val < curVal)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > curVal && q->val > curVal)
            return lowestCommonAncestor(root->right, p, q); 
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right;
    Solution ob;
    TreeNode *res = ob.lowestCommonAncestor(root, p, q);
    cout<<"Lowest Common Ancestor of "<< p->val <<" and " << q->val <<" is: " << res->val <<endl;
    return 0;
}