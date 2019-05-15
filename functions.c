#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *push - print list
 *@head: list
 *@n: number
 *Return: number elements.
 */
void *push(stack_t **head, int n)
{
	stack_t *new_tail = malloc(sizeof(stack_t));
	stack_t *fast_iter = *head;

	if (new_tail == NULL)
	{
		free(new_tail);
		return (0);
	}
	new_tail->n = n;
	new_tail->next = NULL;
	if (*head == NULL)
	{
		new_tail->prev = NULL;
		*head = new_tail;
		return (*head);
	}
	while (fast_iter->next != NULL)
	{
		fast_iter = fast_iter->next;
	}
	fast_iter->next = new_tail;
	new_tail->prev = fast_iter;

}
/**
 *pall - print list
 *@h: list
 *@n: number
 *Return: number elements.
 */
void pall(const stack_t *h, int n)
{
	int i = 0;
	
	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
}