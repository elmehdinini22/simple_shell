#include "shell.h"

/**
* free_function - frees buffers
* @buf: buffer to be freed
*
* Return: no return
*/
void free_function(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
