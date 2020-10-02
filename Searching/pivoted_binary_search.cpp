#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int low,int high,int key){
	if(high<low)
		return -1;
	
	int mid = (low+high)/2;
	if(a[mid]==key)
		return mid;
	else if(a[mid]<key)
		return binary_search(a,mid+1,high,key);
	else
		return binary_search(a,low,mid-1,key);
		
}

int pivoted_binary_search(int a[],int low,int high,int key){
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(a[mid] == key)
		return mid;
	else if(a[low]<a[mid] )			//sorted
	{
		if(key>=a[low] && key<=a[mid-1])
			return pivoted_binary_search(a,low,mid-1,key);
		else
			return pivoted_binary_search(a,mid+1,high,key);
	}
	else{
		if(key>=a[mid+1] && key<=a[high])
			return pivoted_binary_search(a,mid+1,high,key);
		else
			return pivoted_binary_search(a,low,mid-1,key);
	}
}

int main(){
	int a[] = {7,8,9,10,1,2,3,4,5,6};
	int n = 10;
	int key = 3245357;
	
	cout<<"index of key is "<<pivoted_binary_search(a,0,n-1,key);
}
