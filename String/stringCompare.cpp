#include<iostream>
#include<string.h>
using namespace std;
int main(){
	string s1 = "abc";
	string s2 = "ABC";
	int x = s1.compare(s2);
	if(x == 0)
		cout << "The two strings are equal" << endl;
	else if(x < 0)
		cout << s1 << " is less than " << s2 << endl;
	else
		cout << s1 << " is greater than " << s2 << endl;
	return 0;
}
