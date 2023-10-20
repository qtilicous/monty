#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

instruction_t push_instruction;
instruction_t pall_instruction;
int process_line(stack_t **stack, char *line);
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
 * @line: The line of Monty bytecode to process.
 * @stack: A pointer to the stack.
 *
 * Return: 0 on success, -1 on failure.
 */
int process_line(stack_t **stack, char *line)
{
	const char *opcode = strtok(line, " \t\n");

	instruction_t *instruction;

	if (opcode != NULL)
	{
		instruction = get_instruction(opcode);

		if (instruction != NULL)
		{
			int error_occurred = 0;

			instruction->f(stack, get_line_number(line));

			if (error_occurred != 0)
			{
				fprintf(stderr, "An error occurred while executing the instruction '%s'\n", opcode);
			}

			return (error_occurred);
		}
		else
		{
			fprintf(stderr, "Error: Unknown instruction '%s'\n", opcode);
		}
	}

	return (0);
}

