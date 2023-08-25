#include "monty.h"

/**
 * push - push an element to the stack, starting from the top
 * @stack: the stack;
 * @line_number: the line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!job.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(job.arg);
	node->prev = NULL;
	node->next = *stack;

	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * pall - print all the values on the stack, starting from the top
 * @stack: the stack;
 * @line_number: the line number
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	for (tmp = *stack; tmp; tmp = tmp->next)
		printf("%d\n", tmp->n);
}
