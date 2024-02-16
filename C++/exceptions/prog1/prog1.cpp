#include  <iostream>
#include  <stdio.h>
using namespace std;

int main() {
  int momsAge = 30;
  int sonsAge = 34;

  try{
    if(sonsAge > momsAge){
      throw 99; //throw errornumber (any)
    }
  }catch(int x) {
    cout<<"son cannot be older than mom. ERROR NUMBER: "<<x<<endl;
  }

  return 0;
}
