#include "monty.h"

/**
 * free_stk - frees the allocated memory for the stack
 * @stack: pointer to the top of stack
 */
void free_stk(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

/**
 * is_integer - check for a valid integer
 * @str: string to be checked
 * Return: true if integer or false if not
 */
#include <stdbool.h>

bool is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
