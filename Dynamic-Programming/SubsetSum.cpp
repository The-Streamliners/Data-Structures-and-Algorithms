#include <bits/stdc++.h>

using namespace std;

bool subsetrec(int a[],int n,int x)
{
    if(n==0&&x==0)
    return true;
    if(n==0)
    return false;
    if(x==0)
    return true;
    if(a[n-1]<=x)
    {
        return subsetrec(a,n-1,x-a[n-1])||subsetrec(a,n-1,x);
    }
    else
    {
        return subsetrec(a,n-1,x);   
    }
}

int main() {
        int n;
        cout<<"Enter the size of array"<<endl;
        cin >> n;
        int a[n];
        cout<<"Enter the elements"<<endl;
        for (int i = 0; i < n; i++) 
        cin >> a[i];
        int targetsum;
        cout<<"Enter the target sum"<<endl;
        cin>>targetsum;
        if (subsetrec(a, n,targetsum))
            printf("YES\n");
        else
            printf("NO\n");
    return 0;
}
