#include <iostream>
// using namespace std;

// To make c++ faster

/* Without boost.
 *
real	0m5.100s
user	0m0.399s
sys	0m0.871s
 *
 * Exection time using boost
real	0m2.904s
user	0m0.444s
sys	0m0.707s
 * */
#define boost ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

#define MAX_ARRAY_SIZE  1000000

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    std::cout << arr[i] << "\t";
  std::cout <<"\n";
}

void swap(int &a, int &b) {
  if(a == b)
    return;
  int temp = a;
  a = b;
  b = temp;
}

int partition(int arr[], int low, int high) {
  int i=low-1;
  int pivot = arr[high];
  for(int j=low; j<high; j++) {
    if(arr[j] < pivot) {
      // swap arr[j] and arr[i]
      i++;
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[i+1], arr[high]);
  return (i+1);
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    // pi is partitioning index.
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

int main() {
  int arr[MAX_ARRAY_SIZE] = {0};
  for(int i=0; i<MAX_ARRAY_SIZE; i++)
    arr[i] = (rand()%(MAX_ARRAY_SIZE-0) + 1);
  // int size = sizeof(arr)/sizeof(arr[0]);
  print_array(arr, MAX_ARRAY_SIZE);
  quickSort(arr, 0, MAX_ARRAY_SIZE);
  std::cout <<"\n\n\n";
  print_array(arr, MAX_ARRAY_SIZE);
  return 0;
}
