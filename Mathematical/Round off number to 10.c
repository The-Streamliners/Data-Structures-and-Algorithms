#include <stdio.h>

int main ()
{
	int number, remainder;
	
	printf ("Enter a number: ");
	scanf ("%d", &number);
	
	remainder = number % 10;
	
	if (remainder <= 5)
		number -= remainder;
	else
		number += 10 - remainder;
	
	printf ("The round off number is %d", number);
	
	return 0;
}