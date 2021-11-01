//Parenthesis Checker Program

//Given an parenthesis expression string consisting of characters “{“,”}”,”(“,”)”,”[“,”]”
//The program examines whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
/*
sample input      =>  sample output
[()]{}{[()()]()}  =>  balanced
[{()}             =>  not balanced
[]()              =>  balanced
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code

    stack<char> s;
    //maintain a map to store required parenthesis pairs
    map<char, char> m = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
    string ip;
    cin >> ip;

    //Traverse the input string
    //Pop the element from the stack if the top of stack has the opposite parenthesis.
    //Else Push the element into the stack.
    for (int i = 0; i < ip.size(); i++)
    {
        char c = ip[i];
        if (!s.empty() && c == m[s.top()])
            s.pop();
        else
            s.push(c);
    }

    //If stack is empty then balanced else it is unbalanced .
    if (s.empty())
        cout<<"String "<<ip << " is balanced" << endl;
    else
        cout<<"String "<<ip << " is not balanced" << endl;

    return 0;
}