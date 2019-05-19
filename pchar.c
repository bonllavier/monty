#include "monty.h"
/**
 * pchar - print list
 * @head: list
 * @n: number
 */
void pchar(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if ((tmp->n) >= 0 && (tmp->n) <= 127)
	{
		printf("%c\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
}
