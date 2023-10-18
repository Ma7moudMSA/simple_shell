#include "shell.h"

/**
 * _atoi - fn to change string to integer
 * @b: the string to enter
 *
 * Return: the string if found
 */

int _atoi(char *b)
{
	int i, s = 1, f = 0, o;
	unsigned int r = 0;

	for (i = 0; b[i] != '\0' && f != 2; i++)
	{
		if (b[i] == '-')
			s *= -1;
		if (b[i] >= '0' && b[i] <= '9')
		{
			f = 1;
			r *= 10;
			r += (b[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		o = -r;
	else
		o = r;

	return (o);
}

/**
 * rmv_comments - fn to remove comment
 * @buf: the string adress
 *
 * Return: always 0
 */

void rmv_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

/**
 * conv_num - fn name for itoa
 * @num: the number to be converted
 * @base: the base
 * @flags: if there are any
 *
 * Return: the value adress
 */

char *conv_num(long int num, int base, int flags)
{
	static char *arr;
	static char buf[256];
	char s = 0;
	char *ptr;
	unsigned long numb = num;

	if (!(flags & 1) && num < 0)
	{
		numb = -num;
		s = '-';
	}

	arr = flags & 2 ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[255];
	*ptr = '\0';

	do {
		*--ptr = arr[numb % base];
		numb /= base;
	} while (numb != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
 * print_decimal - fn name
 * @value: the input
 * @file: the file descripotr to write
 *
 * Return: number of cahr
 */

int print_decimal(int value, int file)
{
	int (*__putchar)(char)  = _putchar;

	int i, count = 0;

	unsigned int absl, c;

	if (file == STDERR_FILENO)
		__putchar = _errorputchar;
	if (value < 0)
	{
		absl = -value;
		__putchar('-');
		count++;
	}
	else
		absl = value;
	c = absl;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absl / i)
		{
			__putchar('0' + c / i);
			count++;
		}
		c %= i;
	}

	__putchar('0' + c);
	count++;

	return (count);
}
