#include "shell.h"

/**
 * hsh - main shell command
 * @info: shell information
 * @av: the argument vector from main
 *
 * Return: 0 on success and -1 on failure
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interact(info))
			_puts("$");
		_errorputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interact(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history_file(info);
	free_info(info, 1);
	if (!interact(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err == -1)
			exit(info->status);
		exit(info->err);
	}
	return (builtin_ret);
}

/**
 * find_builtin - find
 * @info: the information
 *
 * Return: 0 on success, -1 on failure
 */
int find_builtin(info_t *info)
{
	int I, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myex},
		{"env", _myenv},
		{"help", _help},
		{"history", _myhist},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycurrentdir},
		{"alias", _myalias},
		{NULL, NULL}};
	for (I = 0; builtintbl[I].type; I++)
		if (_strcmp(info->argv[0], builtintbl[I].type) == 0)
		{
			info->count_line++;
			built_in_ret = builtintbl[I].func(info);
			break;
		}
	return (built_in_ret);
}
