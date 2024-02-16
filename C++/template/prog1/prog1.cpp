#include  <iostream>
#include  <stdio.h>
using namespace std;

template <class T, typename T1, typename T2>
T my_funct(T1 a, T2 b) 
{
  cout<<"Inside my_funct: \n";
  cout<<a<<" "<<b<<endl;
  return a;
}

template <class T, typename T1, typename T2>
T my_add(T1 a, T2 b) {
  return a+b;
}

template <class T, typename T1, typename T2>
T my_compare(T1 a, T2 b) {
  return (a - b);
}

int main() {
  my_funct<int, float>(10, 20.5);
  my_funct<char, char>('a', 'b');   //==> a b
  my_funct<char, int>('a', 10);     //==> 97 10
  my_funct<char, float>('a', 15.3); //==> 97 15.3
  
  cout<<"Sum: "<<my_add<int, float>(20, 50.5)<<endl;
  cout<<"Compare: "<<my_compare<float, int>(50.5, 65.5)<<endl;    //==> 50.5, 65
  cout<<"Compare: "<<my_compare<float, double>(50.5, 20.2)<<endl;
  return 0;
}


