#include "monty.h"
#include <stdio.h>

/**
 * push - Implementation of push opcode
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
	/* Implementation of push opcode */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

