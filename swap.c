#include "monty.h"
#include <stdio.h>

/**
 * swap - Implementation of swap opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	/* Implementation of swap opcode */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *first = *stack;
	stack_t *second = first->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;

	*stack = second;
}

