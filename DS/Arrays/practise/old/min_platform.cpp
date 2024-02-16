#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

void sort(int arr[], int size) {
  int i,j,key;
  for(i=1; i<size; i++) {
    key = arr[i];   j = i-1;
    while(arr[j] > key && j>=0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int platformRequired(int arr[], int arr_size, int dep[], int dep_size) {
  int max_platform=0, platform_count=0;
  int i=0, j=0;

  sort(arr, arr_size);
  sort(dep, dep_size);
  while(i<arr_size && j<dep_size) {
    if(dep[j] > arr[i]) {
      platform_count++; i++;
      if(max_platform < platform_count)
        max_platform = platform_count;
    } else {
      platform_count--;
      j++;
    }
  }
  return max_platform;
}

int main() {
  int arr[] = {100, 140, 150, 200, 215, 400};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
	int dep[] = {110, 300, 210, 230, 315, 600};
  int dep_size = sizeof(dep)/sizeof(dep[0]);
  cout<<"Platform required: " << platformRequired(arr, arr_size, dep, dep_size) << endl;
  return 0;
}
