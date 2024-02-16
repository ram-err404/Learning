#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    
    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low<high) {
        int p=partition(arr, low, high);

        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    vector<int> arr={32,1,45,23,12,54,67,89,98,35,20};

    quickSort(arr, 0, arr.size()-1);
    printArr(arr);
    return 0;
}