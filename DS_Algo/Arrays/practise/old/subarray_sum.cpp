/* Quest: Given an Array of non negative Integers and a number. You need to print 
 * all the starting and ending indices of Subarrays having their sum equal to the 
 * given integer.  
 *
 * For Example :- * Input-int[] arr = {2, 3, 6, 4, 9, 0, 11};
 * int num = 9    // sum
 * Output-
 * starting index : 1, Ending index : 2
 * starting index : 5, Ending index : 5
 * starting index : 5, Ending index : 6 */

#include "utility.h"

void find_subarray_indexes(int arr[], int size, int target_sum) {
  int start=0, end=0, sum=0;

  while( start<size && end<size ) {
    if( sum < target_sum ) {
      sum += arr[end];
      end++;
    } else if( sum > target_sum ) {
      sum -= arr[start];
      start++;
    } else{ // here sum == target_sum
      cout<< start <<" \t " << end-1 << endl;
      sum += arr[end];
      end++;
    }
  }
}

int main() {
  int arr[] = {2, 3, 6, 4, 9, 0, 11};
  int X, size=0;
  cout<<"Enter target sum to find subarray: ";    cin>> X;
  size = sizeof(arr)/sizeof(arr[0]);
  print_array(arr, size);
  cout<<"start and end indices of subarray that sums to "<< X <<" are: "<< endl;
  cout<<"start \t end" << endl;
  find_subarray_indexes(arr, size, X);
  return 0;
}
