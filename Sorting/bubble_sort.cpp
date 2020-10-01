#include<iostream>
using namespace std;
void BUBBLE_SORT(int A[100], int n)
{
    int i,j;
    bool swap;
    for(int i=0;i<n-1;i++)
    {
        swap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
                swap=true;
            }
        }
        if(swap==false)
        {
            break;
        }
    }
    return;


}

int main()
{
    int A[]={4,5,6,1,3,8,2,7};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<n<<endl;
    BUBBLE_SORT(A,n);
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
    return 0;

}
