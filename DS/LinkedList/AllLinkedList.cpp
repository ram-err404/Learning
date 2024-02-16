// Reverse a linked list.
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

void printLL(Node *head)
{
  Node *cur = head;
  unordered_map<Node *, bool> visited;

  while (cur && !visited[cur])
  {
    cout << cur->data << " ";
    visited[cur] = true;
    cur = cur->next;
  }
  cout << "\n";
}

Node *reverseLL(Node *head)
{
  Node *prev = nullptr, *cur = nullptr, *next = nullptr;
  cur = head;

  while (cur)
  {
    next = cur->next;
    cur->next = prev;

    prev = cur;
    cur = next;
  }
  head = prev;
  return head;
}

Node *middleOfLL(Node *head)
{
  Node *slow = nullptr, *fast = nullptr;
  slow = fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node *NfromLastLL(Node *head, int N)
{
  Node *fast = nullptr;
  fast = head;
  int i = 1;

  while (fast && fast->next)
  {
    if (i < N)
    {
      i++;
      fast = fast->next;
    }
    else
    {
      break;
    }
  }
  if (i < N)
    return nullptr;

  Node *result = nullptr;
  result = head;
  while (fast && fast->next)
  {
    result = result->next;
    fast = fast->next;
  }
  return result;
}

bool detectLoop(Node *head)
{
  Node *slow = nullptr, *fast = nullptr;
  slow = fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

Node* intersctionNode(Node *l1, Node *l2) {
  int n1=0, n2=0, i;
  Node *l1cur=nullptr, *l2cur=nullptr;
  l1cur=l1;
  l2cur=l2;

  while(l1cur) {
    n1++; l1cur=l1cur->next;
  }
  while(l2cur) {
    n2++; l2cur=l2cur->next;
  }
  cout<<"L1 size: "<<n1<<" L2 size: "<<n2<<endl;
  l1cur=l1; l2cur=l2;
  if(n1>n2) {
    // Move l1 by (n1-n2) times ahead
    i=0;
    while(i<n1-n2) {
      l1cur=l1cur->next;
      i++;
    }
  }
  if(n2>n1) {
    // Move l2 by (n2-n1) times ahead.
    i=0;
    while(i<n2-n1) {
      l2cur=l2cur->next;
      i++;
    }
  }
  while ((l1cur && l1cur->next) && (l2cur && l2cur->next))
  {
    if (l1cur == l2cur)
      return l1cur;
    l1cur = l1cur->next;
    l2cur = l2cur->next;
  }
  return nullptr;
}

int main()
{
  Node *l1 = nullptr;
  l1 = new Node(12);
  l1->next = new Node(8);
  l1->next->next = new Node(15);
  l1->next->next->next = new Node(10);
  l1->next->next->next->next = new Node(5);
  l1->next->next->next->next->next = new Node(55);
  l1->next->next->next->next->next->next = new Node(35);
  l1->next->next->next->next->next->next->next = new Node(20);

  Node *l2=nullptr;
  l2 = new Node(43);
  l2->next = new Node(23);
  l2->next->next = l1->next->next->next->next;

  cout<<"L1: "; printLL(l1);
  cout<<"L2: "; printLL(l2);
  Node *temp = nullptr;
  temp = intersctionNode(l1,l2);
  if(temp)
    cout<<"Intersecting Node of L1 and L2 is: "<< temp->data << endl;
  else
    cout<<"No intersecting Node found"<<endl;

  temp = middleOfLL(l1);
  cout << "Middle of L1: "<< temp->data << endl;
  l1 = reverseLL(l1);
  cout<<"Reverse of L1: ";
  cout<<"L1: "; printLL(l1);

  temp = NfromLastLL(l1, 3);
  cout <<"Third element from Last (NfromLastLL): "<< temp->data << endl;

  l1->next->next->next->next->next->next->next->next = l1->next->next;
  cout<<"L1 after creating a loop: "; printLL(l1);

  if (detectLoop(l1))
    cout << "Loop detected in LL" << endl;
  else
    cout << "No Loop detected in LL" << endl;

  return 0;
}