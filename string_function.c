#include "shell.h"

/**
 * _strlen -returns the length of the string passed
 * @Copy_string:the string whose  length would be checked
 *
 * Return: intger length of the string
 */
int _strlen(const char *Copy_string)
{
	int Local_i = 0;

	if (!Copy_string)
		return (0);

	while (*Copy_string++)
	{
		Local_i++;
	}
	return (Local_i);
}

/**
 * _strcmp - performs comparisoins of two strings
 * @string1: the first string
 * @string2: the second string
 *
 * Return: negative if string1 is less than string2
 * and positive if string1 is greater
 */
int _strcmp(const char *string1, const char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
	{
		return (0);
	}
	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * starts_with -checks whether the argument starts with haystack
 * @haystack: string to search for
 * @Needle: the subdtring to find
 *
 * Return: pointer to the destination in the buffer
 */
char *starts_with(const char *haystack, const char *Needle)
{
	while (*Needle)
		if (*Needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @destination: the destination string
 * @source: the source of the buffer
 *
 * Return: pointer to the desitination buffer
 */
char *_strcat(char *destination, char *source)
{
	char *return_value = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (return_value);
}
