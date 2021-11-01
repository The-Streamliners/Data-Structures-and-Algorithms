#include<iostream>
#include<string.h>
using namespace std;
int t[1001][1001];
int knapSackrecur(int w, int wt[],int val[],int n){
    if(n==0||w==0)
    return 0;
    if(t[n][w]!=-1)
    return t[n][w];
    if(wt[n-1]>w)
    {
		
		int x= knapSackrecur(w,wt,val,n-1);
		t[n][w]=x;
		return t[n][w];
	}
    else
    {
		int x= max(val[n-1]+knapSackrecur(w-wt[n-1],wt,val,n-1),knapSackrecur(w,wt,val,n-1));  
		t[n][w]=x;
		return t[n][w];
	} 
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
    memset(t,-1,sizeof(t));
    cout<<knapSackrecur(w,wt,val,n);

}
