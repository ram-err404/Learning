/* Quest: Remove duplicate numbers from an integer array.
 * 
 * Sol: 
 *  Method 1: create set and add all the elements from the array in the set.
 *  Method 2: create another array and copy only non-repeating elements.
 * */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array(int *arr, int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

/* Method 1: create set from array elements. */
void remove_duplicate_using_set(int *arr, size_t size) {
  set<int>  s;
  for(size_t i=0; i<size; i++) {
    s.insert(arr[i]);
  }
  /* Print set. */
  for( set<int>::iterator it = s.begin(); it != s.end(); it++ )
    cout<< *it <<" , ";
  cout<<"\n";
}

/* Method 2: copy non repeated elements to another array. */
void remove_duplicate(int *arr, size_t size) {
  int arr1[size] = {0};
  size_t i=0, j=0, k=0;

  for (i = 0; i < size; i++) {
    for (j = 0; j < k; j++) {
      if (arr[i] == arr1[j])
        break;
    }
    if (j == k) {
      arr1[k] = arr[i];
      k++;
    }
  }
  /* Print array1 */
  for( size_t i=0; i<k; i++ ) 
    cout<< arr1[i] <<" , ";
  cout<<"\n";
}

/* Method 3: Remove repeated elements from the same array. */
void remove_duplicate_inplace(int arr[], int *size) {
  int i=0, j=0, k=0;

  for(i=0; i<*size; i++) {
    for(j=0; j<k; j++) {
      if(arr[i] == arr[j])
        break;
    }
    if(j == k) {
      if(k != i)
        arr[k] = arr[i];
      k++;
    }
  }
  *size=k;
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
  cout<<"\n";
  /* Method 2 */
  cout<<"Method 2: ";
  remove_duplicate(arr, size);
  /* Method 3 */
  cout<<"Method 3: original array: ";
  print_array(arr, size);
  remove_duplicate_inplace(arr, (int*)&size);
  cout<<"Array After removing duplicates: ";
  print_array(arr, size);
  return 0;
}
