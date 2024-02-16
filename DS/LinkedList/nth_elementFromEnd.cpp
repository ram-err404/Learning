/* Quest: Find nth element from the end in a given list. 
 * Note: Use STL list of C++. */

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template <typename T>
void  display(const list<T>   &ll) {
  typename list<T> :: const_iterator itr  = ll.begin();
  while(itr != ll.end()) {
    cout<< *itr <<"-->";
    itr++;
  }
  cout<<"NULL" << endl;
}

template <typename T>
T nth_elementFromEnd(const list<T>  &ll, int pos_from_last) {
  // since list<T>  &ll is const, so we need const iterator.
  typename list<T> :: const_iterator  ahead_itr = ll.begin();  // n-times ahead iterator
  int i = 0;
  while(i<pos_from_last) {
    i++;
    if(ahead_itr != ll.end())
      ahead_itr++;
    else
      return (T)0;
  }
  typename list<T> :: const_iterator  res_itr = ll.begin();  // resultant iterator
  while(ahead_itr != ll.end()) {
    res_itr++;
    ahead_itr++;
  }
  // At the end, res_itr will be at nth element from the last;
  return *res_itr;  
}

int main() {
  list<int>   ll;
  ll.push_back(10);
  ll.push_back(40);
  ll.push_back(20);
  ll.push_back(55);
  ll.push_back(11);
  ll.push_back(50);
  ll.push_back(33);
  ll.push_back(42);
  ll.push_back(22);
  ll.push_back(76);
  ll.push_back(90);
  ll.push_back(87);
  ll.push_back(66);
  ll.push_back(49);
  ll.push_back(17);
  
  int pos_from_last = 4;
  display(ll); 
  int res = nth_elementFromEnd( ll, pos_from_last );
  if (res)
    cout << pos_from_last <<" element from the last: " << res << endl;
  else
    cout<< pos_from_last <<" element from the last does not exist. " << endl;
  return 0;
}
