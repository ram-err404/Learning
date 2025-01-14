/*
K-Messed Array Sort
Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function sortKMessedArray that sorts arr. For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:
input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2
output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

input: arr = [6,1,4,11,2,0,3,7,10,5,8,9], k=6
output: [0,1,2,3,4,5,6,7,8,9,10,11]

T(N,k)  = O(N*log(k))   ==> log(k) for binary search.

--> There is 1 more approach:
    --> create a sliding window (k size) and maintain a min-heap to find the minimum of the value.
    Then keep the min at the ith index.
    T(N, k) = O(N*log(k))
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Approach 1: Failed (for TC: 2). as for some stage, after swapping, array maynot remain sorted.
#if 0
int search(vector<int>& arr, int low, int high) {
  int ans=INT_MAX;
  int minIdx=-1;
  
  while(low<=high) {
    int mid=(low+high)/2;
    if(arr[low]==arr[mid] && arr[mid]==arr[high]) {
      // need to shrink low and high both.
      if(arr[mid]<ans) {
        ans=arr[mid];
        minIdx=mid;
      }
      low++;  high--;
    }
    else if(arr[mid]>arr[high]) {
      // left side is sorted and maynot have the lowest, so answer may lie on the right.
      low=mid+1;
    } else {
      // ans may lie of the left;
      if(arr[mid]<ans) {
        ans=arr[mid];
        minIdx=mid;
      }
      high=mid-1;
    }
  }
  return minIdx;
}

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  vector<int> carr = arr;
  int size=arr.size();
  
  for(int i=0; i<size; i++) {
    int low=i+1;
    int high=(k+i>=size)?size-1:k+i;
    int minIdx = search(carr, low, high);
    if(minIdx>i && carr[minIdx] < carr[i]) {
      swap(carr[i], carr[minIdx]);
    }
  }
  return carr;
}
#endif

// Approach 2:
vector<int> sortKMessedArrayApproach2( const vector<int>& Arr, int k ) 
{
  vector<int> res = Arr;
  int n=Arr.size();
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int i=0;
  for(; i<=k; i++)
      minHeap.push(res[i]);
  
  int index=0;
  while(i<n) {
      res[index] = minHeap.top();
      minHeap.pop();
      minHeap.push(res[i]);
      i++;
      index++;
  }
  while(!minHeap.empty()) {
      res[index] = minHeap.top();
      minHeap.pop();
      index++;
  }
  return res;
}

int main() {
  // TC: 1
  // vector<int> arr{6,1,4,11,2,0,3,7,10,5,8,9};  k=6

  // TC: 2
  vector<int> arr{1,23,31,42,10,8,41,18,20,35,47};
  int k=10;
  // vector<int> res = sortKMessedArray(arr, k);
  // for(int x:res)
  //   cout<< x <<" ";
  // cout<< endl;
  vector<int> res;
  res = sortKMessedArrayApproach2(arr, k);
  for(int x:res)
    cout<< x <<" ";
  
  return 0;
}