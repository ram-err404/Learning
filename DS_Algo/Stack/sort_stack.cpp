/* Quest: Need to sort a stack using another temporary stack. */
#include "stack.h"

/* Method 1: Using temporary stack. */
/* ALGO: 
 * --> Create a temporary stack say tmpStack.
 * --> While input stack is NOT empty do this:
 *      --> Pop an element from input stack call it temp
 *      --> while temporary stack is NOT empty and top of temporary stack is greater than temp,
 *      --> pop from temporary stack and push it to the input stack
 *      --> push temp in temporary stack
 * --> The sorted numbers are in tmpStack.
 * */
Stack<int> sort_with_temp_stack(Stack<int> &s1) {
  /* */
  int temp;
  Stack<int>  s2; //temp stack.
  while(!s1.empty()) {
    // pop out the first element.
    temp = s1.pop();
    // while temporary stack is not empty and top of stack is greater than temp
    while(!s2.empty() && s2.get_top() > temp)
      s1.push(s2.pop());
    
    // push temp in tempory of stack
    s2.push(temp);
  }
  return s2;
}

/* Method 2: Using Recursion. */
/* ALGO:
 * Algorithm
 *  We can use below algorithm to sort stack elements:
 *  --> sortStack(stack S)
 *  -->     if stack is not empty:
 *  -->         temp = pop(S);  
 *  -->         sortStack(S); 
 *  -->         sortedInsert(S, temp);
 *
 *  Below algorithm is to insert element is sorted order:
 *  --> sortedInsert(Stack S, element)
 *  -->     if stack is empty OR element > top element
 *  -->         push(S, elem)
 *  -->     else
 *  -->         temp = pop(S)
 *  -->         sortedInsert(S, element)
 *  -->         push(S, temp)
 * */
void  sortedInsert(Stack<int> &s, int element) {
  if(s.empty() || element > s.get_top()) 
    s.push(element);
  else {
    int temp = s.pop();
    sortedInsert(s, element);
    s.push(temp);
  }
}
void  sort_using_recursion(Stack<int> &s) {
  if(!s.empty()) {
    int temp = s.pop();
    sort_using_recursion(s);
    sortedInsert(s, temp);
  }
}

int main() {
  Stack<int>  s1;
  Stack<int>  s2;   // temp stack.
  for(int i=0; i<100000; i++) {
    // push a random number within the range of 100000.
    s1.push((rand()%(100000-1)+1));
  } 
  // s1.push(50);
  // s1.push(10);
  // s1.push(60);
  // s1.push(20);
  // s1.push(90);
  // s1.push(30);
  // s1.push(70);
  // s1.push(40);
  // s1.push(80);
  // s1.push(11);
  // s1.push(44);
  // s1.push(88);
  // s1.push(12);
  // s1.push(32);
  // s1.push(22);
  // s1.push(80);
  // s1.push(67);
  
  // s1.display();
  // std::cout<<"\n\n";
  s1 = sort_with_temp_stack(s1);
  // std::cout<<"Sorting using recursion: " << std::endl;
  // sort_using_recursion(s1);
  
  // std::cout<<"Stack after sorting: stack_size: "<< s1.size() << std::endl;
  // s1.display();
  
  return 0;
}
