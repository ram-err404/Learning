#include<iostream>
#include<stack>
using namespace std;

struct Node{
  char data;
  Node *next;

  Node(char val) {
    data=val;
    next=nullptr;
  }
};

bool isPalindrome(Node *head) {
  stack<char> s;
  Node *cur=head;
  while(cur) {
    s.push(cur->data);
    cur=cur->next;
  }
  cur=head;
  while(cur) {
    if(cur->data != s.top())
      return false;
    s.pop();
    cur = cur->next;
  }
}

int main() {
  Node *l1 = new Node('R');
  l1->next = new Node('A');
  l1->next->next = new Node('D');
  l1->next->next->next = new Node('A');
  // l1->next->next->next->next = new Node('A');
  l1->next->next->next->next = new Node('R');

  if(isPalindrome(l1))
    cout<<"LL is a Palindrome"<<endl;
  else
    cout<<"LL is not a Palindrome."<<endl;

  return 0;
}