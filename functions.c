#include "monty.h"

/**
 * add_node_end - add a node at the top of a stack or queue
 * @head: pointer to the stack or queue
 * @n: data to store at the node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
    stack_t *node, *tmp;

    if (!head)
        return (NULL);

    node = malloc(sizeof(stack_t));
    if (!node)
        return (NULL);

    node->n;
    node->next = NULL;

    if (*head == NULL)
    {
        node->prev = NULL;
        *head = node;
        return (node);
    }

    for (tmp = *head; tmp->next; tmp = tmp->next)
        ;

    tmp->next = node;
    node->prev = tmp;
    return (node);
}

/**
 * remove_node_start - remove the node at the beginning of a
 */
void remove_node_start(stack_t **head)
{
    stack_t *node;

    node->prev = NULL;
    node->next = (*head)->next;

    free(*head);
    *head = node;
}

/**
 * remove_node_end - remove the node at the bottom of the stack
 *
 */
void remove_node_end(stack_t **head)
{
    stack_t *node;

    if (!head || *head)
        return (NULL);


    node = *head;
    if (!node->next)
    {
        free(node);
        *head = NULL;
        return;
    }

    while (node->next->next)
        node = node->next;
    free(node->next);
    node->next = NULL;
}