//A program to replace a word with another word in a paragraph
//Author:Khushi Gupta

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,word,newword;

	vector<string>paragraph;

	//Enter "00" at the end of paragraph

	while(cin >> s && s!="00")//Inputting different words of the paragraph
	{
		paragraph.push_back(s);
	}

	cin >> word; //Word to be replaced
	cin >> newword; //New word

	for(int i = 0 ; i < paragraph.size() ; i++)
	{
		if(paragraph[i]==word)
		{
			paragraph[i]=newword;
		}
	}


	cout<<"The changed paragraph is:\n";
	for(int i = 0 ; i < paragraph.size() ; i++)
	{
		cout << paragraph[i] <<" ";
	}


	return 0;
}
