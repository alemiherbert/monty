#include "monty.h"

stack_t *stack;

int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	add_node_end(&stack, 12);
	add_node_end(&stack, 29);
	add_node_end(&stack, 33);
	add_node_end(&stack, 41);
	print_stack(stack);
	

	close(fd);
	return (0);
}