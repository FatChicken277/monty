#include "monty.h"
char *_strtok(char *line);

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
		if (strcmp(line, "\n") != 0)
			_strtok(line);
		count++;
	}

	fclose(file);
	free(line);

	return (0);
}

char *_strtok(char *line)
{
	char *token;
	int i;

	token = strtok(line, " \n\t\r\v\f\a");

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \n\t\r\v\f\a");
		for (i = 0; token[i] != '\0'; i++)
		{
			if (token[i] < '0' || token[i] > '9')
			{
				printf("error\n");
				return ("p");
			}
		}
		printf("%d\n", atoi(token));
	}
	return ("p");
}