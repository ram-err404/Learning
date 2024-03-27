#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &vec) {
  for(auto itr : vec)
    cout<< itr <<",";
  cout<<"\n";
}

vector<int> maxSlidingWindow(vector<int>& num, int k) {
  int max_sliding_window = INT_MIN;
  int sum=0;
  vector<int> sliding_window_sum;

  for(int i=0; i<k; i++)
    sum += num[i];
  sliding_window_sum.push_back(sum);
  max_sliding_window = sum;
  for(int i=k; (i < (int)num.size()); i++) {
    sum += num[i] - num[i-k];
    sliding_window_sum.push_back(sum);
    if(max_sliding_window < sum) 
      max_sliding_window = sum;
  }
  cout<<"max_sliding_window sum: " << max_sliding_window << endl;
  return sliding_window_sum;
}

int main() {
  vector<int> vec = {1,3,-1,-3,5,3,6,7,-4};
  print_vector(vec);
  vector<int> result = maxSlidingWindow(vec, 3);

  cout<<"sliding_window_sum: [ ";
  for(auto itr : result)
    cout<< itr <<",";
  cout<<" ]" << endl;

}
