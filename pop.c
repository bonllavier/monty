#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: address of stack.
 * @line_number: Number of the line.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = *stack;
	if ((*next).next != NULL)
	{
		(*(*next).next).prev = NULL;
	}
	*stack = (*next).next;
	free(next);
}
