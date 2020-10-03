//It's basically Bubble sort with some improvements
//But the time complexity is still O(n^2)

#include<bits/stdc++.h> 
using namespace std; 

int getNextGap(int gap) // Shriks gap by 1.3 (found by testing on large number of inputs)
{ 
	gap = (gap*10)/13; 

	if (gap < 1) 
		return 1; 

	return gap; 
} 


void combSort(int a[], int n) //the sorting function
{ 
	
	int gap = n; 

	
	bool swapped = true; 

	
	while (gap != 1 || swapped == true) //while the gap is greater than 1 
	{ 
		
		gap = getNextGap(gap); //shrink the gap using the above function

		
		swapped = false; 
 
		for (int i=0; i<n-gap; i++) 
		{ 
			if (a[i] > a[i+gap]) 
			{ 
				swap(a[i], a[i+gap]); 
				swapped = true; 
			} 
		} 
	} 
} 


int main() 
{ 
	int a[] = {100, 6, -5, 2, 87, 69, -65, 0, 8}; 
	int n = sizeof(a)/sizeof(a[0]); 

	combSort(a, n); 

	printf("Sorted array: \n"); 
	for (int i=0; i<n; i++) 
		printf("%d ", a[i]); 

	return 0; 
} 
