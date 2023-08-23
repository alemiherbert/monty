#include "monty.h"

/**
 * main - a simple byte code interpreter
 * @ac: argument count
 * @av: argument vector
 * Return: 0 for success and other for faliure
 */
int main(int ac, char **av)
{
	FILE *file_ptr;
	char *line = NULL;
	size_t line_num = 1, len = 0;
	ssize_t nread;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_ptr = fopen(av[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	instruction_t instructions[] = {
		{"push", NULL},
		{NULL, NULL}
	};

	while ((nread = getline(&line, &len, file_ptr)) != -1)
	{
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		// push 6
		// strtok 
		printf("Line %lu: %s\n", line_num, line);
		line_num++;
	}

	free(line);
	fclose(file_ptr);
	return (0);
}
