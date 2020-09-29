#include<iostream>
using namespace std;
void BUBBLE_SORT(int A[100], int n)
{
    int Start=0;
    int End=n-1;
    while(End!=Start)
    {
        int i=Start;
        while(i<End)
        {
            if(A[i+1]<A[i])
            {
                int temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
            }
            i=i+1;
        }
        End=End-1;
    }
    return;
}
int main()
{
    int A[]={4,5,6,1,3,8,2,7};
    int n=sizeof(A)/sizeof(A[0]);
    BUBBLE_SORT(A,n);
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
    return 0;

}
