//Program to check a number is even or odd
#include<stdio.h>

void main()
{   
    int a;
     
    printf("Enter a number\n");
    scanf("%d", &a);
    
    if(a%2 == 0)
    	printf("The number is an even number", a);
    
    else
        printf("The number is an odd number", a);
}