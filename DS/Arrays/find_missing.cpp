#include <iostream>
using namespace std;

int find_missing(int arr[], int size) {
  int sum_index=0, sum_array=0, i=0;  
  for(i=0; i<size; i++) {
    sum_index = sum_index + i;
    sum_array = sum_array + arr[i];
  }
  sum_index = sum_index + i;
  return (sum_index - sum_array);
}

int main() {
  int array[] = {9, 1, 5, 2, 6, 4, 3, 7, 0, 10};
  int size = sizeof(array)/sizeof(array[0]);
  
  cout<<"Missing number is: "<< find_missing(array, size) << endl;
  
  return 0;
}
