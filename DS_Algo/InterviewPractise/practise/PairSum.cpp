#include<iostream>
#include<vector>
#include<set>
using namespace std;

void pairSum(vector<int> &arr, int target) {
    int n=arr.size();
    set<int> s;

    for(int i=0; i<n; i++) {
        if(s.find(target-arr[i]) == s.end()) {
            s.insert(arr[i]);
        } else {
            cout<<"Pair present: "<< arr[i] <<" and "<< target-arr[i] <<endl;
        }
    }
}

int main() {
    vector<int> arr={-40,-5,1,3,6,7,8,20};
    int target=15;

    pairSum(arr, target);
    return 0;
}