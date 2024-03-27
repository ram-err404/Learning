// C++ program to print largest contiguous array sum 
#include<iostream> 
#include<climits> 
using namespace std; 

void print_array(int *array, int size) {
  for (int i=0; i<size; i++)
    cout<< array[i] <<" ";
  cout<<"\n";
}

int maxSubArraySum(int arr[], int size) {
  int max_so_far=INT_MIN, max_ending_here=0, start=0, end=0, s=0;

  for(int i=0; i<size; i++) {
    max_ending_here += arr[i]; 
    
    if(max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
      start=s;
      end=i;
    }
    if(max_ending_here < 0) {
      max_ending_here = 0;
      s = i+1;
    }
  }
  cout<<"Starting index: " << start <<" Ending index: " << end <<endl;
  return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main() 
{ 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]);
  
  print_array(a, n);
	
  int max_sum = maxSubArraySum(a, n); 
	cout << "Maximum contiguous sum is " << max_sum << endl; 
	return 0; 
} 
