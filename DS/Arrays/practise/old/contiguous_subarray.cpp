#include "utility.h"

typedef struct indexes {
  int start, end;
} indexes_t;

indexes_t contiguous_subarray(int arr[], int size) {
  int sum=0, max=INT_MIN, s=0;
  indexes_t   res = {0, 0};

  for(int i=0; i<size; i++) {
    sum += arr[i];
    if(sum > max) {
      max = sum;
      res.start = s;
      res.end = i;
    }
    if(sum < 0) {
      sum = 0;
      s = i+1;
    }
  }
  return res;
}

int main() {
  int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  print_array(arr, size);
  indexes_t   res = contiguous_subarray(arr, size);
  cout<<"Indexes Start: "<< res.start <<" End: "<< res.end << endl;
  
  for(int i=res.start; i<res.end; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
  
  return 0;
}
