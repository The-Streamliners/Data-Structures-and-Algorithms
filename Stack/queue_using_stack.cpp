#include <bits/stdc++.h> 
using namespace std;

# define size 1000
int top1=-1; 
int top2=-1;

int stack1[size];
int stack2[size];

bool isFull1()
{
    if (top1>=size-1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool isEmpty1()
{
    if (top1<0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void push1(int x)
{   
    if(isFull1())
    {
        cout << "Stack Overflow";
    }
    else
    {
        stack1[++top1]=x;
    }
}
int pop1()
{   
    if(isEmpty1())
    {
        cout << "Stack Underflow";
    }
    else
    {
        int x = stack1[top1];
        top1=top1-1;
        return x;
    }
}


bool isFull2()
{
    if (top2>=size-1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool isEmpty2()
{
    if (top2<0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void push2(int x)
{   
    if(isFull2())
    {
        cout << "Stack Overflow";
    }
    else
    {
        stack2[++top2]=x;
    }
}
int pop2()
{   
    if(isEmpty2())
    {
        cout << "Stack Underflow";
    }
    else
    {
        int x = stack2[top2];
        top2=top2-1;
        return x;
    }
}


void enqueue(int x)
{   
    int element1,element2;
    if(isEmpty1())
    {
        stack1[++top1]=x;

    }
    else
    {
        while(top1!=-1)
        {
            element1=pop1();
            push2(element1);

        }
        push2(x);
        int m=top2;
        while(top1!=m)
        {
            element2=pop2();
            push1(element2);

        }
    }
}

int peek() 
{ 
    if (top1 < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = stack1[top1]; 
        return x; 
    } 
} 

int dequeue()
{
    int x= pop1();
    return x;

}
int main() 
{   
    int x;

    while(true)
    {
        cout << "Enter 1 for enqueue\n";
        cout << "Enter 2 for dequeue\n";
        cout << "Enter 3 for top element\n";
        cin >> x;
        if(x==1)
        {   
            cout << "Enter no. to enqueue";
            int number;
            cin >> number;
            enqueue(number);

        }
        if(x==2)
        {   
            cout <<"Dequeued element is " << dequeue() << '\n';
        }
        if(x==3)
        {   
            cout <<"top element is" << peek() << '\n';
        }



    }
  
    return 0; 
} 