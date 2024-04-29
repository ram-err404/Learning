#include<bits/stdc++.h>
using namespace std;

#define max(a,b)  (a>b?a:b)

struct Node{
    int data;
    Node *left, *right;
    
    Node(int val) {
        data=val;
        left=right=nullptr;
    }
};
Node *root=nullptr;

Node* insert(Node *root, int val) {
    if(!root) root=new Node(val);
    else if(val<root->data)
        root->left=insert(root->left, val);
    else
        root->right=insert(root->right, val);
    
    return root;
}

void inorder_bst(Node *root) {
    if(root){
        inorder_bst(root->left);
        cout << root->data<<" ";
        inorder_bst(root->right);
    }
}

void print_leaves(Node *root) {
    if(!root)   return;
    if(root->left==nullptr && root->right==nullptr)
        cout<<root->data<<" ";
    
    print_leaves(root->left);
    print_leaves(root->right);
}

bool search(Node *root, int x) {
    if(root) {
        if(x==root->data)
            return true;
        else if(x<root->data)
            return search(root->left, x);
        else
            return search(root->right, x);
    }
    return false;
}

int bst_sum(Node *root) {
    if(root) {
        return root->data + bst_sum(root->left) + bst_sum(root->right);
    }
    return 0;
}

int bst_height(Node *root) {
  if(!root) return -1;
  return 1+max(bst_height(root->left), bst_height(root->right));
}

void topView(Node *root) {
    if(!root)   return;
    
    map<Node*, int> hd;
    map<int, int> topViewMap;
    queue<Node*> q;
    Node *temp=root;
    
    q.push(temp);
    hd[temp]=0;
    topViewMap[hd[temp]]=temp->data;
    
    while(!q.empty()) {
        if(temp->left) {
            hd[temp->left]=hd[temp]-1;
            if(!topViewMap[hd[temp->left]])
                topViewMap[hd[temp->left]]=temp->left->data;
            q.push(temp->left);
        }
        if(temp->right){
            hd[temp->right]=hd[temp]+1;
            if(!topViewMap[hd[temp->right]])
                topViewMap[hd[temp->right]]=temp->right->data;
            q.push(temp->right);
        }
        q.pop();
        if(q.size())    temp=q.front();
    }
    
    for(auto itr:topViewMap)
        cout<<itr.second<<" ";
    cout<<"\n";
}

void print_vertical_order(Node *root) {
    map<int, vector<int>> m;
    map<Node*, int> hd;
    queue<Node*> q;
    Node *temp=root;
    
    q.push(temp);
    hd[temp]=0;
    m[hd[temp]].push_back(temp->data);
    
    while(!q.empty()) {
        if(temp->left) {
            hd[temp->left]=hd[temp]-1;
            m[hd[temp->left]].push_back(temp->left->data);
            q.push(temp->left);
        }
        if(temp->right) {
            hd[temp->right]=hd[temp]+1;
            m[hd[temp->right]].push_back(temp->right->data);
            q.push(temp->right);
        }
        q.pop();
        if(q.size())    temp=q.front();
    }
    
    for(auto itr:m){
        for(int item:itr.second)
            cout<<item<<" ";
        cout<<"\n";
    }
}

int main() {
    root=insert(root, 12);
    insert(root, 8);
    insert(root, 15);
    insert(root, 10);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 20);
    insert(root, 14);
    insert(root, 18);
    insert(root, 10);
    
    inorder_bst(root);
    
    cout<<"\n"<<search(root, 9)<<endl;
    cout<<search(root, 14)<<endl;
    cout<<search(root, 18)<<endl;
    cout<<search(root, 23)<<endl;
    
    cout<<"Sum of bst: "<<bst_sum(root)<<endl;
    cout<<"Leaves: "; print_leaves(root); cout<<"\n";
    
    cout<<"Top View: "; topView(root); cout<<"\n";
    cout<<"Vertical Order: \n"; print_vertical_order(root); cout<<"\n";

    cout<<"Height of BST: "<<bst_height(root)<<endl;

    return 0;
}
