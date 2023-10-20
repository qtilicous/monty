#include "monty.h"
#include <stdio.h>

/**
 * push - Implementation of push opcode
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 */
void push_instruction(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_valid_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(arg);
	stack_t *new_node = create_stack_node(value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

