#include <stdio.h>
#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a doubly linked list
 * @head: pointer to the head
 * @n: data to store in new node
 * Return: pointer to the first node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
    stack_t *new_node;
    
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        return (NULL);

    /* Just to be sure */
    if (*head == NULL)
    {
        new_node->n = n;
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;
        return (*head);
    }
    /* Connect them */
    (*head)->prev = new_node;
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    return (*head);
}

/**
 * delete_dnodeint - deleter a node a given location
 * @head: pointer to the head
 * @pos: position of node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint(stack_t **head, unsigned int pos)
{
    stack_t *tmp, *tmp2;
    unsigned int i;

    /* If theres nothing to delete return -1 */
    if (*head == NULL)
        return (-1);
    
    tmp = *head;

    /* If first node, make next one new head and delete it */
    if (pos == 0)
    {
        *head = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = NULL;
        free(tmp);
        return (1);
    }
    for (i = 0; i < pos - 1; i++)
    {
        if (tmp == NULL)
            return (-1);
        tmp = tmp->next;
    }
    /** 
     * now tmp points to the (pos - 1)th node 
     * make posth node prev -> posth node next as next
     * make posth node next -> posth node prev as prev
     */
    tmp2 = tmp->next->next;
    if (tmp->next->next = NULL)
        tmp->next->next->prev = tmp;
    
    free(tmp->next);            /* remove posth node */
    tmp->next = tmp2;           /* finish linking */

    return (0);
}