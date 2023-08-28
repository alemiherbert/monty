#include "monty.h"

job_t job;

/**
 * main - a simple bytecode interpreter
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if success
 */
int main(int ac, char **av)
{
	size_t len = 0;
	ssize_t nread = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	job.file = fopen(av[1], "r");
	if (!job.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		nread = getline(&job.line, &len, job.file);
		if (nread == -1)
			break;
		execute_command(&stack, line_number);
		line_number++;
	}

	fclose(job.file);
	return (0);
}

/**
 * execute_command - interprete a line of code
 * @stack: the stack
 * @line_number: the line number
 */
void execute_command(stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	const char *delim = " \n\t";

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	job.opcode = strtok(job.line, delim);
	if (!job.opcode || job.opcode[0] == '#')
		return;

	job.arg = strtok(NULL, delim);

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(job.opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, job.opcode);
	exit(EXIT_FAILURE);
}
