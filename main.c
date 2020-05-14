#include "monty.h"
char *gnum;

/**
 * main - read and run monty files.
 * @argv: arguments.
 * @argc: number of arguments.
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1], *line = NULL;
	unsigned int count = 1;
	FILE *file;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &len, file)) != -1)
	{
		_strtok(line, count, &stack, file);
		count++;
	}
	free_stack(&stack, line, file);

	return (0);
}
/**
 * check_error - check if is error.
 * @stack: head.
 * @file: file.
 * @line: one line of buffer.
 */
void check_error(stack_t **stack, char *line, FILE *file)
{
	if (strcmp(gnum, "3rr0r") == 0)
	{
		free_stack(&(*stack), line, file);
		exit(EXIT_FAILURE);
	}
}

/**
 * _strtok - delete all unnecessary stuff.
 * @stack: head.
 * @count: line_number.
 * @file: file.
 * @line: one line of buffer.
 */
void _strtok(char *line, unsigned int count, stack_t **stack, FILE *file)
{
	int i = 0;
	char *token = NULL;
	instruction_t finder[] = {{"push", _push}, {"pop", _pop},
				  {"pint", _pint}, {"pall", _pall}, {"swap", _swap}, {"add", _add},
				  {"nop", _nop}, {"sub", _sub}, {"mul", _mul}, {"div", _div},
				  {"mod", _mod}, {"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr}};

	token = strtok(line, " \n\t\r\v\f\a");
	gnum = "";
	if (token)
	{
		if (token[0] == '#')
			return;
		if (strcmp(token, finder[0].opcode) == 0)
		{
			token = strtok(NULL, " \n\t\r\v\f\a");
			gnum = token;
			finder[0].f(&(*stack), count);
			check_error(&(*stack), line, file);
			return;
		}
		for (i = 1; i < 15; i++)
		{
			if (strcmp(token, finder[i].opcode) == 0)
			{
				finder[i].f(&(*stack), count);
				check_error(&(*stack), line, file);
				return;
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
		free_stack(&(*stack), line, file);
		exit(EXIT_FAILURE);
	}
}

