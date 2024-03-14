#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPlatform(vector<int> &arr, vector<int> &dep) {
    int n=arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int platform=1, mxPlatform=1;
    int i=1, j=0;
    while(i<n && j<n) {
        if(arr[i] <= dep[j]) {
            platform++;
            i++;
        } else {
            platform--;
            j++;
        }

        mxPlatform = max(mxPlatform, platform);
    }
    return mxPlatform;
}

int main() {
    vector<int> arr{900, 940, 950, 1100, 1500, 1800};
    vector<int> dep{910, 1200, 1120, 1130, 1900, 2000};

    cout<<"Minimum platform required: "<<minPlatform(arr, dep)<<endl;
    return 0;
}