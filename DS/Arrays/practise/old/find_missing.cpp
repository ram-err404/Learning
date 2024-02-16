#include <iostream>
using namespace std;

int find_missing(int arr[], int size) {
  int index_sum=0, value_sum=0;
  for(int i=1; i<=size; i++) {
    value_sum += arr[i-1];
    index_sum += i;
  }
  return (index_sum - value_sum);
}

int main() {
  int array[] = {9, 1, 5, 2, 6, 4, 3, 7, 0, 10};
  int size = sizeof(array)/sizeof(array[0]);
  
  cout<<"Missing number is: "<< find_missing(array, size) << endl;
  
  return 0;
}
