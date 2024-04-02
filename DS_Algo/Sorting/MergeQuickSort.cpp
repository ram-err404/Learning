
#include <iostream>
#include <vector>

using namespace std;

// Quick Sort:
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i=low, j=low;
    for(; j < high; j++) {
        if(arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int partitionIdx = partition(arr, low, high);
        quickSort(arr, low, partitionIdx);
        quickSort(arr, partitionIdx + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    int low=0, high=arr.size()-1;
    quickSort(arr, low, high);
}

// Merge Sort:
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> res(high-low+1);
    int idx1=low, idx2=mid+1, idx3=0;
    while(idx1<=mid && idx2<=high) {
        if(arr[idx1] < arr[idx2]) {
            res[idx3] = arr[idx1++];
        } else {
            res[idx3] = arr[idx2++];
        }
        idx3++;
    }
    while(idx1 <= mid) {
        res[idx3++] = arr[idx1++];
    }
    while(idx2 <= high) {
        res[idx3++] = arr[idx2++];
    }
    
    // Now copy res to arr from low to high index.
    idx3=0; idx1=low;
    while(idx1 <= high) {
        arr[idx1++] = res[idx3++];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void mergeSort(vector<int> &arr) {
    int low=0, high=arr.size()-1;
    mergeSort(arr, low, high);
}

int main() {
    vector<int> arr{38,27,43,10};
    // vector<int> arr{38,27,43,10,78,85,12,96,700,51,35,65,41,14,23,32,97,450};
    // mergeSort(arr);
    quickSort(arr);
    
    for(int x:arr)
        cout<< x <<" ";
    return 0;
}