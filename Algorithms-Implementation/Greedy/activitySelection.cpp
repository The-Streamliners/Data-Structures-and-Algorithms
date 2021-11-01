/*
    activitySelection.cpp by @harisfi on 03.10.2020

    n = sum of activities
    s[] = start time for each activities
    f[] = finish time for each activities

    sample input:
    6
    1 3 0 5 8 5
    2 4 6 7 9 9

    sample output:
    0 1 3 4 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ac;
    cin>>n;

    int s[n-1], f[n-1];
    for (int i = 0; i < n; i++) cin>>s[i];
    for (int i = 0; i < n; i++) cin>>f[i];
  
    ac = 0;         // always select first activity
    cout<<ac<<" ";

    for (int j = 1; j < n; j++) {
      if (s[j] >= f[ac]) {
          cout<<j<<" ";
          ac = j;
      }
    }
    return 0;
}