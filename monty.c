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


	

	fclose(file_ptr);
	return (0);
}
