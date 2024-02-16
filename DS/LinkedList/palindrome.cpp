/* Quest: Check is given list is palindrome or not.
 *
 * Use STL list of C++. */

#include <iostream>
#include <list> // for linked list
#include <stack>
#include <iterator> // list iterator to traverse list.

using namespace std;

template <typename T>
bool palindrome(list<T> &ll) {
  // list<T> :: iterator   it = ll.begin();  // this is error.
  typename list<T> :: iterator   it = ll.begin();   // correct.
  stack<T>  s;
  T temp;
  while(it != ll.end()) {
    s.push(*it);  // push that value to stack.
    it++;
  }
  // Traverse the list again and pop from stack and compare.
  it = ll.begin();
  while(it != ll.end()) {
    temp = s.top();
    if(*it != temp)
      return false;
    s.pop();    // pop element from the stack
    it++;       // move to the next element of the list.
  }  
  return true;
}

int main() {
  list<char>   l1;
  l1.push_back('R');
  l1.push_back('A');
  l1.push_back('D');
  l1.push_back('A');
  l1.push_back('R');
  // ll.push_back('t');
  
  list<int>   l2;
  l2.push_back(1);
  l2.push_back(2);
  l2.push_back(3);
  l2.push_back(4);
  l2.push_back(5);
  l2.push_back(4);
  l2.push_back(3);
  l2.push_back(2);
  // l2.push_back(1);
  
  cout<<"Is LinkedList l1 is palindrom: " << ( palindrome(l1) ? "yes" : "no" )<< endl;
  cout<<"Is LinkedList l2 is palindrom: " << ( palindrome(l2) ? "yes" : "no" )<< endl;

  return 0;  
}
