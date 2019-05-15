#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	stack_t *head;
        unsigned int par_number;
	instruction_t ints[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
	};
	FILE *file;
	char *token;
	char *buffer;
	char *delimiters = " \t\r\n\v\f";
	size_t buffsize = 32;
	ssize_t line_size;
	int f_idx = 0;
	file = fopen(argv[1], "r");

	if(argc > 1)
	{
		head = NULL;
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
			token = strtok(buffer, delimiters);
			if (token == NULL)
			{
				free(buffer);
				continue;
			}
			while (token != NULL)
			{
				for(f_idx = 0 ; ints[f_idx].opcode != NULL ; f_idx++)
                                {
					/*printf(" |opcode: (%s)| ", ints[f_idx].opcode);*/
                                        if(strcmp(ints[f_idx].opcode, token) == 0)
                                        {
						if(strcmp(token, "push") == 0)
							par_number = atoi(strtok(NULL, delimiters));
                                                /*printf("found: (%s) in: (%d)|", ints[f_idx].opcode, par_number);*/
						ints[f_idx].f(&head, par_number);
                                        }
					/*else if(strcmp("pil", token) == 0)
					{
						ints[f_idx].f(&head, par_number);
						}*/
					/*printf(" |opcode: (%s)| ", ints[f_idx].opcode);*/
				}
				token = strtok(NULL, delimiters);
			}
			line_size = getline(&buffer, &buffsize, file);
		}
		free(buffer);
		fclose(file);
	}
	return (0);
}
