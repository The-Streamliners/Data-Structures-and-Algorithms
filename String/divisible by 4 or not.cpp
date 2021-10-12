#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {

  string s;
  cin>>s;
  // A Number is Divisble by 4 if last two digits Divisble by 4
  int a;

  if(s.length()>=2){
    a=(s[s.length()-2]-'0')*10+(s[s.length()-1]-'0'); // last two digits
  }else{
    a=s[0]-'0'; // single integer
  }

  if(a%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  } 
  
}
