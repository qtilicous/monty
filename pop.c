#include "monty.h"
#include <stdio.h>

/**
 * pop - Implementation of pop opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
        *stack = (*stack)->next;
	/* Implementation of pop opcode */
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

