#include <stdio.h>
#include <stdlib.h>
// File opening logic
int main()
{
   char ch, file_name[25];
   FILE *fp;

   printf("Enter file name\n");
   gets(file_name);

   fp = fopen(file_name, "r");

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   while ((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
   return 0;
}
