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
