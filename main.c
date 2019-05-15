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
		/*char *opcode_token;*/
		char *buffer;
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

/*		if (buffer == NULL)
		{
			printf("line_size error");
			}*/
		while (line_size >= 0)
		{
			printf("%s", buffer);
			line_size = getline(&buffer, &buffsize, file);
		}
		free(buffer);
		fclose(file);
	}
	return (0);
}
