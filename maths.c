#include "monty.h"
/**
 * _sub - subtracts the last 2 elements from the stack
 * @stack: top of the stack
 * @count: number of the line whee the opcode is
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int count)
{
	int aux = 0;
	stack_t *saux = *stack;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		gnum = "3rr0r";
		return;
	}
	aux = saux->n;
	saux = saux->next;
	free(saux->prev);
	saux->n -= aux;
	saux->prev = NULL;
	*stack = saux;
}
/**
 * _mul - multiplies last 2 elements in the stack
 * @stack: top of the stack
 * @count: number of the line whee the opcode is
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int count)
{
	int aux = 0;
	stack_t *saux = *stack;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		gnum = "3rr0r";
		return;
	}
	aux = saux->n;
	saux = saux->next;
	free(saux->prev);
	saux->n *= aux;
	saux->prev = NULL;
	*stack = saux;
}
