#include "monty.h"
int par_number = 0;
/**
 * main - Entry point
 *@argc: argument counter
 *@argv: argumnt vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	stack_t *head;
	FILE *file;
	char *token;
	char *buffer;
	size_t buffsize = 1024;
	ssize_t line_size;
	unsigned int line_count = 0;

	if (argc == 1 || argc > 2)
	{ fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	else if (argc == 2)
	{ token = NULL;
		head = NULL;
		file = fopen(argv[1], "r");
		if (file == NULL)
		{ fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			/*fclose(file);*/
			exit(EXIT_FAILURE);
		}
		buffer = (char *)malloc(buffsize * sizeof(char));
		if (buffer == NULL)
		{ fprintf(stderr, "Error: malloc failed\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		line_size = getline(&buffer, &buffsize, file);

		while (line_size >= 0)
		{ line_count++;
			_strtok(buffer, line_count, token, &head, file);
			line_size = getline(&buffer, &buffsize, file);
		}
		free_dlistint(head);
		free(buffer);
		buffer = NULL;
		fclose(file);
	}
	return (0);
}

/**
 *final_liberation - final liberation
 *@head: list
 *@buffer: buffer
 *@file: file to be open
 *Return: number elements.
 */
void final_liberation(stack_t **head, char *buffer, FILE *file)
{
	free_dlistint(*head);
	free(buffer);
	buffer = NULL;
	fclose(file);
}
