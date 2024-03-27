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

/* Solution: We can maintain two pointers, start and end pointers which basically represents
 * a subarray and also we have to take a variable which stores the current sum of the
 * subarray starting from start pointer and ending at end pointer.
 *
 *  --> we keep on incrementing end pointer while adding the element in the current sum
 *      until we reach a point where our current running sum is more than required target
 *      sum, this basically means that the current subarray whose sum we’ve calculated is
 *      not the right answer.
 *  --> So now we alter our subarray by moving the start pointer, that is shortening the
 *      subarray and hence the current sum in the hope that we achieve the current sum
 *      equal to the required target sum.
 *  --> At every point we check if our current sum is equal to target sum or not, if this
 *      is the case we print our pointers.
 *  --> So basically we are altering the subarray by increasing start and end pointers and
 *      changing the current sum depending on its value as compared to target sum. */

#include <iostream>
using namespace std;

/* Function to print array. */
void print_array(int *arr, int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

/* Insertion sort. */
void sort(int *arr, int size) {
  int i=0, j=0, key=0;
  for(i=1; i<size; i++) {
    key = arr[i];
    j=i-1;
    while( key < arr[j] && j>=0 ) {
      arr[j+1] = arr[j];
      j--;    
    }
    arr[j+1] = key;
  }
}

void print_subarray(int *arr, int size, int target_sum) {
  int start=0, end=0, current_sum=0;
  
  print_array(arr, size);
  
  while( start<size && end<=size ) {
    if(current_sum == target_sum) {
      /* as the currSum is equal to target sum, print the 
		   * result with end as end-1.
		   * because when we added the element at end we
		   * increased the pointer there only,
		   * so now we need to subtract 1 because the 
		   * subarray constituting that sum has
		   * its last pointer one index where end is currently at.
		   */
      printf("arr[%d] , arr[%d]: %d , %d = %d \n", start, end-1, arr[start], arr[end-1], current_sum); 
		  if (end <= size - 1) {
		  	current_sum += arr[end];
		  }
		  end++;

    } else {
      /* if the currSum becomes more than required, 
			 * we keep on subtracting the start element
			 * until it is less than or equal to 
			 * required target sum. */
      if(current_sum > target_sum) {
        current_sum -= arr[start];
        start++;
      } else {
        /* we add the last element to our
				 * currSum until our 
				 * sum becomes greater than or
				 * equal to target sum. */
			  if (end <= size - 1)
			  	current_sum += arr[end];
			  end++;
      }
    }
  }
}

int main() {
  int arr[] = {2, 3, 6, 4, 9, 0, 11};
  int X, size=0;
  cout<<"Enter target sum to find subarray: ";    cin>> X;
  size = sizeof(arr)/sizeof(arr[0]);
  print_subarray(arr, size, X);
    
  return 0;
}
