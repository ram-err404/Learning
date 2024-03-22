// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node *prev, *next;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = next = nullptr;
        }
    };

    Node *head, *tail;
    unordered_map<int, Node*>   mp;
    int capacity;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node *nd = mp[key];
            // node detach this node and put it after head.
            int val = nd->val;
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;
            mp.erase(key);
            delete nd;
            nd = nullptr;
            // now insert the same node after head;
            nd = new Node(key, val);
            nd->prev = head;
            nd->next = head->next;
            nd->next->prev = nd;
            head->next = nd;
            mp[key] = nd;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *nd = mp[key];
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;
            mp.erase(nd->key);
            delete nd;
        } else if(mp.size() == capacity) {
            // need to delete the least recently used data. (data near to tail).
            Node *nd = tail->prev;
            nd->prev->next = tail;
            tail->prev = nd->prev;
            mp.erase(nd->key);
            delete nd;
        }
        // Now insert the new node after head.
        Node *nd = new Node(key, value);
        mp[key] = nd;
        nd->prev = head;
        nd->next = head->next;
        nd->next->prev = nd;
        head->next = nd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2);

    cout << lRUCache->get(1) <<endl;        // 1
    
    lRUCache->put(3, 3);
    
    cout << lRUCache->get(2) <<endl;        // -1
    
    lRUCache->put(4, 4);
    
    cout << lRUCache->get(1) <<endl;        // -1
    cout << lRUCache->get(3) <<endl;        // 3
    cout << lRUCache->get(4) <<endl;        // 4

    lRUCache->put(3, 6);
    lRUCache->put(4, 8);

    cout << lRUCache->get(3) <<endl;        // 6
    cout << lRUCache->get(4) <<endl;        // 8
    return 0;
}