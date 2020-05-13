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
void _push(stack_t **stack, unsigned int count)
{
	stack_t *new;
	int i, n;

	if (!gnum)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%s\n", gnum);
	for (i = 0; gnum[i] != '\0'; i++)
	{
		if (gnum[i] < '0' || gnum[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(gnum);

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
}

void _pop(stack_t **stack, unsigned int count)
{
	stack_t *del;
	int data;

	if ((*stack) == NULL)
	{
		printf("It is NULL\n");
		return;
	}
	del = (*stack);
	data = del->n;
	(*stack) = (*stack)->next;
	/*free memory*/
	free(del);
	printf("value %d deleted\n", data);
	printf("count %d\n", count);
	if ((*stack))
		(*stack)->prev = NULL;
}
