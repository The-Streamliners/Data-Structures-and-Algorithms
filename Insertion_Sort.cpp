#include<iostream>
using namespace std;
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   
   }
}
int main() {
   int n;
   cout << "Enter the number of elements in array ";
   cin >> n;
   int arr[n];    
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i = 0; i<n; i++)
      cout<<arr[i]<<" ";
   return 0;
}
