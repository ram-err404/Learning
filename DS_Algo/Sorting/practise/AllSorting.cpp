/* Sorting Algorithms: */

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &arr) {
  int n=arr.size();
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

/* Select an index value as key and sort the array till that index. */
void insertionSort(vector<int> &arr) {
  int n=arr.size();
  int key;
  
  for(int i=1; i<n; i++) {
    key = arr[i];
    int j=i-1;
    while(j>=0 && arr[j] > key) {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1] = key;
  }
  printArray(arr);
}

/* Find the minimum element and place it the last index of sorted part (i.e. ith index). */
void selectionSort(vector<int> &arr) {
  int n=arr.size();
  int mn=0;  // say 0th index has the minimum val.
  
  for(int i=0; i<n-1; i++) {
    mn=i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[mn]) {
        mn=j;
      }
    }
    if(arr[i] != arr[mn]) {
      swap(arr[i], arr[mn]);
    }
  }
  printArray(arr);
}

/*Quick Sort: */
// Partition is the main logic of quickSort algorithm.
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i=low;  // last smallest element's index.
  for(int j=low; j<=high; j++) {
    // Shift all the elements smaller than pivot to the left. 
    if(arr[j] < pivot) {
      swap(arr[j], arr[i]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i; // partitioning index
}

void quickSort(vector<int> &arr, int low, int high) {
	if(low<high) {
    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
	}
}

int main() {
  vector<int> arr{10,1,34,5,23,65,1,2,5,2};
  
  // insertionSort(arr);
  // selectionSort(arr);
  quickSort(arr, 0, arr.size()-1);
  printArray(arr);
  return 0;
}
