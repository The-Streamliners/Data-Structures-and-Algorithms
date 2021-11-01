/*
    egyptianFraction.cpp by @harisfi on 03.10.2020

    a = numerator
    b = denominator

    sample input:
    6 14

    sample output:
    1/3 + 1/11 + 1/231
*/

#include <bits/stdc++.h>
using namespace std;

void fract(int a, int b) {
    if(b==0||a==0) return;
    if(b%a==0) {
        cout<<"1/"<<(b/a);
        return;
    }
    if(a%b==0) {
        cout<<(a/b);
        return;
    }
    if(a>b) {
        cout<<a/b<<" + ";
        fract(a/b, b);
        return;
    }
    int x=b/a + 1;
    cout<<"1/"<<x<<" + ";
    fract(a*x-b, b*x);
}

int main() {
    int a, b;

    cin>>a>>b;
    fract(a, b);
    return 0;
}