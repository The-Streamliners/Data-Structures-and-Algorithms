#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
 
    if (n1 != n2)
        return false;
 
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
 
    return true;
}
 
int main()
{
    char str1[20];
    cin.getline(str1,20);
    char str2[20];
    cin.getline(str2,20);
 
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
 
    return 0;
}
