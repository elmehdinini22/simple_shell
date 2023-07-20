#include "shell.h"

/**
* scanf_env - scanf the environment string to stdout
*
* Return: 0
*/
void scanf_env(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
