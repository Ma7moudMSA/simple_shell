#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: struct containing information about arguments
 *
 * Return: always zero
 */
int _myenv(info_t *info)
{
	print_list_str(info);
	return (0);
}

/**
 * _getenv - gets the current environment
 * @info: struct containing information about arguments
 * @name: name of the environment
 *
 * Return: the value of the environment variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		ndoe = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - initialize the environment
 * @info: structure containing information aboutargument
 *
 * Return: zero or one
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - remove unset environment variable
 * @info: structure containing information aboutargument
 *
 * Return: zero or one
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}

/**
 * populate_env_list - populate the environment linked list
 * @info: structure containing information aboutargument
 *
 * Return: zero
 */
int populate_env(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
