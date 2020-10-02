//program to implement the jump search algorithm

#include<bits/stdc++.h>
using namespace std;


int jumpsearch(int a[],int x,int n)
{
    int step = sqrt(n);
    int previous = 0;

    while(a[min(step,n)-1] < x)
    {
        previous = step;
        step += sqrt(n);
        if(previous >= n)
        {
            return -1;
        }
    }

    while(a[previous] < x)
    {
        previous++;

        if(previous == min(step,n))
        {
            return -1;
        }
    }

    if(a[previous] == x)
    {
        return previous;
    }

    return -1;
}


int main()
{
    int a[]={0,1,1,3,5,6,8,20,20,35,46,89};
    int x=35;
    int n= sizeof(a)/sizeof(a[0]);
    
    int index= jumpsearch(a,x,n);
    if(index==-1)
    {
        cout<<"Number not found\n";
    }
    else
    {
        cout<<"Number "<<x<<" is at index "<<index<<endl;
    }
    return 0;
}