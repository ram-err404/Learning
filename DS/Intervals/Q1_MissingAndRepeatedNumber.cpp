// https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long Sn = (n*(n+1))/2;
	long long S2n = (n*(n+1)*(2*n+1))/6;
	long long S = arr[0];
	long long S2 = arr[0]*arr[0];

	for(int i=1; i<n; i++) {
		S += arr[i];
		S2 += arr[i]*arr[i];
	}

	// x-y = S-Sn
	long long val1 = S - Sn;
	// x^2 - y^2 = (S^2 - S^2 n)
	long long val2 = S2 - S2n;

	// x+y = (S^2 - S^2 n)/(x-y)
	// x-y = S-Sn						
	val2 = val2/val1;

	// x+y = val2
	// x-y = val1
	long long x = (val2+val1)/2;
	long long y = x-val1;					// x-y = val1
	
	return {(int)y, (int)x};
}

int main() {
    vector<int> arr {6, 4, 3, 5, 5, 1};

    pair<int, int> res = missingAndRepeating(arr, arr.size());

    cout<<"Missing Number: "<< res.first <<" Repeated Number: "<< res.second <<endl;
    return 0;
}