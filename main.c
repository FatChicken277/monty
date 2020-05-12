#include "monty.h"

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int file;
	char bf[1024];
	char *line = NULL;
	size_t len = 0;
    ssize_t readd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	read(file, bf, 1024);

	while ((readd = getline(&line, &len, bf)) != -1)
	{
        printf("Retrieved line of length %zu:\n", readd);
        printf("%s", line);
    }

	return (0);
}
