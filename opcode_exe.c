#include "monty.h"
/**
 * execute - Execute Monty bytecode command
 * @opcode: The Monty bytecode command to execute
 * @stack: Pointer to the top of the stack
 * @line_number: Pointer to the current line number
 */
void execute(char *opcode, stack_t **stack, unsigned int *line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack);
	}
	else
	{
		invalid_opcode(opcode, line_number);
	}
}
