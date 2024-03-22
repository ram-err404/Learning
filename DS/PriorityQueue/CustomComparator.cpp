// priority_queue: with custom comparator.

#include <iostream>
#include <queue>

using namespace std;

template<class T>
class comparator{
public:
    /* We need to overwrite () operator. Since it need to compare the 2 values  */
    bool operator()(T a1, T a2) {
        // return a1>a2;   // acending order.
        return a1<a2;   // decending order.
    }
};

int main() {
    int arr[] = {10,4,5,90,12,9,6,94,1,2,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    // priority_queue<int, vector<int>, greater<int>> pq;  // min heap
    // priority_queue<int> pq;     // max heap
    
    priority_queue<int, vector<int>, comparator<int>>   pq;
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
    }
    
    while(!pq.empty()) {
        cout<< pq.top() <<" ";
        pq.pop();
    }
    cout<<"\n";
    return 0;
}