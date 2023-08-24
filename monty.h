#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct job_s - the current job being executed
 * @flag: wether we are handling a stack or queue
 * @args: arguments
 * @command: the command to be interpreted
 * 0 is for stack, 1 is for queue
 * @FILE: the file being handled
 * @file: this is the file in use
 */
typedef struct job_s
{
	int flag;
	char *args;
	char *command;
	FILE *file;
} job_t;

extern job_t *job;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
stack_t *add_node_end(stack_t **head, const int n);
void remove_node_start(stack_t **head);
void remove_node_end(stack_t **head);
/*ssize_t print_stack(const stack_t *head);*/
int run_job(stack_t **stack);
int execute_command(stack_t **stack, size_t line);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
