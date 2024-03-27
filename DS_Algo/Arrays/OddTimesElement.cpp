/* Q:1.) Find number occuring odd number of times in an array. 
 * Note: only one number is occuring odd times. Otherwise solution will not work. 
 */

#include <iostream>
#include <bits/stdc++.h>
#define ARRAY_SIZE  13
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

/* Method1: Do bitwise XOR operation for all elements & it will give you elements which
 * occurs odd no. of times in the end.
 * This method will only work when just one number occurs odd times. */
int getOddTimesElement(int *array, int size) {
  int i=0, result=0;
  /* Do bitwise XOR operation for all elements & it will give you elements which
   * occurs odd no. of times in the end. */
  for(i=0; i<size; i++) {
    result = result ^ array[i];
  }
  return result;
}

/* Method2: */
void getAllOddTimesElements(int arr[], int size) {
  int Xor = 0;

	for (int i = 0; i < size; i++) {
    Xor ^= (1 << arr[i]);
  }
	printf("The odd occurring elements are: ");
	for (int i = 0; i < size; i++)
	{
		if (Xor & (1 << arr[i]))
		{
			printf("%d ", arr[i]);
			Xor ^= (1 << arr[i]); // to avoid printing duplicates
		}
	}
}

/* Method3: create map of array_elements and its frequency. */
vector<int> getAllOddTimesUsingMap(int arr[], int size) {
  // Defining HashMap
  unordered_map<int, int>   hash;
  vector<int>               repeating_elements;

  for(int i=0; i<size; i++)
    hash[arr[i]]++;
  
  for(auto itr : hash) {
    if(itr.second % 2 != 0)
      repeating_elements.push_back( itr.first );
  }
  return repeating_elements;
}

int main() {
  int arr[] = {20, 40, 50, 40, 50, 20, 30, 30, 50, 20, 40, 40, 20, 30};
  int size = sizeof(arr)/sizeof(arr[0]);
  // cout<<"Number occuring odd number of times: " << getOddTimesElement(arr, size) << endl;
  // getAllOddTimesElements(arr, size);
  print_array(arr, size);

  vector<int> result = getAllOddTimesUsingMap(arr, size);
  cout<<"Odd occurring Elements are: ";
  for(auto itr : result)
    cout<< itr <<" ";
  cout<<"\n";
  return 0;
}
