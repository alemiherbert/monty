#include "monty.h"
#include <stdio.h>

/**
 * _push - pushes an element into a stack
 * @stack:
 * @line_number: the number to push
 * Return:
 */
void _push(stack_t **stack, unsigned int line_number)
{
    char *cmd;      /* string to contain commands */
    char *args;     /* string to contain tokens */
    stack_t *tmp;
    tmp = stack;

    if (!tmp)
    {
        // print error message
        // quit program
    }

    strtok(NULL, "\n ");
}