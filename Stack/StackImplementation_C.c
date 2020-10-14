// Implementation of Stack Functions Using Arrays in C with static memory allocation
// A stack implemented here stores integer values and has operations like push, pop, peek etc.


#include<stdio.h>
#include<string.h>
#define MAX 25
int Stack[MAX], Top = -1, ele, i = 0;
void push();
void pop();
void peek();
void display();
int isFull();
int isEmpty();

int main(){

    int opt;
    printf("STACK OPERATIONS: 1. PUSH   2. POP   3. PEEK  4.DISPLAY  5.EXIT");
        do{
            //printf("\nEnter your choice: ");
            scanf("%d",&opt);
            switch(opt)
            {
                case(1):
                {
                    push();
                    break;
                }
                case(2):
                {
                    pop();
                    break;
                }
                case(3):
                {
                    peek();
                    break;
                }
                case(4):
                {
                    display();
                    break;
                }
                case(5):
                {
                    printf("\nExit Operation");
                    break;
                }
                default: printf("Please enter a valid choice (1/2/3/4/5) !");
            }    
        }while(opt != 5);
    return 0;    
}

void push(){
    int flag1 = isFull(); 
    if (flag1 == 1){
        printf("\nStack Overflow | Top = %d", Top);
    }
    else{
        //printf("Enter value to be pushed: ");
        scanf("%d ",&ele);
        Top++;
        Stack[Top]=ele;
    }
}

void pop(){
    int flag2 = isEmpty();
    if(flag2 == 1){
        printf("\nStack Underflow, Top = %d", Top);
    }
    else{
        ele = Stack[Top];
    Top--;
    printf("\nThe Popped element is %d",ele);
    }
}

void peek(){
    printf("\nThe top data element of stack = %d",Stack[Top]);
}

int isEmpty(){
    if(Top == -1){
        return 1;
    }
    
}

int isFull(){
    if(Top == (MAX - 1)){
        return 1;
    }
    else
        return 0;
}

void display(){
    if(Top>=0){
        printf("\nThe elements in Stack are: ");
        for(int i = 0; i<=Top;i++)
        printf("%d ", Stack[i]);
    }
    else
        printf("\nStack is empty !");
}
