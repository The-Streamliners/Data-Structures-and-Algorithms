#include<bits/stdc++.h>
using namespace std;


#include <iostream>
using namespace std;

int linearsearch(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++) // simply iterate to all elements
        if (arr[i] == x) //if element found at some position
            return i;
    return -1; //element is not present in the array
}

int main()
{
    int arr[] = { 2, 9, 10, 11, 4, 12, 13, 15, 16, 16};
    int n = sizeof(arr) / sizeof(arr[0]); //array size
    int x = 11; //element to be searched
    int result = linearsearch(arr, n, x);
    if(result == -1)
    {
        cout << "Element Not found";
    }
    else
    {
        cout << "Element found at index " << result;
    }
}
