#include "shell.h"
/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

/**
 * print_environment - Print the environment variables.
 *
 * return: void
 */
void print_environment(void)
{
    int i;
    extern char **environ;
    char *env_var;
    int length;

    for (i = 0; environ[i] != NULL; i++)
    {
        env_var = environ[i];
        length = _strlen(env_var);
        write(1, env_var, length);
        write(1, "\n", 1);
    }
}
