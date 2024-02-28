#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int maxHistArea(vector<int> &hist) {
  int n=hist.size();
  int maxA=INT_MIN;
  int area=0;
  stack<int> st;

  int i=0;
  while(i<n) {
    if(st.empty() || hist[st.top()] < hist[i]) {
      st.push(i++);
    } else {
      // Need to pop from stack and have to calculate the for this histogram block.
      int top = st.top();
      st.pop();

      area = hist[top] * (st.empty() ? i : i-st.top()-1);
      maxA = max(maxA, area);
    }
  }
  while(!st.empty()) {
    int top = st.top();
    st.pop();

    area = hist[top] * (st.empty() ? i : i-st.top()-1);
    maxA = max(maxA, area);
  }
  return maxA;
}

int main() {
  vector<int> hist{2,1,5,6,2,3};

  cout<<"Maximum Histogram Area: "<< maxHistArea(hist) <<endl;
  return 0;
}
