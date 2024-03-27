// Q: https://www.hackerrank.com/challenges/contacts/problem
/*
I/p:
4               queries[] size n = 4
add hack        queries = ['add hack', 'add hackerrank', 'find hac', 'find hak']
add hackerrank
find hac
find hak

1 line Input: 4 add hack add hackerrank find hac find hak

O/p:
2
0
*/

#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
    node* children[26] = {nullptr};
    int count=0;
};

void addNode(node *root, string name, int index) {
    root->count++;
    if(index==name.size())  return;
    
    if(!root->children[name[index]-'a'])    root->children[name[index]-'a']=new node();
    addNode(root->children[name[index]-'a'], name, index+1);
}

int findCount(node *root, string name, int index) {
    if(index==name.size())  
        return root->count;
    else if(!root->children[name[index]-'a'])
        return 0;
    else
        return findCount(root->children[name[index]-'a'], name, index+1);
}

int main() {
    int n;
    cin>>n; // number of inputs.

    string a,b;
    unordered_set<string> s;
    node *root=new node();

    for(int i=0; i<n; i++) {
        cin>>a>>b;
        if(a=="add") {
            if(s.find(b)==s.end()) {
                // b is not already added. Add it to the Trie. (root).
                addNode(root, b, 0);
                s.insert(b);    // add b to set to avoid it adding again.
            }
        } else if(a=="find") {
            cout<<findCount(root, b, 0)<<" ";
        }
    }

    return 0;
}