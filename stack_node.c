#include "monty.h"
#include <stdlib.h>

/**
 * create_stack_node - Create a new node for the stack.
 * @n: The integer value to store in the node.
 *
 * Return: A pointer to the newly created stack node, or NULL on failure.
 */
stack_t *create_stack_node(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

