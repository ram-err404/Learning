/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    stack<int> s;
    int max_area;
    int tp;
    int area_with_top;
    int n=height.size();
    
    // Run through all bars.
    int i=0;
    while(i<n) {
        if(s.empty() || height[s.top()] <= height[i])
            s.push(i++);
        else {
            tp=s.top();
            s.pop();
            area_with_top=height[tp]*(s.empty()?i:i-s.top()-1);
            
            // update the max_area.
            if(max_area<area_with_top)
                max_area=area_with_top;
        }
    }
    
    //Now pop the remaining bars from stack & calculate area with every popped bar as smallest bar.
    while(!s.empty()) {
        tp=s.top();
        s.pop();
        area_with_top=height[tp]*(s.empty()?i:i-s.top()-1);
        
        // update the max_area.
        if(max_area<area_with_top)
        max_area=area_with_top;
    }
    return max_area;
}

int main() {
    vector<int> hist = {2,1,5,6,2,3};
    cout<<"Max histogram area: "<< maxArea(hist);
    return 0;
}
