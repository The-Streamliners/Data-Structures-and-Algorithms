#include <bits/stdc++.h>
using namespace std;
int OptimalStrategy(int arr[], int l, int r, int sum)
{
	if (r == l + 1)
		return max(arr[l], arr[r]);
	return max((sum - OptimalStrategy(arr, l + 1, r, sum - arr[l])),(sum - OptimalStrategy(arr, l, r - 1, sum - arr[r])));
}
int main()
{
	cout<<"Enter the number of coins"<<endl;
	int n;
	cin>>n;
	cout<<"Enter the value of coins"<<endl;
	int arr[n+1];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<"Optimal value player can obtain "<< OptimalStrategy(arr,0,n-1,sum)<<endl;


	return 0;
}
