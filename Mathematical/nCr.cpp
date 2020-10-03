
#include <bits/stdc++.h> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, r) 
int calculateComb(int n, int r, int** dpTable) 
{ 
	
	if (dpTable[n][r] != -1) 	 
		return dpTable[n][r]; // If value already in the dpTable table then return 

	
	if (r == 0) { 
		dpTable[n][r] = 1; // store the new value in the table if r==0
		return dpTable[n][r];  
	} 
	
	if (r == n) { 
		dpTable[n][r] = 1; // store the new value in the table if r==n
		return dpTable[n][r]; 
	} 
	
	
	dpTable[n][r] = calculateComb(n - 1, r - 1, dpTable) + calculateComb(n - 1, r, dpTable); //store the new number in the dpTable table 
	return dpTable[n][r]; 
} 

int createTable(int n, int r) //make the dpTable table to be used here initialize with -1 and pass to the calculateComb to find the value of nCr
{ 
	int** dpTable; 
	dpTable = new int*[n + 1]; 

	
	for (int i = 0; i < (n + 1); i++) { 
		dpTable[i] = new int[r + 1]; 
	} 

	
	for (int i = 0; i < (n + 1); i++) { 
		for (int j = 0; j < (r + 1); j++) { 
			dpTable[i][j] = -1; 
		} 
	} 

	return calculateComb(n, r, dpTable); 
} 


int main() 
{ 
	int n, r; 

    cin >> n >> r; 
	cout << n << "C" << r << " = " << createTable(n, r) << endl; 
	return 0; 
} 

