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
 * free_stack - free memory.
 * @stack: head.
 * @line: one line of the buffer.
 * @file: file.
 */
void free_stack(stack_t **stack, char *line, FILE *file)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}

	free(line);
	fclose(file);
}
/**
 * dlistint_len - length of a doubly linked list dlistin_t
 * @h: head of the doubly linked list
 * Return: number of elements of the doubly linked list
 */
size_t dlistint_len(stack_t *h)
{
	stack_t *current = h;
	int lg = 0;

	if (h == NULL)
		return (lg);
	while (current)
	{
		lg++;
		current = current->next;
	}
	return (lg);
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

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		global_var.gnum = "3rr0r";
		return;
	}
	aux = saux->n;
	saux = saux->next;
	free(saux->prev);
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
