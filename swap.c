#include "monty.h"

/**
 * swap - swap elements
 * @stack: address of stack.
 * @line_number: Number of the line.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int x;
	size_t l;

	l = 3;
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (l == 2)
	{
		tmp = (*stack)->next;
		tmp->next = *stack;
		tmp->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
		*stack = tmp;
	}
	else
	{
		tmp = *stack;
		for (x = 0; x < 2; x++)
			tmp = tmp->next;
		(tmp->prev)->prev = NULL;
		(tmp->prev)->next = *stack;
		(*stack)->prev = tmp->prev;
		(*stack)->next = tmp;
		tmp->prev = *stack;
		*stack = (*stack)->prev;
	}
}
