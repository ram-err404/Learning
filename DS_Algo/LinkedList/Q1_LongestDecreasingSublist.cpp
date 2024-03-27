// Interview question: Az Coding Assessment Q1.

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int _val) {
        val=_val;
        next=nullptr;
    }
};

Node* insert(Node* head, int _val) {
    if(!head) {
        return head = new Node(_val);
    }
    Node* cur = head;
    while(cur->next)
        cur=cur->next;
    cur->next=new Node(_val);
    return head;
}

void printList(Node* head) {
    Node* cur=head;
    while(cur) {
        cout<< cur->val <<" ";
        cur=cur->next;
    }
    cout<<"\n";
}

Node* longestDecreasingSublist(Node* head) {
    Node *start=head, *end=head;
    Node* cur=head;
    int curLen=1, maxLen=1;
    
    while(cur->next) {
        if(cur->val >= cur->next->val) {
            curLen++;
        } else {
            if(maxLen < curLen) {
                maxLen = curLen;
                start = end->next;
                end = cur;
            } else {
                start = cur->next;
            }
            curLen=1;
        }
        cur=cur->next;
    }
    end->next=nullptr;
    return start;
}

int main() {
    vector<int> arr {2,5,4,4,5,4,3,3,2,1,6};
    Node *head = nullptr;
    
    for(int i=0; i<arr.size(); i++) {
        head = insert(head, arr[i]);
    }
    printList(head);
    
    Node* start = longestDecreasingSublist(head);
    printList(start);
    return 0;
}