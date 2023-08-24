#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    if (!job->args)
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    add_node_end(stack, atoi(job->args));
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    if (!tmp)
        return;
    
    (void) line_number;

    while (tmp->next)
        tmp = tmp->next;
    
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->prev;
    } 
}
