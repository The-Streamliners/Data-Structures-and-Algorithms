/*
Contributer:
            Github Username: ultimatecoder2
            Name: Deepanshu Jindal
*/




#include<bits/stdc++.h>
using namespace std;
/*
Problem: Implement two stacks using a single array.

Approach:
    One stack will start from the starting of the array and other will start from the ending of the array.
    So that we can utilize the whole array properly.
*/

class Stack
{
    //Creating a class which will store all operations and define stack Data Structure


    int total_size; //It will store the total size of array
    int fe;//fe store the index of last element inserted in 1st stack(On left side of array)
    int be; //be store the index of last element inserted in 2nd stack(On right side of array)
    int *arr;


public:
    Stack(int n)
    { //Constructor function. Initializes the variables.
        total_size=n;
        fe=-1;
        be=n;
        arr=new int[n];
    }


    void Push(int n,char ch)
    { //Used to insert an element from a particular stack
        //Here n is the integer that we want to Push and ch is the stack in which we want to push. f->first stack, any other char->2nd stack
        int temp;
        if(fe==be-1) //Here stack will be full
        {
            cout<<"Element can't be inserted as stack is already full"<<endl;
            return;
        }
        else
        {
            if(ch=='f')
            {
                ++fe;
                arr[fe]=n;
            }
            else
            {
                --be;
                //cout<<"top is "<<this->top<<endl;
                arr[be]=n;
            }
            cout<<"Element inserted successfully"<<endl;
        }
    }


    void pop(char ch)
    { //Used to remove an element from a particular stack
        int temp;
        if(ch=='f')
        {
            if(fe==-1)
            cout<<"Element can't be popped as Stack 1 already empty"<<endl;
            else
            {
                // if element in first stack then we need to decrease value of fe in pop as one element is removed;
            temp=arr[fe];
            cout<<"Element removed is "<<temp<<endl;
            --fe;
            }
        }
        else
         {
            if(be==total_size)
            cout<<"Element can't be popped as Stack 2 already empty"<<endl;
            else
            {
                // if element in second stack then we need to increase value of be in pop as one element is removed;
            temp=arr[be];
            cout<<"Element removed is "<<temp<<endl;
            ++be;
            }
        }
    }

    void Print(char ch)
    { //used to print elements of a particular stack in bottom up order
        int temp;
        if(ch=='f')
        {
        if(fe==-1)
            cout<<"Empty stack 1"<<endl;
        else
        {
        for(int i=0;i<=fe;i++)
            {
                temp=arr[i];
                cout<<temp<<" ";
            }
            cout<<endl;
        }
        }

        else
        {
                if(be==total_size)
                    cout<<"Empty stack 2"<<endl;
                else
                {
                    for(int i=total_size-1;i>=be;i--)
                    {
                        temp=arr[i];
                        cout<<temp<<" ";
                    }
                    cout<<endl;
                }
        }
    }

};

int main()
{
    Stack *s=new Stack(10);//Created object of class
        //Now just testing bunch of operations.
        s->Push(5,'f');
        s->Print('f');
        s->Print('b');
        s->Push(7,'b');
        s->Print('f');
        s->Print('b');
        s->Push(6,'f');
        s->Print('f');
        s->Print('b');
        s->Push(3,'b');
        s->Print('f');
        s->Print('b');
        s->Push(2,'b');
        s->Print('f');
        s->Print('b');
        cout<<"Popping starts here"<<endl;
        s->pop('f');
        s->Print('f');
        s->Print('b');
        s->pop('b');
        s->Print('f');
        s->Print('b');

return 0;
}
