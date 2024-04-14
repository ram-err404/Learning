// Az Coding Assessment Question 2.

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

/* Brute Force approach:  T(n,m,k) = O(n * (m + mlog(m)))
vector<int> kthMinimumInMSublists(vector<int> &arr, int m, int k) {
    vector<int> res;
    int n=arr.size();
    
    for(int i=0; i<=n-m; i++) {
        vector<int> temp;
        for(int j=i; j<m+i; j++) {
            temp.push_back(arr[j]);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp[k-1]);
    }
    return res;
} */

/* Optimised one: T(n,m,k) = O(n * m * log(k))*/
vector<int> kthMinimumInMSublists(vector<int> &arr, int m, int k) {
  int n=arr.size();
  vector<int> res(n - m + 1);
  for (int i = 0; i < n - m + 1; ++i) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store k smallest elements
    for (int j = i; j < i + m; ++j) {
      
    }
    res[i] = minHeap.top(); // kth minimum element from the current sublist
  }
  return res;
}

int main() {
    vector<int> arr{1,2,3,4,6,1,3};
    int m=5, k=2;

    vector<int> res = kthMinimumInMSublists(arr, m, k);
    
    for(int x:res)
        cout<< x <<" ";
    cout<<"\n";
    return 0;
}