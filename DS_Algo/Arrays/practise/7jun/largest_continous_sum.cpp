#include <iostream>
using namespace std;

void print_array(int *array, int size) {
  for (int i=0; i<size; i++)
    cout<< array[i] <<" ";
  cout<<"\n";
}

int maxSubArraySum(int arr[], int size) {
  int start=0, end=0, max_sum=0;
  int i=0, sum=0;
  while(i<size) {
    sum += arr[i];
    if(sum<0) {
      sum=0;
      start=i+1;
    } else if(sum > max_sum) {
      max_sum = sum;
      end=i;
    }
    i++;
  }
  cout<< start <<" " << end <<"\n";
  return max_sum;
}

/*Driver program to test maxSubArraySum*/
int main() { 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]);
  
  print_array(a, n);
	
  int max_sum = maxSubArraySum(a, n); 
	cout << "Maximum contiguous sum is " << max_sum << endl; 
	return 0; 
}
