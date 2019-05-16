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

	if (new_head == NULL)
	{
		free(new_head);
		return;
	}
	new_head->n = n;
	new_head->next = *head;
	new_head->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new_head;
	}
	*head = new_head;
}
