// BST
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    
    Node(int val) {
        data=val;
        left=right=nullptr;
    }
};

Node* insert(Node *root, int val) {
    if(!root)   root=new Node(val);
    else if(val<root->data)
        root->left=insert(root->left, val);
    else
        root->right=insert(root->right, val);
    // Finally return the root;
    return root;
}

void printInorder(Node *root) {
    if(root) {
        printInorder(root->left);
        std::cout << root->data << " ";
        printInorder(root->right);
    }
}

int search(Node *root, int target) {
    if(root) {
        if(root->data==target)
            return 1;
        else if(target<root->data)
            search(root->left, target);
        else
            search(root->right, target);
    } else {
        return -1;
    }
}

Node* inorderSuccessor(Node *root) {
    if(root && root->left)   
        return inorderSuccessor(root->left);
    return root;
}

Node* delNode(Node *root, int val) {
    if(!root) return root;
    
    if(val < root->data)
        root->left = delNode(root->left, val);
    else if(val > root->data)
        root->right = delNode(root->right, val);
    else {
        // There could be 2 cases here.
        // 1.) Node with 1 or no child
        if(!root->left) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if(!root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        // 2.) Node with 2 childrens. Get the inorder successor.
        Node *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = delNode(root->right ,temp->data);
    }
    return root;
}

int main() {
    Node *root=nullptr;
    root = insert(root, 12);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 11);
    insert(root, 15);
    insert(root, 25);
    
    printInorder(root);
    if(search(root, 15)==-1) {
        cout<<"Not Found"<<endl;
    } else {
        cout<<"Found"<<endl;
    }
    
    root = delNode(root, 12);
    printInorder(root);
    return 0;
}