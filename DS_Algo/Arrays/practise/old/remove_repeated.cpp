#include "utility.h"

/* Method 1: */
void remove_duplicate_using_set(int arr[], int size) {
  set<int>  res;
  for(int i=0; i<size; i++)
    res.insert(arr[i]);

  for(auto itr:res)
    cout<< itr <<" ";
  cout<<"\n";
}

/* Method 2: */
void remove_duplicate(int arr[], int size) {

}

/* Method 3: */
void remove_duplicate_inplace(int arr[], size_t &size) {
  
}

int main() {
  int     arr[] = {1, 2, 1, 2, 3, 1, 2, 3, 4, 5, 3, 1};
  size_t  size  = sizeof(arr)/sizeof(arr[0]);
  cout<<"Array: ";
  /* Print array */
  for( size_t i=0; i<size; i++ ) 
    cout<< arr[i] <<" , ";
  cout<<"\n";
  /* Method 1 */
  cout<<"Method 1: ";
  remove_duplicate_using_set(arr, size);
  // cout<<"\n";
  // /* Method 2 */
  // cout<<"Method 2: ";
  // remove_duplicate(arr, size);
  // /* Method 3 */
  // cout<<"Method 3: original array: ";
  // print_array(arr, size);
  // remove_duplicate_inplace(arr, &size);
  // cout<<"Array After removing duplicates: ";
  // print_array(arr, size);
  return 0;
}
