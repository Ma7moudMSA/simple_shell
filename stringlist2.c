#include "shell.h"

/**
* list_length - fn name
* @head: we malo
*
* Return: law mesh -1
*/

size_t list_length(const l_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++
	}
	return (i);
}

/**
* list_string - fn name
* @head: we malo
*
* Return: law mesh -1
*/

char **list_string(l_t *head)
{
	l_t *node = head;
	size_t i = list_length(head);
	size_t j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free[strs];
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
* p_list - fn name
* @head: we malo
*
* Return: law mesh -1
*/

size_t p_list(const l_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(conv_num(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
* node_starts_with - fn name
* @node: we malo
* @prefix: bs ba2a ya gam
* @c: we malo
*
* Return: law mesh -1
*/


l_t *node_starts_with(l_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


/**
* get_node_i - fn name
* @head: bs ba2a ya gam
* @node: we malo
*
* Return: law mesh -1
*/

ssize_t get_node_i(l_t *head, l_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++
	}
	return (-1);
}
