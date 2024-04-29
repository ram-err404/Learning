// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int poStart, int poEnd, unordered_map<int, int>& mp) {
        
        if(inStart > inEnd || poStart > poEnd)  return nullptr;

        TreeNode* node = new TreeNode(postorder[poEnd]);
        int index = mp[postorder[poEnd]];
        int len = index-inStart;

        node->left = buildTree(inorder, inStart, index-1, postorder, poStart, poStart+len-1, mp);
        node->right = buildTree(inorder, index+1, inEnd, postorder, poStart+len, poEnd-1, mp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = nullptr;
        unordered_map<int, int> mp;
        int n=inorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(inorder, 0, n-1, postorder, 0, n-1, mp);
    }
};

void preorderTraversal(TreeNode* root) {
    if(root) {
        cout<< root->val <<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    vector<int> inrorder {9,3,15,20,7};
    vector<int> postorder {9,15,7,20,3};

    Solution ob;
    TreeNode *root = ob.buildTree(inrorder, postorder);

    preorderTraversal(root);
    return true;
}