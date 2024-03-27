#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int size) {
  for(int i=0; i<size; i++)
    cout<< arr[i] <<" ";
  cout<<"\n";
}

template <class T>
void print_vector(vector<T> vec) {
  for(auto itr:vec)
    cout<< itr <<" ";
  cout<<"\n";
}

void sort(int arr[], int size) {
  int i,j,key;
  for(i=1; i<size; i++) {
    key=arr[i];   j=i-1;
    while(arr[j] > key && j>=0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
