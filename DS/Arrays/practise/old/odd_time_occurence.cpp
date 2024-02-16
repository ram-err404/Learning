#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}
vector<int> getAllOddTimesUsingMap(int arr[], int size) {
  unordered_map<int, int>   hash;
  vector<int>               result;
  for(int i=0; i<size; i++)
    hash[arr[i]]++;

  for(auto itr:hash) {
    if(itr.second%2 != 0)
      result.push_back(itr.first);
  }
  return result;
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
