#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		FILE *file;
		char *token;
		char *buffer;
		char *delimiters = " \t\r\n\v\f";
		size_t buffsize = 32;
		ssize_t line_size;
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Cannot open file \n");
			exit(0);
		}
		buffer = (char *)malloc(buffsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		line_size = getline(&buffer, &buffsize, file);

		while (line_size >= 0)
		{
			printf("%s", buffer);
			token = strtok(buffer, delimiters);
			if (token == NULL)
			{
				free(buffer);
				continue;
			}
			while (token != NULL)
			{
				token = strtok(buffer, delimiters);
			}
			line_size = getline(&buffer, &buffsize, file);
		}
		free(buffer);
		fclose(file);
	}
	return (0);
}
