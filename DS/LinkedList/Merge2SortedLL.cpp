// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy, *head;
        dummy = head = new ListNode();

        ListNode *l1 = list1;
        ListNode *l2 = list2;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }
        if(!l1) {
            dummy->next = l2;
        } else {
            dummy->next = l1;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }
};

void populateList(ListNode *list1, ListNode *list2) {
    
}

int main() {
    ListNode *list1=nullptr;
    ListNode *list2=nullptr;

    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution ob;
    ListNode *head = ob.mergeTwoLists(list1, list2);

    cout<<"After merging the 2 sorted List: [";
    ListNode *cur = head;
    while(cur) {
        cout<< cur->val <<" ";
        cur = cur->next;
    }
    cout<<"]\n";
    return 0;
}