//Program to find minimum number of coins that add up to given money
//Author:Khushi Gupta
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int money,n;
	cin >> money; //Total Money
	cin >> n;  //No of Coins
	int denomination[n];

	for(int i=0;i<n;i++)
	cin >> denomination[i];//Different value of Coins


	int number_of_coins = 0;

	long long int mincoins[money+1]={0};


	for( int i = 1 ; i <= money ; i++ )
	{
		mincoins[i]=LLONG_MAX;
		for( int j = 0 ; j < 3 ; j++ )
		{
			if(i >= denomination[j])
			{
				number_of_coins = mincoins[i-denomination[j]] + 1;
			}
			if(number_of_coins < mincoins[i])
			mincoins[i] = number_of_coins;

		}
	}


    cout << "Minimum Amount Of Coins Required:  ";
	cout << mincoins[money];
	return 0;
}
