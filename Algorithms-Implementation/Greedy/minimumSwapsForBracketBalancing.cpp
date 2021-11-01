/*

Input Constraints:
	String of even length consisting of only '[' and ']' brackets.
	Number of '[' == number of ']'

Input Example:
	[]][][
Output Example:
	2

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int open = 0, closed = 0;
	int swap = 0, mibalance = 0;

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '[')
		{
			open++;
			if(imbalance > 0)
			{
				swap += imbalance;
				imbalance--;
			}
		}
		else
		{
			closed++;
			imbalance = closed - open;
		}
	}

	cout << swap << endl;
}
