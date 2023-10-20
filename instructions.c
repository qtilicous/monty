#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

instruction_t push_instruction;
instruction_t pall_instruction;
void process_line(const char *filename);
void free_resources(FILE *file, char *line, stack_t *stack);

/**
 * free_resources - Free resources used in Monty interpreter.
 * @file: A pointer to the file to close.
 * @line: A pointer to the line buffer to free.
 * @stack: A pointer to the stack to free.
 */
void free_resources(FILE *file, char *line, stack_t *stack)
{
	free(line);
	fclose(file);
	free_stack(&stack);
}

/**
 * get_instruction - Get the instruction function for the given opcode.
 * @opcode: The opcode to search for.
 * Return: NULL
 */
instruction_t *get_instruction(const char *opcode)
{
	if (strcmp(opcode, "push") == 0)
	{
		return (&push_instruction);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		return (&pall_instruction);
	}

	return (NULL);
}

/**
 * get_line_number - get the line number
 * @line: the line to get number
 * Return: void
 */
int get_line_number(char *line)
{
	unsigned int line_number;

	char *endptr;

	line_number = strtoul(line, &endptr, 10);

	if (*endptr != '\0')
	{
		return (line_number);
	}

	return (-1);
}

/**
 * free_stack - get the stack
 * @stack: the stack to get
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}

	*stack = NULL;
}

/**
 * process_line - Process a line of Monty bytecode.
 * @filename: the file name
 */
void process_line(const char *filename)
{
	stack_t *new_stack = NULL;

	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
	}

	free_stack(&new_stack);

	fclose(file);
}

