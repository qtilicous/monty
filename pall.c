#include "monty.h"
#include <stdio.h>

/**
 * pall - Implementation of pall opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	/* Implementation of pall opcode */
	(void)line_number;  /* Unused parameter */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

