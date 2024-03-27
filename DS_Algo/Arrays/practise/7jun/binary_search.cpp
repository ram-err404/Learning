#include <iostream>
#define MAX_ARRAY_SIZE  100000
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout << arr[i] <<" ";
  cout <<"\n";
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i=low-1;
  for(int j=low; j<high; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[i+1], arr[high]);
  return (i+1);
}

void quickSort(int arr[], int low, int high) {
  if(low<high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

int binary_search(int arr[], int size, int key) {
  int low=0, high=size;
  while(low < high) {
    int mid = (low + high)/2;
    if(key == arr[mid])
      return mid;
    else if(key < arr[mid])
      high = mid-1;
    else
      low = mid+1;
  }
  return -1;  // Not found.
}

int main() {
  int arr[MAX_ARRAY_SIZE] = {0};

  for(int i=0; i<MAX_ARRAY_SIZE; i++) 
    arr[i] = (rand() % (MAX_ARRAY_SIZE - 0) + 1);
  
  /* Sort the array. */
  // insertion_sort(arr, MAX_ARRAY_SIZE);
  quickSort(arr, 0, MAX_ARRAY_SIZE-1);
  
  /* Array after sorting. */
  print_array(arr, MAX_ARRAY_SIZE);
  
  /* Binary search. X=511 (any value to be searched) */
  int index = binary_search(arr, MAX_ARRAY_SIZE, 511);
  
  if(index == -1)
    cout<<"Value not found in array" << endl;
  else
    cout<<"Found at index: "<< index <<" val: "<< arr[index] << endl;
  
  return 0;
}
