#include <iostream>
using namespace std;
#define MAX_ARRAY_SIZE  100000

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

/* Insertion Sort. */
/* With insertion sort, running time:
 * real	0m13.789s
 * user	0m13.736s
 * sys	0m0.004s */
void insertion_sort(int arr[], int size) {
  int i, j, key=0;
  for(i=1; i<size; i++) {
    j=i-1;  key = arr[i];
    while(arr[j] > key && j>=0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

/********************************************************************/
/* Quick Sort. */
/* With Quick Sort, running time: 
 * real	0m0.143s
 * user	0m0.072s
 * sys	0m0.008s */
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}
/*******************************************************************/

int binary_search(int arr[], int size, int X) {
  int l=0, r=size-1, mid=0;
  while(l<r) {
    mid = (l+r)/2;
    if(arr[mid] == X)
      return mid;
    else if(arr[mid] > X)
      r = mid-1;
    else
      l = mid+1;
  }
  return -1;
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
