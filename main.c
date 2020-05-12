#include "monty.h"

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int num_line = 0;

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
	while (getline(&line, &len, file) != -1)
	{
		printf("%d, %s", num_line++, line);
	}
	fflush(stdout);
	fclose(file);
	free(line);

	return (0);
}
