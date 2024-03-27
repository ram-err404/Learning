#include <iostream>
#include <climits>
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

int main() {
  int min = INT_MAX;
  int max = INT_MIN;
  int *arr = nullptr;
  arr = new int[20];
  int max_rand = 100, min_rand = 1;
  for(int i=0; i<20; i++) {
    /* Generating random numbers b/w 1-100 */
    arr[i] = (rand() % (max_rand + 1 - min_rand) + min_rand);
    if(max < arr[i])  max = arr[i];
    if(min > arr[i])  min = arr[i];
  }
  cout<<sizeof(arr) <<" " << sizeof(arr[0]) << endl;
  print_array( arr, 20 );
  cout<<"Min: " << min <<" Max: " << max << endl;
  return 0;
}
