#include <iostream>
using namespace std;

void print_array(int arr[], size_t size) {
  for(size_t i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

int first_repeating_method(int arr[], size_t size) {
  int *count = (int*) calloc(sizeof(int), size);
  for(size_t i=0; i<size; i++) {
    count[arr[i]]++;
    if(count[arr[i]] > 1)
      return i;
  }
  return -1;
}

int main() {
  // int arr[10000000] = {0};
  int *arr = (int*) calloc(sizeof(int), 100000000);
  for(int i=0; i<100000000-1; i++)
    arr[i] = i+1;
  arr[100000000-1] = 7;
  // size_t size = sizeof(arr)/sizeof(arr[0]);
  size_t size = 100000000;
  // print_array(arr, size);
  long long index = first_repeating_method(arr, size);
  if(index != -1)
    cout<<"First repeating index: " << index <<" val: "<< arr[index] <<"\n";
  else
    cout<<"No repeating numbers present in the array." << endl;
  return 0;
}
