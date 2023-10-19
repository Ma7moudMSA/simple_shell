#include "shell.h"

/**
 * _strcpy -This function comes in handy when you need a duplicate of a string
 * that you can tweak without changing the original.
 *  Just remember to release the memory set aside for the new string
 * once you’re finished with it to prevent memory leaks.
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to distination
 */
char *_strcpy(char *destination, char *source)
{
	int Local_i = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[Local_i])
	{
		destination[Local_i] = source[Local_i];
		Local_i++;
	}
	destination[Local_i] = 0;
	return (destination);
}

/**
 * _strdup - duplicate string
 * @string: the string to duplicate
 *
 * Return: pointer to the string
*/
char *_strdup(const char *string)
{
	int Local_length = 0;
	char *Return_value;

	if (string == NULL)
		return (NULL);
	while (*string++)
		Local_length++;
	Return_value = malloc(sizeof(char) * (Local_length + 1));
	if (!Return_value)
		return (NULL);
	for (Local_length++; Local_length--;)
		Return_value[Local_length] = *--string;
	return (Return_value);
}

/**
* _puts - print all string with newline
* @str: input
*
* Return: number of bytes
*/

void _puts(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print *
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	static int p;
	static char buf[1024];

	if (c == -1 || p >= 1024)
	{
		write(1, buf, p);
		p = 0;
	}
	if (c != -1)
		buf[p++] = c;
	return (1);
}
