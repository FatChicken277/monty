#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: top of the stack
 * @count: number of the line where the opcode is
 */
void _pchar(stack_t **stack, unsigned int count)
{
	int aux;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		gnum = "3rr0r";
		return;
	}
	aux = (*stack)->n;
	if (aux < 0 || aux > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			count);
		gnum = "3rr0r";
		return;
	}
	printf("%c\n", aux);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @stack: top of the stack
 * @count: number of the line where the opcode is
 */
void _pstr(stack_t **stack, unsigned int count __attribute__((unused)))
{
	int aux;
	stack_t *saux = *stack;

	if (!(*stack))
	{
		printf("\n");
		return;
	}
	while (saux)
	{
		aux = saux->n;
		if (aux == 0 || (aux < 0 || aux > 127))
			break;
		printf("%c", aux);
		saux = saux->next;
	}
	printf("\n");
}
/**
 * _rotl - rotates the stack to the top.
 * @stack: top of the stack
 * @count: number of line where the opcode is
 * Return: Nothing
 */
void _rotl(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *saux, *current;

	if (!(*stack) || (dlistint_len(*stack) == 1))
		return;

	saux = *stack;
	*stack = (*stack)->next;
	current = *stack;
	(*stack)->prev = NULL;
	saux->next = NULL;

	while (current->next != NULL)
		current = current->next;

	current->next = saux;
	saux->prev = current;
}
/**
 * _rotr - rotates the stack to the bottom.
 * @stack: top of the stack
 * @count: number of line where the opcode is
 * Return: Nothing
 */
void _rotr(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *current;

	if (!(*stack) || (dlistint_len(*stack) == 1))
		return;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
