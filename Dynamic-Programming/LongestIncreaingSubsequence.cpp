#include<bits/stdc++.h> 
using namespace std; 
int longestIncreasingSubsequence( int arr[], int n ) 
{ 
	int LIS[n]; 

	LIS[0] = 1; 
	for (int i = 1; i < n; i++ ) 
	{ 
		LIS[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && LIS[i] < LIS[j] + 1) 
				LIS[i] = LIS[j] + 1; 
	} 
	int maximum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		maximum=max(maximum,LIS[i]);
	}
	return maximum;
} 
int main() 
{ 
	cout<<"Enter the size of array"<<endl;
	int n;
	cin>>n;
	int arr[n+1];
	cout<<"Enter the array elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	printf("Length of Longest Increaing Subsequence is %d\n", longestIncreasingSubsequence( arr, n ) ); 

	return 0; 
}
