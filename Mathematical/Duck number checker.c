// Programme to check for duck number
#include <stdio.h>

int main()
{
	int a;
	
	printf("enter the number to check");
	scanf("%d", &a);
	if(a == 0)
	{
		printf("Yes the number is duck number.");
		return 0;
	}
	
	while(a > 1)
	{
		if(a % 10 == 0)
		{
			printf("Yes the number is duck number.");
			return 0;
		}
		a /= 10;
	}
	
	printf("NO it is not duck number.");
	return 0;
}