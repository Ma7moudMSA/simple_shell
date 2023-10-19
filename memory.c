#include "shell.h"

/**
* _memset - fill mem
* @ptr: pointer to memory
* @byte: byte to fill
* @amount: amount to be filled
*
* Return: pointer to memory area
*/

char *_memset(char *ptr, char byte, unsigned int amount)
{
	unsigned int index;

	for (index = 0; index < amount; index++)
		ptr[index] = byte;
	return (ptr);
}

/**
* ffree - fn name
* @strofstr: string of strings to be freed
*/

void ffree(char **strofstr)
{
	char **text = strofstr;

	if (!strofstr)
		return;
	while (*strofstr)
		free(*strofstr++);
	free(text);
}

/**
* bfree - fn name
* @p: bs ba2a
*
* Return: we malo
*/

int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
