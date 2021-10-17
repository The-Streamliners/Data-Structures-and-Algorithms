#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
  string s;
  cin>>s;

  int odd=0,even=0;
  for (int i = 0; i < s.length();i++)
  {
    // if i is even, position of digit is odd
    if(i&1){
      even+=s[i]-'0';
    }else{
      odd+=s[i]-'0';
    }

  }
  // difference is divisible by 11 or not
  if((odd-even)%11==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
