// C++ program to Count Inversions 
// in an array 
#include <bits/stdc++.h> 
using namespace std; 

int getInvCount(int arr[], int n) 
{ 
	int inv_count = 0; 
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) 
			if (arr[i] > arr[j]) 
				inv_count++; 

	return inv_count; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 84, 2, 37, 3, 67, 82, 19, 97, 91, 63, 27, 6, 13, 90, 63, 89, 100, 60, 47, 96, 54, 26, 64, 50, 71, 16, 6, 40, 84, 93, 67, 85, 16, 22, 60 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << " Number of inversions are "
		<< getInvCount(arr, n); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 
