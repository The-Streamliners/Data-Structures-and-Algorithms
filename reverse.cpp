#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	int a[6]={1,2,3,4,5};
	for(int i=0;i<2;i++)
	{
		int t;
		t=a[i];
		a[i]=a[4-i];
		a[4-i]=t;
	}
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<"  ";
	}
	getch();
	return 0;
}

