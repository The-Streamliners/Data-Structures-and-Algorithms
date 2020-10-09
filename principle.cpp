#include<iostream>
using namespace std;
int main()
{
	int p,v,n;
	float r;
	cout<<"enter the principle amount:";
	cin>>p;
	cout<<"enter the interest rate:";
	cin>>r;
	cout<<"enter the years:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		v=p*(1+r);
		p=v;
	}
	cout<<"the amount after "<<n<<" years="<<p;
	return 0;
}
