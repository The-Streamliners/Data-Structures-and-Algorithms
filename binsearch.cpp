#include<stdio.h>
#include<conio.h>
int binsearch(int a[],int l,int h,int item)
{ 
int mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid]==item)
		return (mid+1);
		else if(a[mid]>item)
		return binsearch(a,l,mid-1,item);
		else
		return binsearch(a,mid+1,h,item);
 	}
	
}
int main()
{
	int a[]={10,29,56,75,89,99};
	int n,r;
	printf("enter the element for searching:");
	scanf("%d",&n);
	r=binsearch(a,0,5,n);
	printf("element is at %d position",r);
	getch();
	return 0;
}
