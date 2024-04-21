#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxHistArea(vector<int> &arr) {
    stack<int> s;   // will keep pushing index in this stack.
    int n=arr.size();
    int i=0, top=0;
    int max_area=0, area=0;

    while(i<n) {
        if(s.empty() || arr[s.top()] < arr[i]) {
            s.push(i++);
        } else{
            // Now we have to pop the top and calculate the area with this top.
            top=s.top();
            s.pop();

            area = arr[top] * (s.empty()?i:i-s.top()-1);
            if(area>max_area)   max_area=area;
        }
    }

    while(!s.empty()) {
        top=s.top();
        s.pop();

        area = arr[top] * (s.empty() ? i : i-s.top()-1);
        if(area>max_area)   max_area=area;
    }
    return max_area;
}

int main() {
    vector<int> hist {2,1,5,6,2,3};

    cout<<"Max Histogram Area: " << maxHistArea(hist) <<endl;
    return 0;
}