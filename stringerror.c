#include "shell.h"

/**
* _errorputs - fn name
* @str: we malo
*
* Return: numver
*/

void _errorputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_errorputchar(str[i]);
		i++;
	}
}


/**
* _errorputchar - fn name
* @c: we malo
*
* Return: numver
*/

int _errorputchar(char c)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}

/**
* _putfd - fn name
* @c: we malo
* @fd: ua gsams
*
* Return: numver
*/

int _putfd(char c, int fd)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}

/**
* _putsfd - fn name
* @str: we malo
* @fd: ua gsams
*
* Return: numver
*/

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
