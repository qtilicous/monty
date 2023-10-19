#include "monty.h"

/**
 * pall - Implements the pall opcode.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 *
 * Description: This function prints all values on the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

