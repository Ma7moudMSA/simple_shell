#include <shell.h>

/**
 * _strncpy - Copy a string,  version of the strncpy function.
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
		destination[I] = source[I++];/* enters a loop that continues*/
									/*until it has copied copy_numbers - 1*/
	if (copy_numbers > I)
	{ /*enters another loop that fills the rest of the destination string */
		/*with null characters up to copy_numbers*/
		j = I;
		while (j < copy_numbers)
			destination[j++] = '\0';
	}
	return (s);
}

/**
 * _strncat - concetenates two string
 * @destination: destination string
 * @source: source string
 * @copy_numbers: number of characters to be copied
 *
 * Return: the concatenated string
*/
char *_strncat(char *destination, char *source, int *copy_numbers)
{
		int I, j;
	char *s = destination;

	I = j = 0;
	while (destination[I++] != '\0')
	{}

	if (j < copy_numbers)
	{
		destination[I++] = source[j++];
	}
	if (j < copy_numbers)
		destination[I] = '\0';
	return (s);
}

/**
 * _strchr - locates a character in a string
 * @source: the source
 * @c: the character to
 *
 * Return: (s) a pointer to the memoery area s
*/
char *_strchr(char *source, char c)
{
	do {
		if (*source == c)
		return (source);
	} while (*source != '\0');

	return (NULL);
}
