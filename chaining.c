#include "shell.h"

/**
 * ischaining - fn name
 * @info: args
 * @buffer: feno
 * @p: we malop
 *
 * Return: always zero
 */

int ischaining(info_t *info, char *buffer, size_t *p)
{
	size_t i = *p;

	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = 0;
		i++;
		info->type_cmd_buf = 1;
	}
	else if (buffer[i] == '&' && buffer[i + 1 == '&'])
	{
		buffer[i] = 0;
		i++;
		info->type_cmd_buf = 2;
	}
	else if (buffer[i] == ';')
	{
		buffer[i] = 0;
		info->type_cmd_buf = 3;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * checkforchain - fn name
 * @info: args
 * @buffer: feno
 * @ptr: we malop
 * @i: we malo ua hsdv
 * @l: hcewd it psrdf
 *
 * Return: always zero
 */


void checkforchain(info_t *info, char *buffer, size_t *ptr, size_t i, size_t l)
{
	size_t k = *ptr;

	if (info->type_cmd_buf == 2)
	{
		if (info->status)
		{
			buffer[i] = 0;
			k = l;
		}
	}
	if (info->type_cmd_buf == 1)
	{
		if (!!info->status)
		{
			buffer[i] = 0;
			k = l;
		}
	}
	*ptr = k;
}

/**
 * replaceAlias - fn name
 * @info: args
 *
 * Return: always zero
 */

int replaceAlias(info_t *info)
{
	int i;
	l_t *node;
	char *ptr;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (ptr)
			return (0);
		info->argv[0] = ptr;
	}
	return (1);
}

/**
 * replacing_vars - fn name
 * @info: args
 *
 * Return: always zero
 */

int replacing_vars(info_t *info)
{
	int i = 0;
	l_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			replacingStrings(&(info->argv[i]),
				_strdup(conv_num(info->status, 10, 0)));
				continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replacingStrings(&(info->argv[i]),
				_strdup(conv_num(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replacingStrings(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replacingStrings(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * replacingStrings - fn name
 * @o: args
 * @n: chek it
 *
 * Return: always zero
 */

void replacingStrings(char **o, char *n)
{
	free(*o);
	*o = n;
}
