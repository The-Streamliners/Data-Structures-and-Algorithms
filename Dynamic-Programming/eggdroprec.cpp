#include <bits/stdc++.h> 
using namespace std;  
int eggdroprec(int n, int k) 
{ 
	if (k == 1 || k == 0) 
		return k; 
	if (n == 1) 
		return k; 

	int minimum = INT_MAX;
	int res; 
	for (int x = 1; x <= k; x++) { 
		res = max(eggdroprec(n - 1, x - 1),eggdroprec(n, k - x)); 
		if (res < minimum) 
			minimum = res; 
	} 
	return minimum + 1; 
} 
int main() 
{ 
	
	int n,k;
	cout<<"Enter the Number of eggs"<<endl;
	cin>>n;
	cout<<"Enter the number of floors"<<endl;
	cin>>k;
	cout << "least number of trials required for "<< n << " eggs and " << k << " floors is "	<< eggdroprec(n, k) << endl; 
	return 0; 
} 
