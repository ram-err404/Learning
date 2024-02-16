#include  <iostream>
#include  <stdio.h>
using namespace std;

template <class T1, class T2>
class Ram{
  T1 first;
  T2 second;
  public:
    Ram(T1 a, T2 b){
      first = a;
      second = b;
    }
    T1 bigger();
};
template <class T1, class T2>
T1 Ram<T1, T2>::bigger() {
  return (first > second ? first: second);
}

int main() {
  Ram<double, int> obj1(50.5, 90);
  Ram<float, int> obj2(70.2, 15);
  Ram<int, float> obj3(30, 90.2);
  cout<<obj1.bigger()<<endl;
  cout<<obj2.bigger()<<endl;
  cout<<obj3.bigger()<<endl;

  return 0;
}
