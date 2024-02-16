/* Q: You are given arrival and departure time of trains reaching to a particular
 *  station. You need to find minimum number of platforms required to accommodate
 *  the trains at any point of time.
 *
 *  arrival[] = {1:00, 1:40, 1:50, 2:00, 2:15, 4:00} 
 *  departure[] = {1:10, 3:00, 2:20, 2:30, 3:15, 6:00}
 *  No. of platforms required in above scenario = 4.
 */

/* Sol: We will use logic very much similar to merge sort.
 *  --> Sort both arrival(arr) and departure(dep) arrays.
 *  --> Compare current element in arrival and departure array and pick smaller one among both.
 *  --> If element is pick up from arrival array then increment platform_needed.
 *  --> If element is pick up from departure array then decrement platform_needed.
 *  --> While performing above steps, we need track count of maximum value reached for platform_needed.
 *  --> In the end, we will return maximum value reached for platform_needed.
 *  
 *  Time complexity : O(NLogN)
 * */

#include <iostream>
using namespace std;

#define ARRAY_SIZE  6

void print_array(int *array, int size) {
  for(int i=0; i<size; i++)
    cout<< array[i] <<" ";
  cout<<"\n";
}

void sort(int *array, int size) {
  /* Using insertion sort technique. */
  int i, j, key;
  
  for(i=1; i<size; i++) {
    key = array[i];
    j = i-1;
    while(key < array[j] && j>=0) { 
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}

int platformRequired(int *arrival, int arr_size, int *departure, int dep_size) {
  int platform_needed=0;
  int max_platform=-1;
  int i=0, j=0;
  sort(arrival, arr_size);
  // print_array(arrival, arr_size); 
  sort(departure, dep_size);
  // print_array(departure, dep_size);

  while(i<arr_size && j<dep_size) {
    if(arrival[i] < departure[j]) {
      platform_needed++;
      i++;
      if(platform_needed > max_platform)
        max_platform = platform_needed;
    }
    else {
      platform_needed--;
      j++;
    }
    // cout<<"i: "<< i <<" j: "<< j <<" platform_needed: "<< platform_needed <<" max_platform: " << max_platform <<endl;
  }
  return max_platform;
}

int main() {
  int arr[] = {100, 140, 150, 200, 215, 400};
	int dep[] = {110, 300, 210, 230, 315, 600};

  cout<<"Platform required: " << platformRequired(arr, ARRAY_SIZE, dep, ARRAY_SIZE) << endl;
  return 0;
}
