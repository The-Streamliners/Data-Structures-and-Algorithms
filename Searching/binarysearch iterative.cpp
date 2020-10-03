#include<bits/stdc++.h>
using namespace std;


#include <iostream>
using namespace std;

int binarysearch(int *arr, int n, int x)
{
    //array should be sorted
    int mid = 0;
    int s = 0;
    int e = n;

    int iterations = log2(n);//as binary search takes logn time


    for(int i = 0; i <= iterations; i++)
    {

        mid = (s + e) / 2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] > x)
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 2, 5, 7, 12, 15, 16, 18, 21};
    int n = sizeof(arr) / sizeof(arr[0]); //array size
    int x = 21; //element to be searched
    int result = binarysearch(arr, n, x);
    if(result == -1)
    {
        cout << "Element Not found";
    }
    else
    {
        cout << "Element found at index " << result;
    }
}
