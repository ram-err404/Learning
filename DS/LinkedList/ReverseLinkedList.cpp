#include "linked_list.h"

/* Reverse a LinkedList. */
/* ALGO: 
 * --> Initialize three pointers prev as NULL, curr as head and next as NULL.
 * --> Iterate trough the linked list. In loop, do following.
 *    --> // Before changing next of current,
 *    --> // store next node
 *    --> next = curr->next
 *    --> // Now change next of current
 *    --> // This is where actual reversing happens
 *    --> curr->next = prev
 *    --> 
 *    --> // Move prev and curr one step forward
 *    --> prev = curr
 *    --> curr = next
 *  */
template <class T>
void  reverseLinkedList(LinkedList<T> &ll) {
  Node<T> *prev = nullptr;
  Node<T> *next = nullptr;
  Node<T> *cur = ll.get_head();

  while(cur!= nullptr) {
    // store next.
    next = cur->link;
    // change cur->link to prev.
    cur->link = prev;
    // Move pointers 1 position ahead.
    prev = cur;
    cur = next;
  }
  ll.set_head(prev);
}

int main() {
  LinkedList<int>  ll;

  ll.insert(10);
  ll.insert(20);
  ll.insert(11);
  ll.insert(30);
  ll.insert(40);
  ll.insert(11);
  ll.insert(50);
  ll.insert(33);
  ll.display();
  std::cout <<"Size of the LL: " << ll.size() << std::endl;
  ll.remove();
  ll.remove();
  ll.display();

  std::cout<<"Reverse LinkedList: "; 
  reverseLinkedList(ll);
  ll.display();
  std::cout <<"Size of the LL: " << ll.size() << std::endl;
  
  return 0;
}
