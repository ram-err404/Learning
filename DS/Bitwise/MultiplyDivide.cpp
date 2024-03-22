
#include <iostream>

using namespace std;

// Divide using bitwise operators:
// Function to divide a by b and return floor value it
long long divide(long long dividend, long long divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only if
  // either one of them is negative
  // otherwise it will be positive
  
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
  
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  long long quotient = 0, temp = 0;
 
  // test down from the highest bit and
  // accumulate the tentative value for
  // valid bit
  for (int i = 31; i >= 0; --i) {
 
    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
  //if the sign value computed earlier is -1 then negate the value of quotient
  if(sign==-1) quotient=-quotient;
   
  return quotient;
}

// Multiply using bitwise operators:
/* 
    x * y = (x*2) * (y/2).      ==> x*2 = x<<1, y/2 = y>>1.
    
    and next multiply sign we can remove using 1 loop.
*/
int multiply(int x, int y) {
    int res = 0;
    
    for(int i=y; i>0; i = i>>1) {
        if(i & 1) {
            res += x;
        }
        x = x<<1;
    }
    return res;
}

int main() {
    int x=40, y=28;
    int a=1120, b=-28;
    
    cout<<"Multiplication: "<< multiply(x, y) <<endl;
    cout<<"Divide: "<< divide(a, b) <<endl;
    return 0;
}