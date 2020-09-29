#include <bits/stdc++.h>
using namespace std;

#define int long long

//Euclidean Algorithm to compute gcd
// Algorithm to find LCM

int gcd(int a, int b)
{
   if (a == 0)
      return b;
   return gcd(b % a, a);
}
// complexity:
// O(1): best case
// O(logn) : worst case

int lcm(int a, int b)
{
   int g = gcd(a, b);
   return a / g * b;
   // this implementation prevents overflow in case
   // of large sized a and b
}

int32_t main()
{
   int a, b;
   cin >> a >> b;
   cout << "The required gcd is : " << gcd(a, b) << endl;
   cout << "The required lcm is : " << lcm(a, b) << endl;
}