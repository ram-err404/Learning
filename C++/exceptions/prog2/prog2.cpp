#include  <iostream>
#include  <stdio.h>
using namespace std;

template <class T, class T1, class T2>
T add(T1 a, T2 b) {
  return a+b;
}
template <class T, class T1, class T2>
T substract(T1 a, T2 b) {
  return a-b;
}
template <class T, class T1, class T2>
T multiply(T1 a, T2 b) {
  return a*b;
}
template <class T, class T1, class T2>
T divide(T1 a, T2 b) {
  try {
    if(b == 0){
      throw "cannot be divided by zero";
    }
  }catch(const char *msg) {
    cout << msg << endl;
    // cout<<"cannot divide by 0, ERROR NUMBER: "<<x<<endl;
    return -1;
  }
  return a/b;
}

int main() {
  int num1;
  double num2;
  cout<<"Enter 2 numbers: ";
  cin>>num1>>num2;

  cout<<"\nadd: "<<add<int, double>(num1, num2);
  cout<<"\nsubstract: "<<substract<int, double>(num1, num2);
  cout<<"\nmultiply: "<<multiply<int, double>(num1, num2);
  cout<<"\ndivide: "<<divide<int, double>(num1, num2) << endl;
  return 0;
}
