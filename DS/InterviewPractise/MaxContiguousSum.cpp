#include<iostream>
#include<vector>
using namespace std;

int maxContiguousSum(vector<int> arr) {
    int n=arr.size();
    int sum=0, mx=0, start=0, end=0, s=0;

    for(int i=0; i<n; i++) {
        sum += arr[i];

        if(sum<0) {
            s=i+1;  sum=0;
        }
        if(sum>mx) {
            mx=sum;
            start=s;
            end=i;
        }
    }
    return mx;
}

int main() {
    vector<int> arr{-2,-3,4,-1,-2,1,5,-3};

    cout<<"Contiguous Max sum: "<< maxContiguousSum(arr) <<endl;
    return 0;
}