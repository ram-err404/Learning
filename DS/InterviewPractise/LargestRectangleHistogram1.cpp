// Max Histogram Area:

// Less efficient code, but more illustrative code.
// This code has Time Coplexity as O(n), but will have 3 pass.
// First is to calculate the left boundary, second is for right boundary and then last
// one is for calculating area with each index.

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int maxHistogramArea(vector<int> &hist) {
  int n=hist.size();
  int maxA = INT_MIN;
  int area = 0;

  vector<int> leftBoundary(n, 0);
  vector<int> rightBoundary(n, 0);
  
  int i=0;
  stack<int> stLeft;  // This will store index.
  while(i<n) {
    if(stLeft.empty() || hist[stLeft.top()] < hist[i]) {
      leftBoundary[i] = !stLeft.empty() ? stLeft.top() : 0;
      stLeft.push(i++);
    } else {
      stLeft.pop();
    }
  }
  
  // clear stack, by swapping it with an empty stack.
  
  stack<int> stRight;  // This will store index.
  i=n-1;
  while(i>=0) {
    if(stRight.empty() || hist[stRight.top()] < hist[i]) {
      rightBoundary[i] = !stRight.empty() ? stRight.top() : n-1;
      stRight.push(i--);
    } else {
      stRight.pop();
    }
  }
  
  // Finally area will be: 
  // hist[i]  --> height.
  /* Area = (rightBoundary - leftBoundary -1) * hist[i] */
  for(int i=0; i<n; i++) {
    area = (rightBoundary[i] - leftBoundary[i] -1) * hist[i];
    maxA = max(maxA, area);
  }
  return maxA;
}

int main() {
  vector<int> hist {2,1,5,6,2,3};

  cout<<"Max Histogram Area: " << maxHistogramArea(hist);
  return 0;
}
