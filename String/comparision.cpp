#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char str1[20], str2[20];
	int i = 0, a = 0;
	cout << "Enter string 1 : ";
	cin >> str1;
	cout << "Enter string 2 : ";
	cin >> str2;
	
	if(strlen(str1) != strlen(str2))
		return 0;
	else{
		while(str1[i] != '\0' || str2[i] != '\0'){
			if(str1[i] !=str2[i]){
				a = 1;
				break;
			}i++;
		}if(a == 0)
			cout << "The two entered strings are equal";
		else
		 	cout << "The two entered strings are not equal";
		cout << endl;
		return 0;
	}
}
