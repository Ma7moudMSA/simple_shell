#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the input string
 * @d: the delimeter string
 *
 *
 * Return: a pointer to an array of strings or NULL
 */
char **strtow(char *d, char *str)
{
	int i, j, k, m, n = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!isdelim(str[i], d) && (isdelim(str[i + 1], d) || !str[i + 1]))
			n++;

	if (n == 0)
		return (NULL);
	s = malloc((1 + n) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
		while (isdelim(str[i], d))
			i++;
		k = 0;
		while (!isdelim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words.
 * @str: the input string
 * @d: the delimeter string
 *
 *
 * Return: a pointer to an array of strings or NULL
 */
char **strtow2(char *d, char *str)
{
	int i, j, k, m, n = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if (!isdelim(str[i], d) && (isdelim(str[i + 1], d) || !str[i + 1]))
			n++;

	if (n == 0)
		return (NULL);
	s = malloc((1 + n) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
		while (isdelim(str[i], d))
			i++;
		k = 0;
		while (!isdelim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
	}
	s[j] = NULL;
	return (s);
}
