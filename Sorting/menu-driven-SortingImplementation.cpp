//GITHUB PROFILE ID : https://github.com/AviSharma1305
//GITHUB USER ID : AviSharma1305
// CODE FOR MENU DRIVEN SORTING METHODS
// INCLUDES SELECTION, BUBBLE, INSERTION SORTING METHODS RESP.

#include <bits/stdc++.h>
using namespace std;

//FUNCTION TO SORT THE ELEMENT USING SELECTION SORT ALGO
void selection_sort(vector<int> &v, int n){
    for(int i = 0; i < n-1; i++){
        int min_indx = i;
        for(int j = i; j < n; j++)
            if(v[min_indx] > v[j])
                min_indx = j;
        swap(v[i], v[min_indx]);
    }
}

//FUNCTION TO SORT THE ELEMENT USING BUBBLE SORT ALGO
void bubble_sort(vector<int> &v, int n){
    for(int i = 0; i < n-1; i++){
        bool flag = false;
        for(int j = 0; j < n-1-i; j++)
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                flag = true;
            }
        if(!flag)
            break;
    }
}

//FUNCTION TO SORT THE ELEMENT USING INSERTION SORT ALGO
void insertion_sort(vector<int> &v, int n){
    for(int i = 1; i < n; i++){
        int key = v[i];
        int j = i - 1;
        while(j > -1 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

//FUNCTION TO DISPLAY THE SORTED VECTOR
void display_Array(vector<int> &v ,int n)
{
     cout << "After Sorting: ";
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        v.clear();
}

//DRIVER CODE
int main(){
    int n, ch, x;
    vector<int> v(n);
    do{
        cout << "\n\tMENU\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Exit\nEnter your choice: "; //MENU FOR SORTING ALGOS
        cin >> ch;
        if(ch != 4){
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter Elements: ";
            for(int i=0;i<n;i++){
                cin >> x;
                v.push_back(x);
            }
        }
        if(ch == 1)   //SELECTION SORT
            {
                selection_sort(v, n);
                display_Array(v,n);
            }
        else if(ch == 2)  //BUBBLE SORT
            {
                bubble_sort(v, n);
                display_Array(v,n);
            }
        else if(ch == 3)  //INSERTION SORT
        {
            insertion_sort(v, n);
            display_Array(v,n);
        }
        else if(ch == 4)  //EXIT
            break;
        else
            {
                cout<<"Invalid Choice\n";
            }
        cout << "\n";
    } while(ch != 4);
    return 0;
}