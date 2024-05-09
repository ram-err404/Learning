// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void createGraph(TreeNode* cur, unordered_map<int, vector<pair<int, char>>>& graph) {
        if(cur) {
            if(cur->left) {
                graph[cur->val].push_back({cur->left->val, 'L'});
                graph[cur->left->val].push_back({cur->val, 'U'});
                createGraph(cur->left, graph);
            }
            if(cur->right) {
                graph[cur->val].push_back({cur->right->val, 'R'});
                graph[cur->right->val].push_back({cur->val, 'U'});
                createGraph(cur->right, graph);
            }
        }
    }
    
    void dfs(int node, int dst, unordered_map<int, vector<pair<int, char>>>& graph, 
                map<int, bool>& vis, string& ans, string& res) {
        
        vis[node]=true;
        if(node==dst) {
            res=ans;
            return;
        }

        for(auto v : graph[node]) {
            if(!vis[v.first]) {
                ans.push_back(v.second);
                dfs(v.first, dst, graph, vis, ans, res);
                res.pop_back();
            }
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Need to create a graph out of this.
        unordered_map<int, vector<pair<int, char>>> graph;
        TreeNode* cur=root;

        createGraph(root, graph);   // Graph is ready.

        string res="";
        string ans="";
        int N=graph.size();
        
        map<int, bool> vis;     // visited
        for(auto it : graph) {
            vis[it.first]=false;
        }
        
        dfs(startValue, destValue, graph, vis, ans, res);
        return res;
    }
};

int main() {
    TreeNode* root=new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(3);
    
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    
    Solution ob;
    string res;
    res = ob.getDirections(root, 3, 6);
    
    cout<< res << endl;
    return 0;
}