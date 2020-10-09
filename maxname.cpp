#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
class name
{
	char name[20];
	int l[3];
   public:
   	void getname()
   	{
   		cout<<"\nenter name:";
   		gets(name);
	}
	void display()
	{
       
		cout<<"\nname="<<name;
	}
	  void length(int i)
	{ 
	    l[i]=strlen(name);
	   // int maxidx=max();
	    cout<<"\nlength="<<l[i];					
	}
	int max(int l[])
	{
	   for(int i=0;i<1;i++)
	   {
	   	int maxidx=i;
		   for(int j=i+1;j<3;j++)
		   {
		      if(l[j]>l[maxidx])
			  maxidx=j;	
		   }
		   return maxidx;
	   }
	}
	void printm()
	{
		int maxidx=max(l);
		cout<<"max length name index="<<maxidx;
	}
};
main()
{
	name n[3];
	for(int i=0;i<3;i++)
	{
		n[i].getname();
	    //n[0].display();
        n[i].length(i);	
	}
	
	getch();
	return 0;
}
