#include "shell.h"

/**
* cmd_builtin - cmd execution of builtin functions
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int cmd_builtin(char **command, char *line)
{
        struct builtin builtin = {"env", "exit"};

        if (_strcmp(*command, builtin.env) == 0)
        {
                print_env();
                return (1);
        }
        else if (_strcmp(*command, builtin.exit) == 0)
        {
                exit_ccmd(command, line);
                return (1);
        }
        return (0);
}
