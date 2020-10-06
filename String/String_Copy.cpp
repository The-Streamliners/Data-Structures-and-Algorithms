// C++ program to implement strcpy() function to copy a string
// by Vaasu; GitHub: VaasuCodez
#include<iostream>
#include<string.h> 
using namespace std;
int main () 
{ 
    char s1[] = "First string!"; 
    char s2[] = "Second string!"; 
    char s3[50]; 
    char s4[50]; 
    char s5[] = "String 5!"; 
    cout << "string 1: " << s1 << "\nstring 2: " << s2 << "\nstring 3 & 4 are not initialized\nstring 5: " << s5 << endl; 
      
    strcpy(s2, s1); 
    strcpy(s3, "This text got inserted in string 3 successfully!"); 
    strcpy(s4, s5); 
    cout << "\nAfter using strcpy() function\n" << endl;
    cout << "string 1: " << s1 << "\nstring 2: " << s2 << "\nstring 3: " << s3 << "\nstring 4: " << s4 << "\nstring 5: " << s5 << endl; 
    return 0; 
}
