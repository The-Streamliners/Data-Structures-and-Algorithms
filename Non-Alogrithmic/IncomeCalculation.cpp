#include<bits/stdc++.h>
using namespace std;

int findtax(float arr[][2], int n, int salary)
{ 
int tax=0;
for(int i=0;i<n;i++)
{
  if(i==0)
  {
  	if(salary>=arr[i][1]){
  		salary=salary-arr[i][0];
  		tax+=(arr[i][0]*arr[i][1]/100);
	  }
	  else{
	  	tax+=(salary*arr[i][1]/100);
	  	salary=0;
	  }
  }
  else{
  	if(salary>(arr[i][0]-arr[i-1][0]))
  	  {
  		salary=salary-(arr[i][0]-arr[i-1][0]);
  	 	 tax+=((arr[i][0]-arr[i-1][0])*arr[i][1]/100);	
	  }
  	else{
  		tax+=(salary*arr[i][1]/100);
	  	salary=0;
	  }
  	
  }
	
}
  
return tax;		
}
int findincome(float arr[][2], int n, float paid)
{
    float income = 0;
    float temp;
    for(int i = 0; i < n; i++)
    {
        if(i==0)
        { temp = (arr[i][0] * arr[i][1] / 100.00);
		}
		else{
		 temp = ((arr[i][0]-arr[i-1][0]) * arr[i][1] / 100.00);	
		}

        if(paid > temp)
        {
        	if(i>0){
        		income = income + arr[i][0]-arr[i-1][0];
			}
			else{
				income = income + arr[i][0];
			}

            paid = paid - temp;

        }
        else
        {
            income += ((paid*100)/arr[i][1]);
            paid=0;
        }
    }
    return int(income);
}

int main()
{
    int n;
    cout << "Enter number of slabs" << endl;
    cin >> n;
    cout << "Enter Income(in rupees) and Income tax rate(in percentage)" << endl;
    float arr[n][2];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
      bool check;
    cout<<"If you want to check your salary from tax Press 1 or if you want to check tax from salary Press 0 "<<endl;
    cin>>check;
    if(check==1){
    int paid;
    cout << "Enter total tax paid(in rupees)" << endl;
    cin>>paid;
    cout <<"Your Income is " <<findincome(arr, n, paid);
	}
    else{
    	int salary;
    	cout<<"Enter your Income"<<endl;
    	cin>>salary;
    	cout<<"Total tax is "<<findtax(arr,n,salary);
	}
    return 0;
}
