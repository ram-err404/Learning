#include "utility.h"
#include <bits/stdc++.h>

map<int, int> pair_sum_to_x(int arr[], int size, int X) {
  int l=0, r=size-1;
  int sum=0;
  map<int, int>   result;
  /* Sort the array, so that we have higher values at the end */
  sort(arr, size);
  

  while(l<r) {
    sum = arr[l] + arr[r];
    if(sum == X) {
      result.insert( pair<int, int>(arr[l], arr[r]) );
      l++; r--;
    }
    else if(sum < X)
      l++;
    else
      r--;
  }
  return result;
}

/* Method 2: Asked in Google. */
map<int, int> pair_sum_to_x_efficient(int arr[], int size, int X) {
  unordered_set<int>  comp; // Complement of the number.
  map<int, int>       res;
  int                 complement = 0;
  unordered_set<int>::iterator  itr;

  for(int i=0; i<size; i++) {
    complement = X-arr[i];

    // unordered_set.find() returns end iterator if key is not found.
    if( comp.find(arr[i]) != comp.end()) {
      // We found the pair
      res.insert(make_pair(complement, arr[i]));
    }
    comp.insert(complement);
  }
  return res;
}

int main() {
  int x=15;
  // int array[] = { -40, -5, 1, 3, 6, 7, 8, 20 };
  int array[100000] = {0};
  for(int i=0; i<100000; i++) {
    array[i] = (rand()% (1000-1) + 1);
  }
  int size = sizeof(array)/sizeof(array[0]);
  // cout<<"Enter value for X: ";  cin >> x;
  
  // map<int, int> res = pair_sum_to_x(array, size, x);
  map<int, int> res = pair_sum_to_x_efficient(array, size, x);
  
  print_array(array, size);
 
  cout<<"Pair sum equals to "<< x <<": "<< endl;

  for(auto itr:res)
    cout<< itr.first <<" , "<< itr.second << endl;
  return 0;
}
