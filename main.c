#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Monty bytecode interpreter entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	FILE *file;
	char *command = NULL;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	command = (char *)malloc(256);
	if (command == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(command, 256, file) != NULL)
	{
		opcode = strtok(command, " \t\n");
		if (opcode != NULL && strcmp(opcode, "#") != 0)
		{
			execute(opcode, &stack, &line_number);
		}
		line_number++;
	}
	fclose(file);
	if (command != NULL)
	{
		free(command);
	}
	return (0);
}
