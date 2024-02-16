/* Question: Find all pairs of elements from an array whose sum is equal to given number.
 * Problem : Given a  array,we need to find all pairs whose sum is equal to number X.
 * For example: array[]={ -40, -5, 1, 3, 6, 7, 8, 20 };
 * Pair of elements whose sum is equal to 15 :  7, 8 and -5, 20 */

/* Sol: 
 *  --> Sort the array
 *  --> We will maintain two indexes one at beginning (l=0) and one at end (r=n-1)
 *  --> iterate until l <  r
 *  --> Check if arr[l] + arr[r] is equal to X
 *  --> if Yes, then print the pair and do l++, r–
 *  --> If arr[l] + arr[r] is less than X, this means if we want to find sum close to X, do l++
 *  --> If arr[l] + arr[r] is greater than X,this means if we want to find sum close to X , do r-- */

#include <iostream>
#define ARRAY_SIZE  8
using namespace std;

void sort(int *arr, int size) {
  int i, j, key;
  for(i=1; i<size; i++) {
    key=arr[i];
    j=i-1;
    while(arr[j] > key && j>=0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void print_array(int *arr, int size) {
  for(int i=0; i<size; i++) {
    cout<< arr[i] <<" ";
  }
  cout<<"\n";
}

void pair_sum_to_x(int *arr, int size, int x) {
  int l=0, r=size-1, sum=0;
  
  if(size < 2)
    return ;
  
  sort(arr, size);
  cout<<"Pair sum equals to "<< x <<": "<< endl;
  while(l < r) {
    sum = arr[l] + arr[r];
    if(sum == x)
      cout<< arr[l++] <<" , "<< arr[r--] << endl;
    else if(sum < x) 
      l++;
    else
      r--;
  }
}

int main() {
  int x=0;
  int array[] = { -40, -5, 1, 3, 6, 7, 8, 20 };
  cout<<"Enter value for X: ";  cin >> x;
  pair_sum_to_x(array, ARRAY_SIZE, x);
  return 0;
}
