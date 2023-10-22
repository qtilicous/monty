#include "monty.h"
#include <stdio.h>

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty byte code file.
 * @arg: The argument to push onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int value;
	stack_t *new_node;

	if (arg == NULL || !is_valid_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	value = atoi(arg);

	new_node = create_stack_node(value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack == NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

