#include "linked_list.h"

template <class T>
struct middle_linked_list {
  int     position;
  Node<T> *ptr;
};
// typedef int type of this struct variant.
typedef middle_linked_list<int>   middle_linked_list_t;

template <class T>
middle_linked_list<T> middleLinkedList(const LinkedList<T>  &ll) {
  Node<T> *slow = nullptr;
  Node<T> *fast = nullptr;
  middle_linked_list<T>   res = {0, nullptr};
  slow = fast = ll.get_head();  // get head is a const function.
  
  while(fast && fast->link) {
    ++res.position;
    slow = slow->link;
    fast = fast->link->link;
  }
  
  res.ptr = slow;
  return res;
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
  ll.insert(43);
  ll.insert(83);
  ll.insert(13);
  ll.insert(43);
  ll.insert(36);
  ll.insert(96);
  ll.display();
  std::cout <<"Size of the LL: " << ll.size() << std::endl;
  middle_linked_list_t  ret_val = middleLinkedList(ll);
  std::cout<<"Middle of LL: position: " << ret_val.position 
    <<" Data: " << ((ret_val.ptr) ? ret_val.ptr->get_data() : 0)
    <<" Link: " << ((ret_val.ptr) ? ret_val.ptr->link : 0)
    <<", Value at link: " 
    << ((ret_val.ptr) ? ((ret_val.ptr->link) ? ret_val.ptr->link->get_data() : 0) : 0)
    << std::endl;
  return 0;
}
