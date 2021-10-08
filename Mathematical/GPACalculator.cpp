#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
  string s;
  cin>>s;
  long double sum=0;
  int k=0;
  for (int i = 0; i < s.length(); ++i)
  {
     if(s[i]=='A'&&s[i+1]=='+'){
      k++;
      sum+=10;
   }
   else if(s[i]=='A')sum+=9;
   else if(s[i]=='B')sum+=8;
   else if (s[i]=='C')sum+=7;
   else if (s[i]=='D')sum+=6;
   else if(s[i]=='E')sum+=5;
  }
  sum=sum/(s.length()-k);
  cout<<sum<<endl;
}
