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
