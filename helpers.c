#include <stdio.h>
#include "monty.h"

int is_num(char *str)
{
    unsigned int i;
    if (!str)
    {
        return (0);
    }
    i = 0;
    while (*(str + i))
    {
        if (*(str) == '-')
        {
            i++;
            continue;
        }
    }
}