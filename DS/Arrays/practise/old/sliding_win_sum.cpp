#include "utility.h"

template<class T>
vector<int> maxSlidingWindow(vector<T> vec, int win_size) {
  int i, sum=0;
  vector<int>   res_sum;
  for(i=0; i<win_size; i++)
    sum += vec[i];
  
  res_sum.push_back(sum); 
  int max_sum = sum;

  for(i=win_size; i < (int)vec.size(); i++) {
    sum += vec[i] - vec[i-win_size];
    if(sum > max_sum)
      max_sum = sum;
    res_sum.push_back(sum);
  }
  cout<<"Max sliding window sum: "<< max_sum << endl;
  return res_sum;
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
