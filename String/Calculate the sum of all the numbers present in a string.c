// Programme to get the sum of all the digits present in a string

#include <stdio.h>

int main()
{
	int sum = 0, i = 0;
	char string[50];
	
	printf("Please enter a string : ");
	scanf("%s", string);
	
	while(string[i++])
	{
		if (string[i] >= 48 && string[i] <= 57)
		{
			sum += string[i] - 48;
		}
	}
	printf("The sum of all the digits present in the string is %d", sum);
	return 0;
}