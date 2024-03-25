// https://leetcode.com/problems/invert-binary-tree/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return root;
        
        // Swap the left and right vals.
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }

    void preorderTree(TreeNode* root) {
        if(root) {
            cout<< root->val <<" ";
            preorderTree(root->left);
            preorderTree(root->right);
        }
    }
};

int main() {
    TreeNode *root = nullptr;

    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left = new TreeNode(9);

    Solution ob;
    root = ob.invertTree(root);
    ob.preorderTree(root);
    return 0;
}