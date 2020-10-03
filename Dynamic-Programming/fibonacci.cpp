// Fib(num) using Dynamic Programming with better space complexity of O(1)
//The time complexity is O(num)

#include<bits/stdc++.h> 
using namespace std; 



int fib(int num) 
{ 
	int num1 = 0, num2 = 1, c, i; 
	if( num == 0) 
		return num1; 
	for(i = 2; i <= num; i++) 
	{ 
	c = num1 + num2; 
	num1 = num2; 
	num2 = c; 
	} 
	return num2; 
} 

int main() 
{ 
	int num;

    cout << "Enter the value of num : ";
    cin >> num;
	
	cout << fib(num); 

	return 0; 
} 

//by arxxv

