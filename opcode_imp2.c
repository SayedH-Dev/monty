#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Pointer to the current line number
 */
void add(stack_t **stack, unsigned int *line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", *line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * nop - Do nothing (no operation)
 * @stack: Pointer to the top of the stack (unused)
 */
void nop(stack_t **stack __attribute__((unused)))
{
}
