// https://leetcode.com/problems/subtree-of-another-tree/

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

bool ans = false;

class Solution {
private:
    bool match(TreeNode* root, TreeNode* subRoot) {
        if(root && subRoot) {
            bool left = match(root->left, subRoot->left);
            bool right = match(root->right, subRoot->right);

            if(root->val == subRoot->val && left && right)
                return true;
            else 
                return false;
        } else if(!root && !subRoot) {
            return true;
        } else {
            return false;
        }
    }
    void inorderTraverse(TreeNode *root, TreeNode *subRoot) {
        if(root) {
            inorderTraverse(root->left, subRoot);
            bool temp = match(root, subRoot);
            if(temp) {
                ans = temp;
            }
            inorderTraverse(root->right, subRoot);
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorderTraverse(root, subRoot);
        return ans;
    }
};

int main() {
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = nullptr;
    subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution ob;
    cout << boolalpha;
    ans = ob.isSubtree(root, subRoot);
    cout << ans << endl;
    return 0;
}