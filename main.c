#include "monty.h"
/*void push(char *token);*/

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
		_strtok(line, count, &stack);
		count++;
	}

	fclose(file);
	free(line);

	return (0);
}

/**
 * _strtok - delete all unnecessary stuff.
 * @stack: head.
 * @count: line_number.
 * @line: one line of buffer.
 */
void _strtok(char *line, unsigned int count, stack_t **stack)
{
	int i = 0;
	char *token = NULL;
	instruction_t finder[] = {
		{"push", _push},
		{"pop", _pop},
		{"pint", _pint},
		{"pall", _pall},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}};

	token = strtok(line, " \n\t\r\v\f\a");
	printf("token %s\n", token);
	if (token)
	{
		if (strcmp(token, finder[0].opcode) == 0)
		{
			token = strtok(NULL, " \n\t\r\v\f\a");
			gnum = token;
			finder[0].f(&(*stack), count);
			return;
		}

		for (i = 1; i < 7; i++)
		{
			if (strcmp(token, finder[i].opcode) == 0)
			{
				finder[i].f(&(*stack), count);
				return;
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
		exit(EXIT_FAILURE);
	}
}
