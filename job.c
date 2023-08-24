#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}};

int run_job(stack_t **stack)
{
    size_t len, line;
    ssize_t nread;

    line = 1;
    while (true)
    {
        nread = getline(&(job->command), &len, job->file);
        if (nread == EOF)
            return (0);

        execute_command(stack, line);

        line++;
    }
}

int execute_command(stack_t **stack, size_t line)
{
    char *cmd;
    size_t i;

    cmd = strtok(job->command, " \n\t");
    if (cmd && cmd[0] == '#')
        return 0;

    job->args = strtok(NULL, " \t\n");

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(cmd, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line);
            return (0);
        }
    }

    fprintf(stderr, "L%lu: unknown instruction %s\n", line, cmd);
    return (1);
}
