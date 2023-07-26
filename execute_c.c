#include "shell.h"

/**
 * check_c - Check if the command is valid and executable.
 * @readBytes: The number of bytes read from the input.
 *
 * Return:
 *  0 - If the command is empty or an error occurred while reading.
 *  1 - If the command is empty (only a newline).
 *  2 - If the command is valid and executable.
 */
int check_c(int readBytes)
{
    char command[10];

    if (readBytes < 1)
    {
        if (readBytes == 0)
            perror("Error: Empty command\n");
        else
            perror("Error in reading command\n");
        return (0);
    }
    else if (readBytes == 1 && command[0] == '\n')
    {
        return (1);
    }

    if (access(command, F_OK | X_OK) == -1)
    {
        perror("Error: executable cannot be found\n");
        return (0);
    }

    return (2);
}

/**
 * _execute - Execute the command line interpreter.
 *
 * return: void
 */
void _execute(void)
{
    ssize_t bytesRead;
    pid_t id;
    char command[10];
    int status;
    char *argv[2];
    int valid_c;
    char *envp[] = {NULL};
    char prompt[17] = "Enter a command\n";

    while (1)
    {
        write(1, prompt, sizeof(prompt) - 1);
        bytesRead = read(0, command, sizeof(command) - 1);

        valid_c = check_c(bytesRead);
        if (valid_c == 0)
            continue;
        else if (valid_c == 1)
            break;

        id = fork();
        if (id == -1)
        {
            perror("Error in creating process\n");
            continue;
        }

        if (id == 0)
        {
            command[bytesRead - 1] = '\0';
            argv[0] = command;
            argv[1] = NULL;
            execve(command, argv, envp);
            perror("Error in command execution ");
            _exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    }
}
