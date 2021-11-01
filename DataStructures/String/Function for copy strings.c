// Programme to copy two strings

#include <stdio.h>

void strcopy (char* a, char* b)
{
	while (*b++ = *a++);
}

void main ()
{
	char string1[25], string2[25];
	
	printf ("Enter a string: ");
	scanf ("%s", string1);
	
	strcopy (string2, string1);
	
	printf ("Second string is %s.");
}
