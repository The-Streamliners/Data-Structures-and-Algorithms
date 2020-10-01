#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int ch;                             //declaring global variables and strings
char fn[20],e,c,name[20];

fpos_t position;
FILE *fp1,*fp2,*fp;                 //declaring file pointers variable

void Modify();                      //declaration of all the functions to be used in the program
void NewFile();
void SaveAs();
void Copy();
void Delete();
void View();
void comparison();
void Edit();
void Find();
void erasetext();
void removetext(char *str, const char *word);

#define esc 27                      //declaring constants
#define buffersize 1000

int main()
{	                            //layout of display page of text editor
	while(1)
	{
		ch = 0;
		printf("\n-----------------------------------------TEXT EDITOR--------------------------------------------------");
		printf("\n\n\tMENU:\n\t\n");
		printf("\n\t 1.NEWFILE\n\t 2.VIEW\n\t 3.COPY\n\t 4.DELETE\n\t 5.COMPARISON\n\t 6.EDIT\n\t 7.SAVEAS\n\t 8.FIND\n\t 9.EXIT\n");
		printf("\n\tEnter your choice: ");

		scanf("%d",&ch);                        //user input of function choice

		if(ch < 1 || ch > 9)                   //check for valid user input
		{
			printf("\tInvalid Input\n");
			exit(0);
		}

		switch(ch)                            //switch block to select function as per user input
		{
			case 1:
			{
				NewFile();
				break;
			}
			case 2:
			{
				View();
				break;
			}
			case 3:
			{
				Copy();
				break;
			}
			case 4:
			{
				Delete();
				break;
			}
			case 5:
			{
				comparison();
				break;
			}
			case 6:
			{
				Edit();
				break;
			}
			case 7:
			{
				SaveAs();
				break;
			}
			case 8:
			{
				Find();
				break;
			}
			case 9:
			exit(0);

			default:
			{
				printf("Incorrect Input\n");
				break;
			}
		}
	}
return 0;
}

//definition of all the functions used in the program

//function definition to create new file

void NewFile()                                                                //function takes no argument and returns void
{
	printf("\n\tEnter the name of the file to be created: ");  
	getchar();
	scanf("%[^\n]", name);	               									  //prompt for user input
	fp1=fopen(name,"w");                                                      //opening new file with user input name

	printf("\n\tPress Esc and then Enter to save.\n\t");
	printf("Press Tab key and then Enter to quit without saving.\n\n");

	char temp;
	scanf("%c", &temp);

	while(1)
	{
		c=getchar();

		if(c == esc)
		{
			fclose(fp1);
			break;
		}
		else if(c == '\t')
		{
			remove(name);
			break;
		}

		fputc(c,fp1);
	}
}

//function definition to compare two files

void comparison()                                                   //function takes no argument and returns void
{
	int line = 1, col = 0;

	printf("\n\tEnter the first file: ");                            //user prompt for first file
	getchar();
	scanf("%[^\n]", name);
	fp1 = fopen(name,"r");                                       //opening first file entered by user in read only mode

	printf("\n\tEnter the second file: ");                          //user prompt for second file
	getchar();
	scanf("%[^\n]", fn);
	fp2 = fopen(fn,"r");                                        //opening second file entered by user in read only mode

    if (fp1 == NULL || fp2 == NULL)                                 //check for existence of file and if it has read privileges
    {
    	printf("\tError : Files not open\n");
       	return;
    }

	char ch1 = getc(fp1);                                        //reading the two files character wise
   	char ch2 = getc(fp2);

	while (ch1 != EOF && ch2 != EOF)                            //reading files till end of file is reached
    {
       	col++;                                                  //column or character count

       	if (ch1 == '\n' && ch2 == '\n')                         //check for end of line
		{
		    line++;                                             //increment line count on reaching ending of line
		    col = 0;                                            //column or character set to zero again
		}

        if (ch1 != ch2)                                        //for block if characters at same position are not same on the two files
        {
            printf("\tFiles not identical\n");
            printf("\tLine Number : %d \t""Position : %d \n", line, col);
            return;                                           //exiting program with proper message display
        }

        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }

    if(ch1 == EOF && ch2 == EOF)                            //end of file is reached for both files
    {
    	printf("\n\tFiles are identical\n");
	}
	else
	{
       	printf("\tFiles not identical\n");
	}

	fclose(fp1);                                           //closing both files
    fclose(fp2);
}

//function to view existing file

void View()                                                  //function takes no argument and returns void
{
	printf("\n\tEnter the file name: ");                     //user input for file name to be opened
	getchar();
	scanf("%[^\n]",fn);
	fp1=fopen(fn,"r");                                       //opening file in read only mode

	if(fp1==NULL)                                            //file pointer returns null if file doesn't exist or does not have read privileges
	{
		printf("\n\tFile not found!");
		return;
	}

	c=fgetc(fp1);                                            //reading file character wise

	while( c != EOF )                                       //characters of file are printed till end of file is reached
	{
		printf("%c",c);
		c=getc(fp1);
	}

	fclose(fp1);                                           //closing file
	return;
}

//function definition to copy contents of existing file to new file

void Copy()                                                           //function takes no argument and returns void
{
	printf("\n\tEnter the filename from which to copy: ");
	getchar();
	scanf("%[^\n]", name);                                      //user input for name of existing file

	printf("\n\tEnter the new filename:  ");
	getchar();
	scanf("%[^\n]",fn);                                         //user input for name of new file

	fp1=fopen(name,"r");                                    //opening existing file in read only mode

	if(fp1 == NULL)                                         //file pointer returns null if unable to open file
	{
		printf("\n\tFile not found!");
		return;
	}

	fp2=fopen(fn,"w");                                     //opening existing file in write only mode

	while((c=getc(fp1)) != EOF)                            //loop to write characters in new file from existing file till end of file is reached for existing file
	{
		putc(c,fp2);
	}

	printf("\n\tFile has been copied successfully");

	fclose(fp1);                                        //closing both the files
	fclose(fp2);
}

//function definition to delete existing file

void Delete()                                           //function takes no argument and returns void
{
	printf("\n\tEnter the file name: ");
	getchar();
	scanf("%[^\n]",fn);                                    //user inputs file name
	fp1=fopen(fn,"r");                                 //open the file in read only mode

	if(fp1==NULL)                                      //file pointer returns null if file does not exist
	{
		printf("\n\tFile not found!");
		return;
	}

	fclose(fp1);

	if(remove(fn)==0)                                 //remove function returns zero value if file deleted successfully
	{
		printf("\n\n\tFile has been deleted successfully!");
	}
	else                                           //remove function returns non zero value if file not deleted successfully
	{
		printf("\n\tError!\n");
	}
}

//function definition to edit file

void Edit()                                               //function takes no argument and returns void
{

	printf("\n\tEdit options available:\n");               //option to append file or delete word from file
	printf("\t1. Append to file\n");
	printf("\t2. Delete a word in the file\n");
	printf("\n\tEnter you choice: ");

	int option;

	scanf("%d", &option);                                 // taking input for option

	getchar();

	if(option < 1 || option > 2)                            //check for valid input
	{
		printf("\tInvalid Input\n");
		return;
	}

	switch(option)
	{
		case 1:                                            //switch case 1 to append file
		{
			printf("\n\tEnter the file name: ");
			scanf("%[^\n]",fn);                                //taking input of file name
	
			fp1=fopen(fn,"r+");                            //opening file in read and write mode

			if(fp1==NULL)                                  //file pointer returns null if unable to open file

			{
				printf("\n\tFile not found!");
				return;
			}	

			while((c=getc(fp1))!= EOF)                   //while loop block gets character from file and prints on screen till end of file is reached
			{
				printf("%c",c);
			}
			printf("\n\tPress Esc and then enter key to save.\n\n");

			while(1)                                        //while loop block to get character input from user and add to file
			{
				c=getchar();

				if(c == esc )                               //escape sequence to close file
				{
					fclose(fp1);
					break;
				}

				fputc(c,fp1);

			}
			return;
		}

		case 2:                                             //switch case 2 to delete word from file
		{
			erasetext();                                    //function called for specific word removal
    			return;
		}
	}
}

//function definition to rename file

void SaveAs()                                                    //function takes no argument and returns void
{
	printf("\n\tEnter the name of the file to be changed: ");
	getchar();
	scanf("%[^\n]", name);                                        //user input for name of existing file

	printf("\n\tEnter the new file name: ");
	getchar();
	scanf("%[^\n]", fn);                                          //user input for new name of file

	fp1 = fopen(name, "r");                                     //opening file in read only mode

	if(fp1==NULL)                                               //file pointer returns null if unable to open file
	{
		printf("\n\tFile not found!");
		return;
	}

	fp2=fopen(fn,"w");                                     //opening a new file in write only mode

	while((c=getc(fp1)) != EOF)                            //loop to write characters in new file from existing file till end of file is reached for existing file
	{
		putc(c,fp2);
	}

	printf("\n\tFile has been copied successfully");

	fclose(fp1);                                        //closing both the files
	fclose(fp2);
}

//function definition to search a word in file

void Find()                                                 //function takes no argument and returns void
{
	printf("\n\tEnter the file name: ");
	getchar();
	scanf("%[^\n]",fn);                                        //user input for file name
	fp1=fopen(fn,"r");                                     //opening file in read only mode

	if(fp1==NULL)                                          //file pointer returns null if unable to open file
	{
		printf("\n\tFile not found!");
		return;
	}

	char temp[100000];                                     //variable declaration to store string read from file
	int line = 1;
	int match_no = 0;
	char str[100], *ptr[100], string[100];
	long int pos;

	printf("\tEnter the phrase to search: ");             //user input to search word
	getchar();
	scanf("%[^\n]", str);

	while(fgets(temp, 100000, fp1) != NULL)               //while loop condition using fgets function
	{
		*ptr = strstr(temp, str);                         //function to find substring temp in string str

		if((strstr(temp, str)) != NULL)                  //strstr function returns a pointer if string is found or else returns null
		{
			pos = *ptr - temp;
			fseek(fp1, pos, SEEK_CUR);

			*string = printf("\033[1;31m"); printf("\t%s", str); printf("\033[0m");

			printf("%s found on line %d at position %ld in line : %s\n", string, line, pos, temp);
			match_no++;
		}
		line++;
	}
	if(match_no == 0)
	{
		printf("\tNo match found");
	}
}

//function definition to delete word from file

void erasetext()                                                   //function takes no argument and returns void
{	
    char nam[30]; char word[100]; char buffer[1000];               //declaring strings to read input from user or store strings from file
    FILE * f1; FILE * f2;                                         //declaring file pointers
    int line = 0,plus = 0;                                       // integer variables for user input and loop count

    printf("\tEnter file name: ");                               //user input for file name
    scanf("%[^\n]", nam);

    printf("\tEnter word to remove: ");                         //user input of word to remove
    getchar();
    scanf("%[^\n]", word);

    printf("\tEnter line number to edit: ");                   //user input for line number
    scanf("%d", &line);

    if(line < 1)                                              //check for valid line number
    {
        printf("\tInvalid line number\n");
        return;
    }

    f1 = fopen(nam,"r");                                      //opening file in read only mode
    f2 = fopen("new.txt", "w");                               //opening a text file in write only mode

    if(f1 == NULL || f2 == NULL)                              //file pointer returns null if unable to open file or if read write privileges do not exist for file
    {
	    printf("\tUnable to open files.\n");
        return;
    }

    plus = 0;                                               //plus is initialized to zero

    while((fgets(buffer,buffersize,f1)!= NULL))            //while condition using fgets function
    {
        plus++;                                            //incrementing plus as line number

        if(plus == line)                                   /*when plus equals specified line number removetext function is
                                                            called to remove word from the line*/
        {
            removetext(buffer,word);
            fputs(buffer,f2);
        }
        else                                               //copies text from existing file to new file
        {
            fputs(buffer,f2);
        }
    }

    fclose(f1);                                          //closing both files after editing
    fclose(f2);

    remove(nam);                                         //deleting previous file
    rename("new.txt" ,nam);                              //renaming edited file to previous file name

    printf("\tThe word \033[1;33m%s\033[0m has been removed form line %d.\n", word, line);

    return;
}

//function definition to remove word from specified line in file

void removetext(char *str, const char *word)                          //function takes two strings as argument and returns void
{
    int x,z,stringlen,trlen;                                          //local variables declaration
    int found;

    stringlen = strlen(str);                                          //length of sentence
    trlen = strlen(word);                                             //length of word

    for(x=0; x<= (stringlen-trlen); x++)                            /* for block matches each character of sentence to each character of
                                                                        word
                                                                      if words do not match found is set
                                                                       to zero and loop breaks out of the present iteration */
    {
        found = 1;

        for(z=0;z<trlen;z++)
        {
            if(str[x+z] != word[z])
            {
                found = 0;
                break;
            }
        }

        if(str[x+z]!= ' ' && str[x+z] != '\t' && str[x+z] != '\n' && str[x+z] != '\0')  //if it is not a word found is set to zero
        {
            found = 0;
        }
                                                          /*if word is found then sentence string is
                                                            decremented and shifted to the left*/
        if(found == 1)
        {
            for(z=x; z<= (stringlen - trlen); z++)
            {
                str[z] = str[z + trlen];
            }

            stringlen = stringlen - trlen;
            x--;
        }
    }
}
