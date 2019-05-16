#include "monty.h"
/**
 * pall - print list
 * @head: list
 * @n: number
 * Return: number elements.
 */
void pall(stack_t **head, unsigned int n)
{
	int i = 0;
	stack_t *tmp = *head;
	(void)(n);

	if (tmp == NULL)
	{
		return;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		i++;
	}
}
