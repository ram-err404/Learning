
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    if(left > right)    return -1;

    int mid = (left+right)/2;
    if(arr[mid] == target)  return mid;

    // check left part is sorted.
    if(arr[mid] > arr[left]) {
        if(target >= arr[left] && target < arr[mid]) {
            return binarySearch(arr, left, mid-1, target);
        }
        return binarySearch(arr, mid+1, right, target);
    }
    
    // right part is not sorted
    if(target > arr[mid]) {
        // move mid+1 to high
        return binarySearch(arr, mid+1, right, target);
    }
    // otherwise
    return binarySearch(arr, left, mid-1, target);
}

int getElementIndex(vector<int> &arr, int target) {
    int n=arr.size();
    return binarySearch(arr, 0, n-1, target);
}

int main() {
    // vector<int> arr {4,5,6,7,1,2,3};
    // int target=2;

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        int target;
        cin >> target;

        int res = getElementIndex(arr, target);
        if(res!=-1)     cout<<"Found at index: "<< res <<endl;
        else            cout<<"Not Found" << endl;
    }
    return 0;
}