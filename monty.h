#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
 * struct job_s - global variable that stores information about the job
 * currently being executed
 * @file: file being interpreted
 * @line: the line of code to be interpreted
 * @opcode: opcode to be executed
 * @arg: the argument to the opcode
*/
typedef struct job_s
{
	FILE *file;
	char *line;
	char *opcode;
	char *arg;
} job_t;

extern job_t job;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void execute_command(stack_t **stack, unsigned int line_number);
#endif
