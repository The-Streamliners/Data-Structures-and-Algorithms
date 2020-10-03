// A Simple C++ program to check if the 
// given word is a Palindrome
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to check Palindrome
bool isPalindrome(string str) 
{ 
    int n = str.length(); 
  
    // Start checking if the letters at symmetrically 
    //  opposite place is the same
    for (int i = 0; i < n / 2; i++) 
        if(str[i]!=str[n-1-i])
            return false;
        return true; 
} 
  
// Driver program 
int main() 
{ 
    string str = "radar"; 
    bool out;
    out=isPalindrome(str); 
    if(out)
        cout<<"The given word is a palindrome"; 
    else
        cout<<"The given word is NOT a palindrome";
    return 0; 
} 