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
		void (*fun_ptr_arr[]) (va_list) = {push, pall};
		char fname[] = {'push', 'pall'};
		FILE *file;
		char *token;
		char *buffer;
		char *delimiters = " \t\r\n\v\f";
		size_t buffsize = 32;
		ssize_t line_size;
		int f_idx = 0;
		stack_t *head;
		head = NULL;
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
			/*token = strtok(buffer, delimiters);*/
			if (token == NULL)
			{
				free(buffer);
				continue;
			}
			while (token != NULL)
			{
				token = strtok(buffer, delimiters);
				for(f_idx = 0 ; f_idx < 2 ; f_idx++)
				{
					if(fname[f_idx] == token)
					{
						token = strtok(buffer, delimiters);
						(*fun_ptr_arr[f_idx])(&head, atoi(token));
						/*push(&head, atoi(token));*/
					}
				}
			}
			line_size = getline(&buffer, &buffsize, file);
		}
		free(buffer);
		fclose(file);
	}
	return (0);
}
