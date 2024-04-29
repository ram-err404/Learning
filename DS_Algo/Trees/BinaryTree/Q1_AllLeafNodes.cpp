// Find leaves of binary Tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int _val) {
        val=_val;
        left = right = nullptr;
    }
};

class Solution {
    int dfs(TreeNode* root, int layer, vector<vector<int>>& res) {
        if(!root)   return 0;
        
        int left = dfs(root->left, layer, res);
        int right = dfs(root->right, layer, res);
        
        layer = max(left, right);
        if(layer+1 > res.size()) {
            res.resize(layer+1);
        }
        res[layer].push_back(root->val);
        
        return layer+1;
    }
public:
    vector<vector<int>> findAllLeaves(TreeNode* root) {
        vector<vector<int>> res;
        int layer=0;
        
        dfs(root, layer, res);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution ob;
    vector<vector<int>> res = ob.findAllLeaves(root);
    
    cout<<"[";
    for(auto vec:res) {
        cout<<" [ ";
        for(int x:vec)
            cout<< x <<" ";
        cout<<"] ";
    }
    cout<<"]" << endl;
    return 0;
}
