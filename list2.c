#include "monty.h"

/**
 * _push - adds a new node in the stack.
 * @stack: top of the stack.
 * @count: line_number.
 */
void _push(stack_t **stack, unsigned int count)
{
	stack_t *new;
	int i, n;

	if (!gnum)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		gnum = "3rr0r";
		return;
	}
	printf("%s\n", gnum);
	for (i = 0; gnum[i] != '\0'; i++)
	{
		if (gnum[i] < '0' || gnum[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			gnum = "3rr0r";
			return;
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

/**
 * _pall - prints all the values on the stack.
 * @stack: head.
 * @count: line_number.
 */
void _pall(stack_t **stack, unsigned int count __attribute__((unused)))
{
	size_t i = 0;
	stack_t *aux = *stack;

	for (i = 0; aux != NULL; i++)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 * @stack: head.
 * @count: line_number.
 */
void _pint(stack_t **stack, unsigned int count)
{
	if ((*stack))
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		gnum = "3rr0r";
		return;
	}
}

/**
 * _pop - removes the top element of the stack.
 * @stack: head.
 * @count: line_number.
 */
void _pop(stack_t **stack, unsigned int count)
{
	stack_t *del;
	int data;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		gnum = "3rr0r";
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

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: head.
 * @count: line_number.
 */
void _swap(stack_t **stack, unsigned int count)
{
	int aux = 0;
	stack_t *saux = *stack;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		gnum = "3rr0r";
		return;
	}
	aux = saux->n;
	saux->n = saux->next->n;
	saux->next->n = aux;
	*stack = saux;
}
