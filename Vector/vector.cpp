#include<bits/stdc++.h>
using namespace std;

int main() {
    
    //Initializing a vector of int data type
           vector<int> v; 
    
    //Insert values in a vector using push_back()
    for (int i = 1; i <= 5; i++) 
        v.push_back(i); 
        
    //Printing the contents of a vector
    for (auto i = v.begin(); i != v.end(); ++i) 
        cout << *i << " "; 
    
    //Delete the last element of vector
         v.pop_back(); 
         
    //inserts new elements before the element at the specified position
         auto it = v.insert(v.begin(), 3); 
         
    // prints the vector size using size()
        cout << "\nSize : " << v.size(); 
    
    //Returns the maximum number of elements that the vector can hold
        cout << "\nCapacity : " << v.capacity(); 
    
    //Returns the size of the storage space currently allocated to the vector expressed as number of elements
        cout << "\nMax_Size : " << v.max_size();
    
    //checks if a vector is empty or not
        if (v.empty() == false) 
          cout << "\nVector is not empty"; 
        else
          cout << "\nVector is empty";
        
    //remove a element from a specified position
        it = v.begin(); 
        v.erase(it);
   
    //remove all the elements from the vector
        v.clear(); 
    
  return 0;
}
