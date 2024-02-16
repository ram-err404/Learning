#ifndef __NODE_H__
#define __NODE_H__

/* Node class */
template <class T>
class Node {
  T data;
public:
  Node<T> *link;
  /* Member functions. */
  T get_data();
  void set_data(T x);
};

template <class T>
T Node<T>:: get_data() {
  return data;
}

template <class T>
void Node<T>:: set_data(T x) {
  data = x;
}

#endif
