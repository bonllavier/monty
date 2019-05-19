#include "monty.h"
/**
 * pstr - print like a string
 * @head: list
 * @n: number
 */
void pstr(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;
	(void)(n);

	while (tmp != NULL)
	{
		if ((tmp->n) >= 0 && (tmp->n) <= 127)
		{
			if ((tmp->n) > 0 && (tmp->n) <= 127)
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
		else
		{
			break;
		}
	}
	printf("\n");
}
