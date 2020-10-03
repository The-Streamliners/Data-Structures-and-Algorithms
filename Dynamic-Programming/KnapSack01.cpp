#include<iostream>
using namespace std;

int knapSackrecur(int w, int wt[],int val[],int n){
    if(n==0||w==0)
    return 0;
    if(wt[n-1]>w)
    return knapSackrecur(w,wt,val,n-1);
    else
    return max(val[n-1]+knapSackrecur(w-wt[n-1],wt,val,n-1),knapSackrecur(w,wt,val,n-1));   
}

int main(){
    int w,n;
    cout<<"Enter Weight and n"<<endl;
    cin>>w>>n;
    int wt[n];
    int val[n];
    cout<<"Enter weights"<<endl;
    for(int i =0;i<n;i++)
    cin>>wt[i];
    cout<<"Enter Values"<<endl;
    for(int i =0;i<n;i++)
    cin>>val[i];
    cout<<knapSackrecur(w,wt,val,n);

}