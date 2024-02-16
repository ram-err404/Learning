#include "stack.h"

int main() {
  Stack<int>  s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);
  s.push(70);
  
  s.display();
  s.pop();
  s.pop();
  s.push(80);
  s.display();
  return 0;
}
