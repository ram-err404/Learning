#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

Node *root=nullptr;

Node* insert(Node *root, int x) {
    if(!root) root=new Node(x);
    else if(x<root->data)
        root->left=insert(root->left, x);
    else
        root->right=insert(root->right, x);
    
    return root;
}

Node* BFS(Node *root, int target) {
    if(!root)   return nullptr;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node *temp=q.front();
        q.pop();
        if(temp->data==target)
            return temp;
        
        if(temp->left )
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return nullptr;
}

Node* DFS(Node *root, int target) {
    if(!root) return nullptr;
    
    stack<Node*> s;
    s.push(root);
    
    while(!s.empty()) {
        Node *temp=s.top();
        s.pop();
		cout<<temp->data<<", ";
        if(temp->data==target)
            return temp;
        
        if(temp->right)
            s.push(temp->right);
		if(temp->left)
            s.push(temp->left);
    }
	cout<<"\n";
    return nullptr;
}

int main() {
    root=insert(root, 12);
    insert(root, 18);
    insert(root, 10);
    insert(root, 14);
    insert(root, 16);
    insert(root, 7);
    insert(root, 4);
    insert(root, 8);
    insert(root, 5);
    insert(root, 13);
    
    // Node *found = BFS(root, 13);
    Node *found = DFS(root, 22);
    if(found==nullptr) 
        cout<<"Not found";
    else
        cout<<"Found";
    return 0;
}