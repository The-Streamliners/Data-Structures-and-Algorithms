// A Simple C++ program to check spaces in a string
#include <bits/stdc++.h>
using namespace std;

// Function
void check_space(string& str)
{
    if (str.find (' ') != string::npos)
    {
        cout  << "Contains at least one space!" << endl;
    }
    else
    {
        cout  << "Does not contain any spaces!" << endl;
    }
}

// Driver program
int main()
{
    string dest = "Learning C++ is fun";
    check_space(dest);


    return 0;

}
