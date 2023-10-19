#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <linux/kernel.h>

int process_line(char *line, stack_t **stack);
void free_resources(FILE *file, char *line, stack_t *stack);

/**
 * process_line - Process a line of Monty bytecode.
 * @line: The line of Monty bytecode to process.
 * @stack: A pointer to the stack.
 *
 * Return: 0 on success, -1 on failure.
 */
int process_line(char *line, stack_t **stack)
{
	const char *opcode;
	char *argument;

	instruction_t *instruction = get_instruction(opcode);

	opcode = strtok(line, " \t\n");
	argument = strtok(NULL, " \t\n");

	if (!opcode)
		return (1);

	if (!instruction)
		return (0);

	if (argument)
		instruction->f(stack, get_line_number(line), atoi(argument));
	else
		instruction->f(stack, get_line_number(line));

	return (1);
}

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
	free_stack(stack);
}

/**
 * get_instruction - Get the instruction function for the given opcode.
 * @opcode: The opcode to search for.
 * Return: NULL
 */
instruction_t *get_instruction(char *opcode)
{
	if (strcmp(opcode, "push") == 0)
	{
		return (&push_function);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		return (&pall_function);
	}
	else
	{
		return (NULL);
	}
}

/**
 * get_line_number - get the line number
 * @line: the line to get number
 * Return: 0
 */
unsigned int get_line_number(char *line)
{
	unsigned int line_number;

	if (kstrtouint(line, 10, &line_number) == 0)
	{
		return (line_number);
	}
	else if
	{
		return (0);
	}
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
