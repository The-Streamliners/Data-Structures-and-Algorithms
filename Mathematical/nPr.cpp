//runs in O(n)

#include<bits/stdc++.h> 
using namespace std; 

int nPr(int n, int r) 
{ 
	int fact[n + 1]; 

	// base case 
	fact[0] = 1; 

	// calculate value 
	// factorials up to n 
	for(int i = 1; i <= n; i++) 
	fact[i] = i * fact[i - 1]; 

	
	return fact[n] / fact[n - r]; 
} 


int main() 
{ 
	int n, r; 

    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Enter the value of r : ";
    cin >> r;
     
	
	cout << n << "P" << r << nPr(n, r); 

	return 0; 
} 