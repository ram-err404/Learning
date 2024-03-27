#include "utility.h"

/* Method 1: */
int first_repeating(int arr[], int size) {
  int i, j;
  for(i=1; i<size; i++) {
    j=i-1;
    while(j>=0) {
      if(arr[j] == arr[i])
        return i;
      j--;
    }
  }
  return -1;
}

/* Method 2: */
int first_repeating_method2(int arr[], int size) {
  int count[size] = {0};
  for(int i=0; i<size; i++) {
    count[ arr[i] ]++;
    if(count[ arr[i] ] > 1)
      return i;
  }
  return -1;
}

int main() {
  int arr[10000] = {0};
  for(int i=0; i<10000-1; i++)
    arr[i] = i+1;
  arr[10000-1] = 7;
  int size = sizeof(arr)/sizeof(arr[0]);
  print_array(arr, size);
  int index = first_repeating_method2(arr, size);
  if(index != -1)
    cout<<"First repeating index: " <<index <<" val: "<< arr[index] <<"\n";
  else
    cout<<"No repeating numbers present in the array." << endl;
  return 0;
}
