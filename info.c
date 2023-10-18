#include "shell.h"

/**
 * clear_info - clear all information
 * @info: the information pointer to clear
 *
 * Return: void
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - set  information
 * @info: the information pointer to set
 * @av: argument vector
 * Return: void
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->arg)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replaceAlias(info);
		replacing_vars(info);
	}
}

/**
 * free_info - free all infor pointer
 * @info: the information pointer to clear
 * @all: check it out
 *
 * Return: void
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->ptr_buf_cmd)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->his)
			free_list(&(info->his));
		if (info->alias)
			free_list(&(info->alias));
		if (!info->his)
			free_list(&(info->his));
		ffree(info->environ);
		info->environ = NULL;
		ffree((char **)info->ptr_buf_cmd);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
