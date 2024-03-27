#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node{
    char data;
    node *left, *right;

    node(char val) {
        data=val;
        left=right=nullptr;
    }
};

node *root=nullptr;

void fillHD(node *root, int hd, map<int, vector<char>> &mp) {
    if(!root) return;
    
    mp[hd].push_back(root->data);

    fillHD(root->left, hd-1, mp);
    fillHD(root->right, hd+1, mp);
}

void printVerticalOrder(node *root) {
    int hd=0;
    map<int, vector<char>> mp;

    fillHD(root, hd, mp);

    cout<<"Vertical Order: ";
    for(auto itr:mp) {
        cout << itr.second[0] <<" ";
    }
}

int main() {
    root=new node('A');

    root->left = new node('B');
    root->right = new node('C');

    root->left->left = new node('D');
    root->left->right = new node('E');

    root->right->left = new node('F');
    root->right->right = new node('G');

    root->left->left->left = new node('H');

    root->right->left->left = new node('I');
    
    root->right->right->left = new node('J');
    root->right->right->right = new node('K');

    root->right->right->right->right = new node('L');

    printVerticalOrder(root);
    return 0;
}