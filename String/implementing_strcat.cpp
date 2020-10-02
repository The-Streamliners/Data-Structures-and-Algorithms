// A Simple C++ program to implement strcat function
#include <bits/stdc++.h>
using namespace std;

// Function
void strcat_implement(string& dest,string& src)
{
    for(int i=0;i<src.length();i++){
        dest.push_back(src[i]);
    }
}

// Driver program
int main()
{
    string dest = "Learning C++ is fun";
    string src = " and easy";

    strcat_implement(dest, src);

    cout << dest ;

    return 0;

}
