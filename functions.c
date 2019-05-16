#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *push - print list
 *@head: list
 *@n: number
 *Return: number elements.
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
	return;

}
void _posh(stack_t **head, unsigned int n)
{
        stack_t *new_tail = malloc(sizeof(stack_t));
        stack_t *fast_iter = *head;

        if (new_tail == NULL)
        {
                free(new_tail);
                return;
        }
        new_tail->n = n;
        new_tail->next = NULL;
        if (*head == NULL)
        {
                new_tail->prev = NULL;
                *head = new_tail;
                return;
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
