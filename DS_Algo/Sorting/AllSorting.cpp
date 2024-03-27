#include <iostream>
using namespace std;

void print_array(int *arr, int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

void swap(int &x, int &y) {
    x=x+y;
    y=x-y;
    x=x-y;
}

void selection_sort(int *arr, int n) {
    int min=0;
    for(int i=0; i<n-1; i++) {
        min=i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[min])
                min=j;
        }
        if(arr[i]!=arr[min])
            swap(arr[i], arr[min]);
    }
}

void bubble_sort(int *arr, int n) {
    for(int i=0; i<n;i++) {
        for(int j=0; j<n-1; j++) {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void insertion_sort(int *arr, int n) {
    int key;
    int j;
    for(int i=1; i<n; i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// mergesort
void merge(int *arr, int l, int mid, int r) {
    int *newArr = new int[r-l+1];
    
    // declare crawler indices.
    int i=l, j=mid+1, k=0;
    while(i<=mid && j<=r) {
        if(arr[i]<=arr[j]) {
            newArr[k]=arr[i];
            k++; i++;
        } else {
            newArr[k]=arr[j];
            k++; j++;
        }
    }
    
    // add the remaining elements to either of left/right of mid.
    while(i<=mid) {
        newArr[k]=arr[i];
        k++; i++;
    }
    while(j<=r){
        newArr[k]=arr[j];
        k++; j++;
    }
    // copy from newArr to original array;
    for(int i=l; i<=r; i++)
        arr[i]=newArr[i-l];
    
    delete[] newArr;
    
}

void mergesort(int *arr, int l, int r) {
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

// Quick Sort
int partition(int *arr, int low, int high) {
    int pi=arr[high];
    int i=low-1;    // Smallest index.
    
    for(int j=low; j<high; j++) {
        if(arr[j]<pi) {
            i++;
            if(arr[j] != arr[i])
                swap(arr[j], arr[i]);
        }
    }
    if(arr[i+1] != arr[high])
        swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int *arr, int low, int high) {
    if(low<high) {
        int pi=partition(arr,low,high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main() {
    int arr[]={2,1,7,4,3};
    
    // selection_sort(arr, 5);
    // bubble_sort(arr, 5);
    // insertion_sort(arr, 5);
    // mergesort(arr, 0, 4);
    quickSort(arr, 0, 4);
    print_array(arr, 5);
    return 0;
}
