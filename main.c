#include "monty.h"
void _strtok(char *line);
void push(char *token);

int main(int argc, char *argv[])
{
	char *filename = argv[1], *line = NULL;
	int count = 1;
	FILE *file;
	size_t len = 0;

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
		_strtok(line);
		count++;
	}

	fclose(file);
	free(line);

	return (0);
}

void _strtok(char *line)
{
	char *token = NULL;

	token = strtok(line, " \n\t\r\v\f\a");

	if (token)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t\r\v\f\a");
			push(token);
		}
	}
}

void push(char *token)
{
	int i;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] < '0' || token[i] > '9')
		{
			printf("error\n");
			return;
		}
	}
	printf("%d\n", atoi(token));
}
