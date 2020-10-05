// Program to perform simple calculator(algebric) functions  using **Switch case**

#include<stdio.h>
int main()
{
	float a,b,c;
	int x;
	printf("Enter two numbers = ");
	scanf("%f%f",&a,&b);
	printf("\n1.ADDITION\n2.SUBTRACTION\n3.DIVISION\n4.MULTIPLICATION\nEnter your choice = ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			c=a+b;
			break;
			case 2:
				c=a-b;
				break;
				case 3:
					c=a/b;
					break;
					case 4:
						c=a*b;
						break;
						default:
							printf("invalid choice!!!");
			
	}
	printf("Result = %f",c);
	return 0;
}
