// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        // We need to implement BFS here.
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> inner;

            for(int i=0; i<n; i++) {
                TreeNode *node = q.front();
                inner.push_back(node->val);
                q.pop();

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.push_back(inner);
        }
        return res;
    }
};

int main() {
    /*
        Input: root = [3,9,20,null,null,15,7]
        Output: [[3],[9,20],[15,7]]
    */
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution ob;
    vector<vector<int>> res = ob.levelOrder(root);

    cout<<"Output: [ ";
    for(int i=0; i<res.size(); i++) {
        cout<<"[ ";
        for(int j=0; j<res[i].size(); j++) {
            cout<< res[i][j] <<" ";
        }
        cout<<"] ";
    }
    cout<<" ]"<<endl;
    return 0;
}