#include "monty.h"
/**
 * push - print list
 * @head: list
 * @n: number
 * Return: number elements.
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new_head = malloc(sizeof(stack_t));
	(void)(n);
	if (new_head == NULL)
	{
		free(new_head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_head->n = par_number;
	new_head->next = *head;
	new_head->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new_head;
	}
	*head = new_head;
}
