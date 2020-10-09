//program to check odd and even for a given number:
#include<stdio.h>
void main()
{ 
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    num==0?printf("Neighter odd nor even"):(num%2==0?printf("this number is even"):printf("this number is odd"));
}