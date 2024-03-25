#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
    
    Node(int _val) {
        val = _val;
        left = right = nullptr;
    }
};

Node* insertBST(Node *root, int x) {
    if(!root)   return root=new Node(x);
    
    if(x > root->val)
        root->right = insertBST(root->right, x);
    else
        root->left = insertBST(root->left, x);
    return root;
}

// Rt L R
void preorderTraversal(Node *root) {
    if(!root)   return;
    
    cout<< root->val <<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// L Rt R
void inorderTraversal(Node *root) {
    if(!root)   return;
    
    inorderTraversal(root->left);
    cout<< root->val <<" ";
    inorderTraversal(root->right);
}

// L R Rt
void postorderTraversal(Node *root) {
    if(!root)   return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<< root->val <<" ";
}

int heightOfTree(Node *root) {
    if(!root)   return 0;
    
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

void printAllLeafs(Node *root) {
    if(!root)   return;
    
    if(!root->left && !root->right)
        cout<< root->val <<" ";
    
    printAllLeafs(root->left);
    printAllLeafs(root->right);
}

int main() {
    vector<int> vec {20,10,1,2,3,64,7,4,3,2,1,89,65,80};
    Node *root=nullptr;
    int n = vec.size();

    for(int i=0; i<n; i++) {
        root = insertBST(root, vec[i]);
    }

    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<"\nInorder Traversal: ";
    inorderTraversal(root);
    cout<<"\nPostorder Traversal: ";
    postorderTraversal(root);
    
    cout<<"\nHeight of the tree: "<< heightOfTree(root) <<endl;
    cout<<"\nAll leafs: ";
    printAllLeafs(root);

    return 0;
}