#include<bits/stdc++.h>
using namespace std;


/**
 * Leetcode Q: 543| https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode    *left, *right;
};

class Solution {
public:
    int solve(TreeNode *root, int &res) {
        if(root == nullptr)
            return 0;
        
        int l=solve(root->left, res);
        int r=solve(root->right, res);
        
        int temp=1+max(l,r);
        res=max(res, l+r);
        
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        
        solve(root, res);
        return res;
    }
};


int main() {

    return 0;
}