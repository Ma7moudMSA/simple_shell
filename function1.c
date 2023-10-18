#include "shell.h"

/**
* interact - fn to return true if in interactive mode
* @inf: adress of stuct
*
* Return: 1 if int 0 if not
*/

int interact(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}


/**
* isdelim - fn for delimiter
* @char: delimited char
* @del: string
*
* Return: true and false
*/

int isdelim(char chara, char *del)
{
	while (*del)
		if (*del++ == chara)
			return (1);
	return (0);
}


/**
* _isalpha - fn to check digits or char
* @char: input
*
* Return: either true or false
*/

int _isalpha(int chara)
{
	if ((chara >= 'a' && chara <= 'z') || (chara >= 'A' && chara <= 'Z'))
		return (1);
	else
		return (0);
}


/**
* _erroratoi - fn name
* @s: converted string
*
* Return: if no num 0 else num and -1 in error
*/

int _erroratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
* p_error - print error message
* @information: parameter
* @error_string: error type
*
* Return: 0 no num -1 if error
*/

void p_error(info_t *information, char *error_string)
{
	_puts(information->fname);
	_puts(": ");
	_puts(information->count_line, STDERR_FILENO);
	_puts(": ");
	_puts(information->argv[0]);
	_puts(": ");
	_puts(error_string);
}
