#include <iostream>
using namespace std;

int rodCut(int price[], int len){
    if(len<1)
    return 0;

    int val = INT8_MIN;
    for(int i=0;i<len;i++)
    val = max(val,price[i]+rodCut(price,len-i-1));

    return val;
}

int main(){
    int len;
    double x;
    cout<<"Enter value of len and x ";
    cin>>len>>x;
    if(x==0.50)
    len=len*2;
    if(x==0.25)
    len = len*4;
    if(x==0.20)
    len= len*5;

    int price[len];
    cout<<"Enter the prices: ";
    for(int i=0;i<len;i++)
    cin>>price[i];

    cout<<rodCut(price,len);
}