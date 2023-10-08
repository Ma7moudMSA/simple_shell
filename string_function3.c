#include <shell.h>

/**
 * _strncpy - Copy a string
 * @destination: Destination string
 * @source: source string
 * @copy_numbers: number of characters to be copied
 *
 * Return: the concatenated string
 */
char *_strncpy(char *destination, const char *source, int copy_numbers)
{
	int I, j;
	char *s = destination;

	I = 0;
	while (source[I] != '\0' && I < copy_numbers - 1)
		destination[I] = source[I++];
	if (copy_numbers > I)
	{
		j = I;
		while (j < copy_numbers)
			destination[j++] = '\0';
	}
	return (s);
}
