#include "monty.h"
/**
 * rotl - cahnge the stack to the end
 * @head: list
 * @n: number
 * Return: number elements.
 */
void rotl(stack_t **head, unsigned int n)
{
	int i = 0;
	int tmpn = 0;
	stack_t *fast_iter = *head;
	stack_t *new_tail = malloc(sizeof(stack_t));
	/*stack_t *tmp2 = NULL;*/
	(void)(n);

	if (new_tail == NULL)
	{
		free(new_tail);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*head != NULL)
	{
		if (i == 0)
		{
			tmpn = (*head)->n;
			pop(head, n);
			i++;
		}
	}
	new_tail->n = tmpn;
	new_tail->next = NULL;
	if (*head == NULL)
	{
		new_tail->prev = NULL;
		*head = new_tail;
	}
	while (fast_iter->next != NULL)
	{
		fast_iter = fast_iter->next;
	}
	fast_iter->next = new_tail;
	new_tail->prev = fast_iter;

}
