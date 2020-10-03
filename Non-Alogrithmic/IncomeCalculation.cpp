#include<bits/stdc++.h>
using namespace std;

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
    int paid;
    cout << "Enter total tax paid(in rupees)" << endl;
    cin >> paid;
    cout << "Your Income is ";
    cout << findincome(arr, n, paid);
    return 0;
}

/*
output:

Enter number of slabs
3
Enter Income(in rupees) and Income tax rate(in percentage)
250000 0
500000 5
1000000 20
Enter total tax paid(in rupees)
44200
Your Income is 658500
-----------------------

*/
