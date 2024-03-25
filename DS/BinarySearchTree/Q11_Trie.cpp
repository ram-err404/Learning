// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <iostream>
#include <vector>
using namespace std;

class Trie {
private:
    struct TrieNode{
        TrieNode *child[26];
        bool end;
    };
    struct TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;

        for(char x:word) {
            if(!cur->child[x-'a']) {
                cur->child[x-'a'] = new TrieNode();
            }
            cur = cur->child[x-'a'];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(char x:word) {
            if(!cur->child[x-'a']) {
                return false;
            }
            cur = cur->child[x-'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char x:prefix) {
            if(!cur->child[x-'a']) {
                return false;
            }
            cur = cur->child[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    vector<string> inpType {"insert", "search", "search", "startsWith", "insert", "search"};
    vector<string> inpVal {"apple", "apple", "app", "app", "app", "app"};
    // O/p: [null, true, false, true, null, true]
    
    Trie* obj = new Trie();
    int n=inpType.size();
    
    for(int i=0; i<n; i++) {
        if(inpType[i].compare("insert") == 0) {
            obj->insert(inpVal[i]);
            cout<<"null, ";
        } else if(inpType[i].compare("search") == 0) {
            cout<< boolalpha << obj->search(inpVal[i]) <<", ";

        } else if(inpType[i].compare("startsWith") == 0) {
            cout<< boolalpha << obj->startsWith(inpVal[i]) <<", ";
        }
    }
    return 0;
}