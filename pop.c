#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: address of stack.
 * @line_number: Number of the line.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	next = *stack->next;
	*stack->next = NULL;
	free(*stack);
	*stack = next;
}
