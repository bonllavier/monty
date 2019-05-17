#include "monty.h"

/**
 * swap - swap elements
 * @stack: address of stack.
 * @line_number: Number of the line.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num1;
	int num2;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	(*stack)->n = num2;
	(*stack)->next->n = num1;
}
