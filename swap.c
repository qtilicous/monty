#include "monty.h"
#include <stdio.h>

/**
 * swap - Implementation of swap opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;

	first->next = second->next;

	if (second->next)
	{
		second->next->prev = first;
	}
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

