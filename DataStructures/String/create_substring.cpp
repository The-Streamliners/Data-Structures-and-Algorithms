// A Simple C++ program to create a substring without using any inbuilt function
#include <bits/stdc++.h>
using namespace std;

// Function
string create_substring(string str,int from,int to)
{
    string out;
    for(int i=from;i<=to;i++){
        out.push_back(str[i]);
    }
    return out;
}

// Driver program
int main()
{
    string str = "Ilovegithub";
    string substring=create_substring(str,2,5);
    cout<<substring;
    return 0;
}
