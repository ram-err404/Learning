// Build tree from given preorder. 
// preorder will have some values and will have 'L' for all the leaves.

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    char val;   // 'I': internal Node, 'L': Leaf node.
    TreeNode *left, *right;
    TreeNode(char c) {
        val=c;
        left = right = nullptr;
    }
};

class Solution {
    int n=0;
    TreeNode* buildTreePreorder(const string &preorder, int& i) {
        if(i<n) {
            TreeNode* node = new TreeNode(preorder[i]);
            if(preorder[i]=='L' || preorder[i]=='l')
                return node;
            
            node->left = buildTreePreorder(preorder, ++i);
            node->right = buildTreePreorder(preorder, ++i);
            return node;
        }
        return nullptr;
    }
public:
    TreeNode* buildTreePreorder(const string &preorder) {
        n=preorder.size();
        if(n==0)    return nullptr;
        
        int i=0;
        return buildTreePreorder(preorder, i);
    }
};

void printTree(TreeNode* root) {
    if(root) {
        cout << root->val <<" ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    string preorder = "ALBCDLlEll";
    Solution ob;
    TreeNode *root = ob.buildTreePreorder(preorder);
    
    printTree(root);
    return 0;
}
