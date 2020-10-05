#include <bits/stdc++.h> 
using namespace std; 
int lcsrec( string X,string Y, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;  
    if (X[m-1] == Y[n-1])  
        return 1 + lcsrec(X, Y, m-1, n-1);  
    else
        return max(lcsrec(X, Y, m, n-1), lcsrec(X, Y, m-1, n));  
}   
int main()  
{  
	cout<<"Enter the strings"<<endl;
	string X,Y;
	cin>>X>>Y; 
    int m = X.size();  
    int n = Y.size();  
      
    cout<<"Length of LongestCommonSubsequence is "<< lcsrec( X, Y, m, n )<<endl; ;  
      
    return 0;  
}  
