#include "monty.h"

/**
 * _push - adds a new node in the stack.
 * @stack: top of the stack.
 * @count: line_number.
 */
void _push(stack_t **stack, unsigned int count)
{
	int i;

	if (!global_var.gnum)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		global_var.gnum = "3rr0r";
		return;
	}
	for (i = 0; global_var.gnum[i] != '\0'; i++)
	{
		if (global_var.gnum[0] == '-' && i == 0)
			i++;
		if (global_var.gnum[i] < '0' || global_var.gnum[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			global_var.gnum = "3rr0r";
			return;
		}
	}
	stack_queue(&(*stack));
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
		global_var.gnum = "3rr0r";
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

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		global_var.gnum = "3rr0r";
		return;
	}
	del = (*stack);
	(*stack) = (*stack)->next;
	/*free memory*/
	free(del);
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
		global_var.gnum = "3rr0r";
		return;
	}
	aux = saux->n;
	saux->n = saux->next->n;
	saux->next->n = aux;
	*stack = saux;
}
