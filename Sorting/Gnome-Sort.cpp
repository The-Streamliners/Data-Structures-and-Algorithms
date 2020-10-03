// A C++ Program to implement Gnome Sort 
// Contributed by Amit Zope
// github link :https://github.com/amitsat27
// userid : amitsat27
#include <iostream> 
using namespace std; 

// A function to sort the algorithm using gnome sort 
void gnomeSortFunc(int array[], int n) 
{ 
    // Intialising the index variable to 0
	int index = 0; 
    // Checking if index value is less than size of array
	while(index < n){   
		if(index == 0){ 
			index++; 
        }
        //  checks if present element is larger than previous element
        // if larger then goes to right of array increments index
		if(array[index] >= array[index - 1]){ 
			index++; 
        }
        // else if present element is smaller then 
        // it swaps the two elements and goes to left decrements index value
        else{ 
			swap(array[index], array[index - 1]); 
			index--; 
		} 
	} 
	return; 
} 

// A utility function ot print an array of size n 
void printSortedArray(int array[], int size) 
{ 
	cout << "Sorted Numbers after applying Gnome sort : "; 
	for (int i = 0; i < size; i++){
        cout<<array[i]<<" "; 
    } 
	cout<<"\n"; 
} 

// Driver program to test above functions. 
int main() 
{ 
	int array[] = {8,9,4,-3,5,6}; 
	int size = sizeof(array) / sizeof(array[0]); 
	gnomeSortFunc(array,size); 
	printSortedArray(array,size); 
	return (0); 
} 
