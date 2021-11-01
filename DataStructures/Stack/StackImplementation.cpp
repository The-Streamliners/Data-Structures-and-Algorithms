// Stack Implementation using Linked lists

// C++ program to implement basic Stack operations
#include <bits/stdc++.h> 
using namespace std; 
  
#define max_size 100 
  
class Stack { 
    int top; 
  
public: 
    int a[max_size]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isFull();
    bool isEmpty(); 
}; 

//push() - inserts element x onto the Stack  
bool Stack::push(int x) 
{ 
    if (top >= (max_size - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into the stack\n"; 
        return true; 
    } 
} 
  
//pop() - removes and returns element at the top of the stack
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow\n"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 

//peek() − get the top data element of the stack, without removing it.
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty\n"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 

//isFull() − checks if stack is full.
bool Stack::isFull() 
{ 
    if(top>=max_size-1)
        return true;
    else
        return false;
} 
  
//isEmpty() − checks if stack is empty.
bool Stack::isEmpty() 
{ 
    if(top<0)
        return true;
    else
        return false;
} 

int main() 
{ 
    class Stack s; 
    s.push(40); 
    s.push(50); 
    s.push(60); 
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.peek() << " Element at top of stack\n";

    if(s.isFull())
        cout<<"Stack is full\n";
    else
        cout<<"Stack is not full\n";

    if(s.isEmpty())
        cout<<"Stack is empty\n";
    else
        cout<<"Stack is not empty\n";
  
    return 0; 
} 