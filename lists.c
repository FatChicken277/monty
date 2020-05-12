#include "monty.h"

/**
 * create_node - create a new node.
 * @n: node value.
 * Return: new node.
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/**
 * _push - adds a new node in the stack
 * @stack: top of the stack
 * @n: data for the new node
 * Return: address of new node
 */
stack_t *_push(stack_t **stack, int n)
{
	stack_t *new;

	new = create_node(n);
	if ((*stack) == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		(*stack) = new;
	}
	printf("value %d in the stack\n", (*stack)->n);
	return (*stack);
}
