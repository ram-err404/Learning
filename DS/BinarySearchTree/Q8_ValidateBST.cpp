// https://leetcode.com/problems/validate-binary-search-tree/description/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isValidBST(TreeNode* root, long mn, long mx) {
        if(!root)   return true;

        if(root->val <= mn || root->val >= mx)
            return false;
        
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
public:
    bool isValidBST(TreeNode* root) {
       /* The idea here is to validate if root lies int the given range or not. */
       return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    TreeNode *root = new TreeNode(13);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(12);
    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(17);
    root->right->right->left = new TreeNode(16);

    Solution ob;
    cout << boolalpha << ob.isValidBST(root) << endl;
    return 0;
}