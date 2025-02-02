// CPP program to print equal sum two subsets of 
// an array if it can be partitioned into subsets. 
#include <bits/stdc++.h> 
using namespace std; 

/// Function to print the equal sum sets of the array. 
void printSets(vector<int> set1, vector<int> set2) 
{ 
	int i; 

	/// Print set 1. 
	for (i = 0; i < set1.size(); i++) { 
		cout << set1[i] << " "; 
	} 

	cout << "\n"; 

	/// Print set 2. 
	for (i = 0; i < set2.size(); i++) { 
		cout << set2[i] << " "; 
	} 
} 

/// Utility function to find the sets of the array which 
/// have equal sum. 
bool findSets(int arr[], int n, vector<int>& set1, 
			vector<int>& set2, int sum1, int sum2, int pos) 
{ 

	/// If entire array is traversed, compare both the sums. 
	if (pos == n) { 

		/// If sums are equal print both sets and return 
		/// true to show sets are found. 
		if (sum1 == sum2) { 
			printSets(set1, set2); 
			return true; 
		} 

		/// If sums are not equal then return sets are not 
		/// found. 
		else
			return false; 
	} 

	/// Add current element to set 1. 
	set1.push_back(arr[pos]); 

	/// Recursive call after adding current element to set 1. 
	bool res = findSets(arr, n, set1, set2, sum1 + arr[pos], 
						sum2, pos + 1); 

	/// If this inclusion results in equal sum sets partition 
	/// then return true to show desired sets are found. 
	if (res) 
		return res; 

	/// If not then backtrack by removing current element 
	/// from set1 and include it in set 2. 
	set1.pop_back(); 
	set2.push_back(arr[pos]); 

	/// Recursive call after including current element to set 2. 
	res = findSets(arr, n, set1, set2, sum1, sum2 + arr[pos], 
				pos + 1); 
	if (res == false) 
		if (!set2.empty()) 
			set2.pop_back(); 

	return res; 
} 

/// Return true if array arr can be partitioned 
/// into two equal sum sets or not. 
bool isPartitionPoss(int arr[], int n) 
{ 
	/// Calculate sum of elements in array. 
	int sum = 0; 

	for (int i = 0; i < n; i++) 
		sum += arr[i]; 

	/// If sum is odd then array cannot be 
	/// partitioned. 
	if (sum % 2 != 0) 
		return false; 

	/// Declare vectors to store both the sets. 
	vector<int> set1, set2; 

	/// Find both the sets. 
	return findSets(arr, n, set1, set2, 0, 0, 0); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 5, 5, 1, 11 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (!isPartitionPoss(arr, n)) { 
		cout << "-1"; 
	} 
	return 0; 
}
