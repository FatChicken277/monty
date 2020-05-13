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
 * dlistint_len - returns the number of elements in a linked list.
 * @h: head.
 * Return: returns the number of elements in a linked list.
 */
size_t dlistint_len(stack_t **h)
{
	size_t index = 0;

	for (index = 0; *h != NULL; index++)
	{
		*h = (*h)->next;
	}
	return (index);
}

/**
 * _add - adds the top two elements of the stack.
 * @stack: head.
 * @count: line_number.
 */
void _add(stack_t **stack, unsigned int count)
{
	int aux = 0;
	stack_t *saux = *stack;

	if (dlistint_len(&*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	aux = saux->n;
	saux = saux->next;
	saux->n += aux;
	saux->prev = NULL;
	*stack = saux;
}

/**
 * _nop - doesn’t do anything.
 * @stack: head.
 * @count: line_number.
 */
void _nop(stack_t **stack, unsigned int count)
{
	*stack = *stack;
	count = count;
}
