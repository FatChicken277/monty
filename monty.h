#ifndef _HOLBERTON_
#define _HOLBERTON_

/** ====Libraries==== **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/** ====Structures==== **/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** ====Prototypes==== **/

stack_t *create_node(int n);
void _push(stack_t **stack, unsigned int count);
void _pop(stack_t **stack, unsigned int count);
void _pint(stack_t **stack, unsigned int count);
void _pall(stack_t **stack, unsigned int count);
void _nop(stack_t **stack, unsigned int count);
void _swap(stack_t **stack, unsigned int count);
void _add(stack_t **stack, unsigned int count);
size_t dlistint_len(stack_t **h);
void _strtok(char *line, unsigned int count, stack_t **stack);

/** ====Global==== **/
char *gnum;

#endif
