#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Implementation of pint opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* Implementation of pint opcode */

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

