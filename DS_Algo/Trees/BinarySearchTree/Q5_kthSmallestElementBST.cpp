// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
private:
    void inorderTraversal(TreeNode *root, int &count, int &ans, int k) {
        if(root) {
            inorderTraversal(root->left, count, ans, k);
            count++;
            if(count == k) {
                ans = root->val;
                return;
            }
            inorderTraversal(root->right, count, ans, k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        /*  We know the inorder traversal gives us the smallest elements of the tree. (In ascending order).
        */
        int count=0, ans=0;
        inorderTraversal(root, count, ans, k);
        
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution ob;
    int ans = ob.kthSmallest(root, 4);
    cout<< ans << endl;
    return 0;
}