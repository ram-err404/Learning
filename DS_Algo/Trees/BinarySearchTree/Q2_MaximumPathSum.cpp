// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
private:
    int solve(TreeNode *root, int &res) {
        if(!root)   return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(root->val + max(l, r), root->val);
        int ans = max(temp, root->val + l + r);
        res = max(ans, res);

        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root, res);
        return res;
    }
};

int main() {
    TreeNode *root = nullptr;
    root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution ob;
    cout <<"Maximum Path Sum: "<< ob.maxPathSum(root) << endl;
    return 0;
}