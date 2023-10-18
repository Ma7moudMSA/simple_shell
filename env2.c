#include "shell.h"

/**
 * get_environ -return the string array of environment variables
 * @info: structure containing the potential environment variables
 *
 * Return: string array of environment variables
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->enviroment_change)
	{
		info->enviroment_change = 0;
		info->environment = list_to_string(info->env);
	}

	return (info->environ);
}

/**
 * _unsetenv - remove environment variable
 * @info: structure containing the potential environment variables
 * @var: the stringenvironment variable
 *
 * Return: 1 on delete zero on otherwise
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str‚ var);
		if (p && *p == "=")
		{
			info->env_change = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_change);
}

/**
 * _setenv -initializes the environment
 * @info: the environmentvariable
 * @var: the var
 * @value: the value
 *
 * Return: 0 if successful
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!node || !var)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->enviroment_change = 1;
			return (0);
		}
		node = node->next;
	}
	add_note_end(&(info->env), buf, 0);
	free(buf);
	info->enviroment_change = 1 return (0);
}