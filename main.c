#include "monty.h"
void _strtok(char *line, unsigned int count __attribute__((unused)), stack_t **stack);
/*void push(char *token);*/

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

void _strtok(char *line, unsigned int count __attribute__((unused)), stack_t **stack)
{
	int i = 0, num;
	char *token = NULL;
	instruction_t finder[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL}
	};

	token = strtok(line, " \n\t\r\v\f\a");
	printf("token %s\n", token);
	if (token)
	{
		if (strcmp(token, finder[0].opcode) == 0)
		{
			token = strtok(NULL, " \n\t\r\v\f\a");
			printf("%s\n", token);
			num = atoi(token);
			_push(&(*stack), num);
			return;
		}

		for (i = 1; i < 7; i++)
		{
			if (strcmp(token, finder[i].opcode) == 0)
			{
				/*finder[i].f(*stack, cont);*/
				return;
			}
		}
		/*Imprimir error en caso de que no se encuentre el opcode*/
	}
}
