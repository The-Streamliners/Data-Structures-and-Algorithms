

/*
Contributer:
            Github Username: ultimatecoder2
            Name: Deepanshu Jindal
*/

/*
    Problem: Converting an infix expression to postfix expression


    Approach: Here we will make a stack that will store operators.
    If stack is empty, then we willpush operator in stack
    Now when the precedence of the operator on the top of the stack is greater than the new encountered operator then we pop the operator and insert it to the postfix string. Then we push the newly encountered one operator into stack.
    else we just insert the operator in the stack.
    Now Whenever we encounter an opening parantheses then we just insert it in the stack as acc to BoadMass rule, brackets should be solved first.

    If we encounter a closing paranthesses i.e. ')' then we pop all the operators till we encountered a '('.

    Sample Case 1: 3+5*3
    Soln 1:353*+
    Sample Case 2: 3*9-8
    Soln 1:39*8-

*/
#include<bits/stdc++.h>
using namespace std;
bool isoperator(char ch)
{
    //returns true if we get an operator
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return 1;
    else
        return 0;
}

bool checkPrecedence(char op1,char op2)
//Here op1 and op2 are 2 operators.
//We return 1 if precedence of op2 > precedence of op1
{// We know precedence '(' < '+','-' <' *', '/' < '^' < ')'
    if(op2=='(')
    {
        return(0);
    }
    else
    {
        if(op1=='+'||op1=='-')
        {return(1);}//if precedence of incoming is less or equal
        else if(op1=='*'||op1=='/')
        {
            if(op2=='+'||op2=='-')
                return(0);
            else
                return(1);//if precedence of incoming is less or equal
        }
        else
        {
            if(op2=='^')
                return(1);
            else
                return (0);
        }
        }
}

int main()
{
    stack<char> operatorStack;
    string postfix="",infix;
    int len;
    bool IsOperator,isGreaterPrecedence;
    cout<<"Enter Infix string"<<endl;
    cin>>infix;
    len=infix.length();

    for(int i=0;i<len;i++)
    {
        //Check for each element in the infix string and perform the required steps as per discussed approach
        if(infix[i]=='(')//Directly push to stack
            operatorStack.push('(');
        else if(infix[i]==')')
        {
            // pop all the operators till we encountered a '('
            while((operatorStack.top()!='('))
            {
                postfix+=operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else
        {
            IsOperator=isoperator(infix[i]);
            if(IsOperator==0)
            {
                //As not an operator. So add it to postfix string
                postfix+=infix[i];
            }
            else
            {

                if(operatorStack.empty())
                    operatorStack.push(infix[i]);
                else
                {
                    //Here we check precedence
                    isGreaterPrecedence=checkPrecedence(infix[i],operatorStack.top());
                    if(isGreaterPrecedence==1)
                    { //Here precedence of
                        while(isGreaterPrecedence==1 && operatorStack.empty()==0 && (operatorStack.top()!='('))//if precedence of incoming is less or equal
                        {
                            postfix+=operatorStack.top();
                            operatorStack.pop();
                            if(!operatorStack.empty())
                            isGreaterPrecedence=checkPrecedence(infix[i],operatorStack.top());
                        }
                    }
                    operatorStack.push(infix[i]);
                }
            }
        }
    }

    //If any operator left in stack then we add it to the end of the string
    while(!operatorStack.empty())
    {
        if(operatorStack.top()!='(')
            postfix+=operatorStack.top();
        operatorStack.pop();
    }
    cout<<postfix<<endl;
    return 0;
}
