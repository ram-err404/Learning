#include <iostream>
using namespace std;

int find_missing(int arr[], int size) {
  int missing_number = (size*(size+1))/2;
  cout<< missing_number << endl;
  for(int i=0; i<size; i++) 
    missing_number -= arr[i];
  return missing_number;
}

int main() {
  int array[] = {9, 1, 5, 2, 6, 4, 3, 7, 0, 10};
  int size = sizeof(array)/sizeof(array[0]);
  
  cout<<"Missing number is: "<< find_missing(array, size) << endl;
  
  return 0;
}
