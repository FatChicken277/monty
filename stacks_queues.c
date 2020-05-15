#include "monty.h"

void _stack(stack_t **stack, unsigned int count __attribute__((unused)))
{
	(void)stack;

	global_var.flag = 1;
}

void _queue(stack_t **stack, unsigned int count __attribute__((unused)))
{
        (void)stack;

        global_var.flag = 0;
}
