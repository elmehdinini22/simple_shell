#include "shell.h"

/**
 * pfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int pfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
