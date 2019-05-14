#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		FILE *fptr;
		char ch;
		fptr = fopen(argv[1], "r");
		if (fptr == NULL)
		{
			printf("Cannot open file \n");
			exit(0);
		}
		ch = fgetc(fptr);
		while (ch != EOF)
		{
			printf ("%c", ch);
			ch = fgetc(fptr);
		}
		fclose(fptr);
	}
	return (0);
}
