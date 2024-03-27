#include <iostream>
using namespace std;

void print_array(int *arr, int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] << " ";
  cout<<"\n";
}

void remove_duplicate(int arr[], int size) {
  int narr[size] = {0};
  int k=0, j=0, i=0;

  for(i=0; i<size; i++) {
    for(j=0; j<k; j++) {
      if(arr[i] == narr[j])
        break;
    }
    if(j == k) {
      narr[k] = arr[i];
      k++;
    } // end inner-if
  } // end for
  
  /* Print array1 */
  for( int i=0; i<k; i++ ) 
    cout<< narr[i] <<" , ";
  cout<<"\n";

  // print_array(narr, k);
//  return narr;
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
  //remove_duplicate_using_set(arr, size);
  cout<<"\n";
  /* Method 2 */
  remove_duplicate(arr, size);
  // int n_arr_size = sizeof(n_arr)/sizeof(n_arr[0]);
  // cout<<"New array after removing repeating elements: " << endl;
  // print_array(n_arr, n_arr_size);
  return 0;
}
