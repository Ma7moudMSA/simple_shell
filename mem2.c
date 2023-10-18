#include "shell.h"

/**
* tobefree - fn name
* @pointer: this is what we want to free
*
* Return: int
*/

int tobefree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}

/**
* _realloc - fn name
* @pointer: pointer to block
* @old: old size of block
* @new: new size of block
*
* Return: void
*/

void *_realloc(void *pointer, unsigned int old, unsigned int new)
{
		char *point;

		if (!pointer)
			return (malloc(new));
		if (!new)
			return (free(pointer), NULL);
		if (new == old)
			return (pointer);
		point = malloc(new);
		if (!point)
			return (NULL);
		old = old < new ? old : new;
		while (old--)
			point[old] = ((char *)pointer)[old];
		free(pointer);
		return (point);
}
