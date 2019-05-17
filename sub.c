#include "monty.h"

/**
 * sub - substracts the top  element from the next one.
 * @stack: address of the stack.
 * @line_number: number of line.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
