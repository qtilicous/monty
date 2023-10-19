#include "monty.h"
#include <stdio.h>

/**
 * nop - Implementation of nop opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Implementation of nop opcode */
	(void)stack;  /* Unused parameter */
	(void)line_number;  /* Unused parameter */
	/* No operation, do nothing */
}

