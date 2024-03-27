#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <stdlib.h>
#include "node.h"

template <class T>
class LinkedList {
  Node<T> *Head;
  int     cur_size;
public:
  /* Constructor */
  LinkedList() {
    cur_size = 0;
    Head = nullptr;
  }
  /* Get Head node. */
  Node<T>* get_head() const;
  /* Set Head node. */
  void set_head(Node<T> *ptr);
  /* Get value at head. */
  T head();
  /* Get size of the LL. */
  int size();
  /* check if LL is empty. */
  bool empty();

  /* Create Node. */
  Node<T>* create(T val);
  /* Insert at begening. (from head). Return: current size of LL. */
  int insert(T val);
  /* Insert at given postion. Return the current size of the LinkedList. */
  int insert_pos(T val);
  /* Delete from begening. (from head) */
  T remove();
  /* Delete from given position. (from head) */
  T remove_pos();
  /* Modify the value of a given position from head. */
  int modify(int pos, T val);

  /* Display */
  void display();
  /* Find. Return: index. */
  int find();
};

/* Get value at head. */
template <class T>
T LinkedList<T> :: head() {
  if(Head)
    return Head->get_data();
  return 0;
}

/* Get Head Node. */
template <class T>
Node<T>* LinkedList<T> :: get_head() const {
  return Head;
}
/* Set Head node. */
template <class T>
void LinkedList<T> :: set_head(Node<T> *ptr) {
  Head = ptr;
}
/* Get size of the LL. */
template <class T>
int LinkedList<T> :: size() {
  return cur_size;
}

/* Check if LL is empty. */
template <class T>
bool LinkedList<T> :: empty() {
  if(Head)
    return false;
  return true;
}

/* Create Node. */
template <class T>
Node<T>* LinkedList<T> :: create(T val) {
  Node<T> *ptr = new Node<T>;
  if(!ptr) {
    std::cerr <<"Error occured in creating node." << std::endl;
    exit(-1);
  } else {
    ptr->set_data(val);
    ptr->link = nullptr;
  }
  return ptr;
}

/* Insert at begening. (from head). Return: current size of LL. */
template <class T>
int LinkedList<T> :: insert(T val) {
  /* Create Node. */
  Node<T> *nptr = create(val);
  if(Head == nullptr) {
    /* This is the first Node. */
    set_head(nptr);
  } else {
    nptr->link = Head;
    set_head(nptr);
  }
  return ++cur_size;
}

/* Insert at given position. Return the current size of the LinkedList. */
template <class T>
int LinkedList<T> :: insert_pos(T val) {
  
  return cur_size;
}

/* Delete from begening. */
template <class T>
T LinkedList<T> :: remove() {
  Node<T> *ptr;
  T temp = 0;
  if ( !empty() ) {
    temp = head();
    ptr = Head;
    set_head(Head->link);
    delete ptr;
    --cur_size;
  }
  return temp;
}

/* Display. */
template <class T>
void LinkedList<T> :: display() {
  Node<T>   *trav = Head;
  while(trav) {
    std::cout << trav->get_data() <<" --> ";
    trav = trav->link;
  }
  std::cout <<"NULL \n";
}

#endif
