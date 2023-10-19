#include "monty.h"
#include <stdio.h>

/**
 * add - Implementation of add opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	/* Implementation of add opcode */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

