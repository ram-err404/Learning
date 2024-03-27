#ifndef __SORT_H__
#define __SORT_H__

#define boost ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
/******************* InsertionSort *********************************/
void insertionSort(int arr, int size) {
  for(int i=1; i<size; i++) {
    int key = arr[i];
    int j=i-1;
    while(arr[j] > key) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
  }
}

/******************* QuickSort *********************************/
void swap(int &a, int &b) {
  if (a==b)
    return;
  int temp = a;
  a = b;
  b = temp;
}

int partition(int arr[], int low, int high) {
  int i = low-1;
  int pivot = arr[high];
  for(int j=0; j<high; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[i+1], arr[high]);
  return (i+1);
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

/******************* Sort *********************************/
void sort(int arr, int size) {
  quickSort(arr, 0, size);
}

#endif
