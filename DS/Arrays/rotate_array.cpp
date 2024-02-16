/* Quest: Rotate an array by k position. 
 * N=6 and k=2
 * If Arr[] = {1, 2, 3, 4, 5, 6} and k=2
 * then rotated array will be  {5, 6, 1, 2,  3,  4} */

#include <iostream>
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";  
}

/* Method 1: */
void right_rotate_array(int arr[], int size, int k) {
  int temp=0;
  k = k%size;
  for(int i=0; i<k; i++) {
    temp = arr[size-1];
    for(int j=size-1; j>0; j--)
      arr[j] = arr[j-1];
    arr[0] = temp;
  }
}

/* Method 2: Use juggling algorithm. */
int find_gcd(int a, int b) {
  if (b==0)
    return a;
  find_gcd(b, a%b);
}

void left_rotate_using_juggling_algo(int arr[], int size, int k) {
  int i, j, l, temp;
  k = k%size;   // for k > size;
  int gcd = find_gcd(k, size);

  for(i=0; i<gcd; i++) {
    temp = arr[i];
    j = i;
    while(1) {
      l = j+k;
      if(l >= size)
        l = l-size;
      if(l==i)
        break;
      arr[j] = arr[l];
      j = l;
    }
    arr[j] = temp;
  }
}

void right_rotate_using_juggling_algo(int arr[], int size, int k) {
  int temp, i, j, l;
  k = k%size;   // for k > size
  
  int gcd = find_gcd(k, size);
  for(i=0; i<gcd; i++) {
    j=size-1-i;
    temp = arr[j];
    while(1) {
      l = j-k;
      if(l < 0)
        break;
      arr[j] = arr[l];
      j = l;
    } // end while loop
    arr[j] = temp;
  } // end for loop
}

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  // for(int i=0; i<1000000; i++)
  //   arr[i] = i+1;
  int size = sizeof(arr)/sizeof(arr[0]);
  int k=4;    // Number of times to rotate an array.
  cout<<"Original array: ";
  print_array(arr, size);
  
  right_rotate_using_juggling_algo(arr, size, k);
  cout<<"Array after ratating " << k <<" times right: ";
  print_array(arr, size);
  
  // left_rotate_using_juggling_algo(arr, size, k+2);
  // cout<<"Array after rotating "<< k+2 <<" times left: ";
  // print_array(arr, size);
  return 0;
}
