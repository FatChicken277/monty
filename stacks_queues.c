#include "monty.h"
/**
 * _stack - convert to stack mode
 * @stack: stack
 * @count: count
 */
void _stack(stack_t **stack, unsigned int count __attribute__((unused)))
{
	(void)stack;

	global_var.flag = 1;
}
/**
 * _queue - convert to queue mode
 * @stack: stack
 * @count: count
 */
void _queue(stack_t **stack, unsigned int count __attribute__((unused)))
{
	(void)stack;

	global_var.flag = 0;
}
/**
 * stack_queue - convert to stack/queue list mode
 * @stack: stack
 */
void stack_queue(stack_t **stack)
{
	stack_t *new, *last;
	int n;

	n = atoi(global_var.gnum);
	new = create_node(n);
	if (global_var.flag == 1)
	{
		if ((*stack) == NULL)
			*stack = new;
		else
		{
			new->next = *stack;
			(*stack)->prev = new;
			(*stack) = new;
		}
	}
	else
	{
		if ((*stack) == NULL)
			*stack = new;
		else
		{
			last = *stack;
			while (last->next != NULL)
				last = last->next;
			last->next = new;
			new->prev = last;
		}
	}
}
