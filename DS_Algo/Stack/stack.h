#include <iostream>

/* Node class */
template <class T>
class Node {
  T data;
public:
  Node *link;
  T get_data() {
    return data;
  }
  void set_data(T x) {
    data = x;
  }
};

/* Stack class */
template <class T>
class Stack {
  Node<T>   *top  = nullptr;
  long      count  = 0;
  
  /* Stack create function. Private, bcoz we don't want to call it with stack object.*/
  Node<T>* create_node(T x) {
    Node<T>   *ptr = new Node<T>();
    ptr->set_data(x);
    ptr->link = nullptr;
    return ptr;
  }
public:
  /* return true of false if stack is empty or not. */
  bool empty() {
    if(top == nullptr)
      return true;
    return false;
  }

  /* get top of the stack. */
  int  get_top() {
    return top->get_data();
  }
  
  /* get stack size. */
  long  size() {
    return  count;
  }
  
  /* Stack: insert element. Return number of elements in stack. */
  long push(T data) {
    /* create a node here. */
    Node<T>   *ptr = create_node(data);
    if(top == nullptr) {
      /* Stack is empty. */
      top = ptr;
    } else {
      ptr->link = top;
      top = ptr;
    }
    return ++count;
  }
  
  /* Stack: delete element. Return data. otherwise 0. */
  T pop() {
    T   val;
    if(top == nullptr) {
      // empty stack.
      std::cout<<"Stack is empty." << std::endl;
      // return ;
    } else {
      Node<T>   *ptr  = top;
      top = top->link;
      val = ptr->get_data();
      delete ptr;
      count--;
    }
    return val;
  }

  /* Display stack elements. */
  void display() {
    Node<T>   *traverse = top;
    // std::cout<<"Stack: ";
    while(traverse) {
      std::cout<< traverse->get_data() <<" --> ";
      traverse = traverse->link;
    }
    std::cout<<"FRONT\n";
  }
};
