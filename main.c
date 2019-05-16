#include "monty.h"
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
	char *delimiters = " \t\n";
	size_t buffsize = 32;
	ssize_t line_size;
	int f_idx = 0;
	int line_count = 0;
	file = fopen(argv[1], "r");
	/*(void)(head);
	  (void)(f_idx);*/
	(void)(par_number);
	/*(void)(ints);*/
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
			line_count++;
			token = strtok(buffer, delimiters);
			if (token == NULL)
			{
				free(buffer);
				continue;
			}
			while (token != NULL)
			{
				while(ints[f_idx].opcode != NULL)
                                {
					if(strcmp(ints[f_idx].opcode, token) == 0)
                                        {
						if(strcmp(token, "push") == 0)
						{
							token = strtok(NULL, delimiters);
							if(_isdigit(token) == 0)
							{
								free_dlistint(head);
								free(buffer);
								buffer = NULL;
								fclose(file);
								fprintf(stderr,"L<%d>: usage: push integer\n",line_count);
								exit(EXIT_FAILURE);
							}
							else if(_isdigit(token) == 1)
							{
								par_number = atoi(token);
							}
						}
						ints[f_idx].f(&head, par_number);
                                        }
					f_idx++;
				}
				token = strtok(NULL, delimiters);
				f_idx = 0;
			}
			line_size = getline(&buffer, &buffsize, file);
		}
		free_dlistint(head);
		free(buffer);
		buffer = NULL;
		fclose(file);
	}
	return (0);
}
