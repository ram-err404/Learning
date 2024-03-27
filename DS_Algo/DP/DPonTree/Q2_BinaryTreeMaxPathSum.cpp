/*  https://leetcode.com/problems/binary-tree-maximum-path-sum/
    Q 124: Binary Tree Maximum Path Sum.

    We have to calculate the maximum path sum from any node to any node.
*/

/**
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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int solve(TreeNode* root,int& res){
        if(root==nullptr) return 0;

        int l=solve(root->left,res);
        int r=solve(root->right,res);

        int temp=max(max(l,r)+root->val,root->val);
        int ans=max(temp,l+r+root->val);
        res=max(res,ans);

        return temp;
    }
    int maxPathSum(TreeNode* root){
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};
