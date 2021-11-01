// Bogosort applied on a user input array of integers
#include <bits/stdc++.h> 
using namespace std; 
  
bool isSorted(int a[], int n) 
{ 
    while (--n > 0) 
        if (a[n] < a[n - 1]) 
            return false; 
    return true; 
} 
  
void shuffle(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        swap(a[i], a[rand() % n]); 
} 
  
void bogosort(int a[], int n) 
{ 
    while (!isSorted(a, n)) 
        shuffle(a, n); 
} 
int main(){
    int n;
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    bogosort(nums, n);
    for(int x:nums) cout << x << " ";
    cout << endl;
}
