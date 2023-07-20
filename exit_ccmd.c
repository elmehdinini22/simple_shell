#include "shell.h"

/**
* exit_ccmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_ccmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
