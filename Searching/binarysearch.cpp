//Binary Search Implementation
//Author-Khushi Gupta

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int size,element;
	cin >> size;//Size of Array
	int a[size];

	for(int i=0 ; i < size; i++)
	{
		cin >> a[i];//Inputting the array
	}
	cin >> element; //To be found in the array

	sort(a , a + size); //Using STL algorithm for sorting array.Binary search works on in sorted arrays.

	int l = 0; //Left Index
	int r = size-1; //Right Index
	int check=0;
	while(l<=r)
	{
		int mid = l + ((r - l) / 2);

		if(a[mid] == element)
		{
			cout<<"Element found at " << mid + 1;
			check=1;
			break;
		}

		else if(a[mid] < element)
		{
			l = mid + 1;
		}

		else if(a[mid]>element)
		{
			r = mid;
		}
	}
	if(check == 0)
	cout<<"Element Does Not Exist In Given Array";
	return 0;
}
