#include "monty.h"
/**
 * pstr - print like a string
 * @head: list
 * @n: number
 */
void pstr(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if ((tmp->n) >= 0 && (tmp->n) <= 127)
	{
		while (tmp != NULL)
		{
			if ((tmp->n) >= 33 && (tmp->n) <= 126)
			{
				printf("%c", tmp->n);
				tmp = tmp->next;
			}
			else
			{
				if (tmp->n == 0)
					break;
				tmp = tmp->next;
			}
		}
	printf("\n");
	}
	else
	{
		fprintf(stderr, "L%d: can't pstro, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
}
