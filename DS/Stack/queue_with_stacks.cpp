#include "stack.h"

template  <class T>
class   Queue {
  Stack<T>  s1; // Main stack
  Stack<T>  s2; // stack to store poped elements.
public:
  long size() {
    return s1.size();
  }
  /* Insert element in Queue. FIFO. 
   * Returns the size or number of elements in the Queue. */
  int enQueue(T data) {
    return s1.push(data);
  }

  /* Delete elements from the Queue. FIFO. 
   * Since top of s1 is actually the rear end, so we need to pop every element
   * and push into stack s2 till last element, and then again push all the 
   * elements back to stack s1. */
  T deQueue() {
    T   val = 0;
    if(s1.get_top() == nullptr) {
      std::cout<<"Queue is empty." << std::endl;
      return val;
    }
    while(s1.get_top()->link != nullptr) {
      // pop elements from s1 and push to s2.
      s2.push(s1.pop());
    }
    val = s1.pop();
    // Now again push all the elements back to s1 from s2.
    while(s2.get_top()) {
      s1.push(s2.pop());
    }
    return val;
  }

  /* Display Queue elements. */
  void display() {
    s1.display();
  }
};

int main() {
  Queue<int>  q;
  q.enQueue(10);
  // q.enQueue(20);
  // q.enQueue(30);
  // q.enQueue(40);
  // q.enQueue(50);
  // q.enQueue(60);
  // q.enQueue(60);
  // q.enQueue(80);
  q.display();
  
  q.deQueue();
  q.deQueue();
  q.display();
  
  q.enQueue(90);
  q.enQueue(100);
  q.enQueue(110);
  q.display();
  
  q.deQueue();
  q.display();
  return 0;
}
