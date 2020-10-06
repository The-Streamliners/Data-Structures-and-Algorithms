//program to implement the linear search algorithm

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int k) {
	for(int i=0;i<n;i++){
		if(arr[i]==k){
	            return i+1;
	        }
	}
	return -1;
}
int main()
{
    int arr[]={0,1,1,3,5,6,8,20,20,35,46,89};
    int k=35;
    int n= sizeof(arr)/sizeof(arr[0]);
    
    int index= search(arr,n,k);
    if(index==-1)
    {
        cout<<"Number not found\n";
    }
    else
    {
        cout<<"Number "<<k<<" is at index "<<index<<endl;
    }
    return 0;
}

