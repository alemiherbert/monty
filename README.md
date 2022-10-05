# Monty bytecode interpreter
Monty 0.98 is a scripting language that is first compiled into Monty bytecode. It relies on a unique stack, with specific instructions to compile it.
# Installation
The code is compiled as
```(bash)
$ gcc -wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
- All the output is printed to `stdout`
- All the error messages are printed to `stderr`
