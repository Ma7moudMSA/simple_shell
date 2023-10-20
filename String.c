#include "main.h"

/**
* String_U32_PutChar - writes a character to stdout
* @c: The character to print
* Return: ome on a success while negative one on error,
* and error is set appropriately.
*/
int String_U32_PutChar(char c)
{
return (write(1, &c, 1));
}

/**
* String_PU8_StrConcat - Concatenates two string
* @Copy_PU8_String1: need is first string
* @Copy_PU8_String2: second string needed
* Return: return pointer to concatenated path
*/
char *String_PU8_StrConcat(char *Copy_PU8_String1, char *Copy_PU8_String2)
{
	int Local_counter = 0, Local_counter2 = 0,
	Local_U32_Length1, Local_U32_Length2;
	char *Local_PU8_String3 = NULL;

	if (Copy_PU8_String1 == NULL || Copy_PU8_String2 == NULL)
		return (NULL);
	for (Local_U32_Length1 = 0; Copy_PU8_String1[Local_U32_Length1]
		!= '\0'; Local_U32_Length1++)
		;
	for (Local_U32_Length2 = 0; Copy_PU8_String2[Local_U32_Length2]
		!= '\0'; Local_U32_Length2++)
		;
	Local_PU8_String3 = malloc(Local_U32_Length1 + Local_U32_Length2 + 2);
	if (Local_PU8_String3 == NULL)
		return (NULL);
	for (Local_counter = 0; Copy_PU8_String1[Local_counter]
		!= '\0'; Local_counter++)
		Local_PU8_String3[Local_counter] = Copy_PU8_String1[Local_counter];
	if (Copy_PU8_String1[Local_counter - 1] != '/')
	{
		Local_PU8_String3[Local_counter] = '/';
		Local_counter++;
	}
	for (Local_counter2 = 0; Copy_PU8_String2[Local_counter2]
		!= '\0'; Local_counter2++)
		Local_PU8_String3[Local_counter + Local_counter2]
			= Copy_PU8_String2[Local_counter2];
	Local_PU8_String3[Local_counter + Local_counter2] = '\0';
	return (Local_PU8_String3);
}

/**
 * String_U32_StrSplit - split command  line
 * @Copy_PU8_Line: inputed command
 * @Copy_PPU8_Command: command argument
 * Return: Length of the line
 */
int String_U32_StrSplit(char *Copy_PU8_Line, char **Copy_PPU8_Command)
{
	int Local_counter = 0;

	Copy_PPU8_Command[0] = strtok(Copy_PU8_Line, "\n\t\r ");
	for (Local_counter = 1; Copy_PPU8_Command[Local_counter - 1]
		!= NULL; Local_counter++)
		Copy_PPU8_Command[Local_counter] = strtok(NULL, "\n\t\r ");
	Copy_PPU8_Command[Local_counter - 1] = NULL;
	return (Local_counter - 1);
}

/**
 * String_PU8_StrDup - string duplicate
 * @Copy_PU8_String: Inputed String
 * Return: Pointer to the duplicate, or 0 otherwise
 */
char *String_PU8_StrDup(char *Copy_PU8_String)
{
	int Local_counter = 0;
	char *Local_PU8_Dup;

	for (Local_counter = 0; Copy_PU8_String[Local_counter];
		Local_counter++)
		;
	Local_PU8_Dup = (char *)malloc(Local_counter + 1);
	if (Local_PU8_Dup == NULL)
		return (NULL);
	for (Local_counter = 0; Copy_PU8_String[Local_counter];
			Local_counter++)
		Local_PU8_Dup[Local_counter] = Copy_PU8_String[Local_counter];
	Local_PU8_Dup[Local_counter] = '\0';
	return (Local_PU8_Dup);
}

/**
 * String_PU8_StrCmp - compares two strings
 * @Copy_PU8_String1: first string.
 * @Copy_PU8_String2: second string.
 *
 * Return: 0 if s1 and s2 are equals, -1 otherwise
 */
int String_PU8_StrCmp(char *Copy_PU8_String1, char *Copy_PU8_String2)
{

	int Local_counter = 0, x = 0;

	for (Local_counter = 0; Copy_PU8_String1[Local_counter] != 0 ||
		Copy_PU8_String2[Local_counter] != 0; Local_counter++)
	{
		if (x == 5)
			x++;
		if (Copy_PU8_String1[Local_counter] != Copy_PU8_String2
			[Local_counter])
			break;
	}
	if (Copy_PU8_String1[Local_counter] == '\0' &&
		Copy_PU8_String2[Local_counter] == '\0')
		return (0);
	return (-1);
}
