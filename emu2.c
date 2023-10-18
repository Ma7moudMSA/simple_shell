#include "shell.h"

/**
* _myhist - fn name
* @inf: arg
*
* Return: bos keda
*/

int _myhist(info_t *inf)
{
	p_list(inf->his);
	return (0);
}

/**
* unsetalias - fn namer
* @info: what you fot
* @str: common buddy
*
* Return: succues
*/

int unsetalias(info_t *info, char *str)
{
	char *ptr, cha;
	int r;

	ptr = strchr(str, '=');
	if (!ptr)
		return (1);
	cha = *ptr;
	*ptr = 0;
	r = delete_node_i(&(info->alias),
		get_node_i(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = cha;
	return (r);
}

/**
* s_alias - fn namer
* @info: what you fot
* @str: common buddy
*
* Return: succues
*/

int s_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');

	if (!p)
		return (1);
	if (!++p)
		return (unsetalias(info, str));

	unsetalias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* p_alias - fn namer
* @node: what you fot
*
* Return: succues
*/

int p_alias(l_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
* _myalias - fn namer
* @info: what you fot
*
* Return: succues
*/

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	l_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			p_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			s_alias(info, info->argv[i]);
		else
		p_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
